#include "debounce.h"

Debounce::Debounce(uint8_t pin, uint8_t mode, uint32_t debounce_ms, bool initial_state)
: pin_(pin),
  debounce_ms_(debounce_ms),
  stable_(initial_state),
  raw_(initial_state),
  last_raw_(initial_state),
  last_change_ms_(0),
  changed_(false),
  rose_(false),
  fell_(false)
{
  pinMode(pin_, mode);

  // If caller left initial_state at default 'true', that may be wrong for their wiring.
  // So: initialize from the actual pin reading if they didn't explicitly set it.
  // We detect "not explicitly set" by reading once and overriding stable_/raw_ regardless.
  // If you *do* want to force initial_state, pass it explicitly and remove the override.
  const bool r = (digitalRead(pin_) != LOW);
  stable_ = raw_ = last_raw_ = r;
  last_change_ms_ = millis();
}

Debounce::Debounce(uint8_t pin, uint32_t debounce_ms)
: Debounce(pin, INPUT, debounce_ms, true)
{
}

bool Debounce::read() {
  changed_ = rose_ = fell_ = false;

  const bool r = (digitalRead(pin_) != LOW);
  raw_ = r;

  const uint32_t now = millis();

  // If raw input differs from what we were tracking, restart the stability timer.
  if (raw_ != last_raw_) {
    last_raw_ = raw_;
    last_change_ms_ = now;
    return stable_;
  }

  // Raw has remained unchanged; if it's been stable long enough, accept it.
  if ((now - last_change_ms_) >= debounce_ms_ && stable_ != raw_) {
    const bool prev = stable_;
    stable_ = raw_;

    changed_ = true;
    rose_ = (!prev && stable_);
    fell_ = (prev && !stable_);
  }

  return stable_;
}
