#include "debounce.h"

Debounce::Debounce(uint8_t pin, uint8_t mode, uint32_t debounce_ms)
: pin_(pin),
  mode_(mode),
  debounce_ms_(debounce_ms),
  stable_(false),
  raw_(false),
  last_raw_(false),
  last_change_ms_(0),
  changed_(false),
  rose_(false),
  fell_(false)
{
}

Debounce::Debounce(uint8_t pin, uint32_t debounce_ms)
: Debounce(pin, INPUT_PULLUP, debounce_ms)
{
}

void Debounce::begin() {
  pinMode(pin_, mode_);
  const bool r = (digitalRead(pin_) != LOW);
  stable_ = raw_ = last_raw_ = r;
  last_change_ms_ = millis();
}

bool Debounce::read() {
  changed_ = rose_ = fell_ = false;

  const bool r = (digitalRead(pin_) != LOW);
  raw_ = r;

  const uint32_t now = millis();

  // Raw changed? restart stability timer
  if (raw_ != last_raw_) {
    last_raw_ = raw_;
    last_change_ms_ = now;
    return stable_;
  }

  // Raw stable long enough? accept if different from current stable
  if ((now - last_change_ms_) >= debounce_ms_ && stable_ != raw_) {
    const bool prev = stable_;
    stable_ = raw_;

    changed_ = true;
    rose_ = (!prev && stable_);
    fell_ = (prev && !stable_);
  }

  return stable_;
}
