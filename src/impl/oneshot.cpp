#include "oneshot.h"

OneShot::OneShot(uint8_t pin,
                 uint8_t mode,
                 Edge edge,
                 uint32_t pulse_ms,
                 bool retrigger)
: pin_(pin),
  mode_(mode),
  edge_(edge),
  pulse_ms_(pulse_ms),
  retrigger_(retrigger),
  last_input_(false),
  active_(false),
  start_ms_(0)
{
}

void OneShot::begin() {
  pinMode(pin_, mode_);
  last_input_ = (digitalRead(pin_) != LOW);
}

bool OneShot::read() {
  const uint32_t now = millis();
  const bool input = (digitalRead(pin_) != LOW);

  // Edge detection
  const bool rising  = (!last_input_ && input);
  const bool falling = (last_input_ && !input);
  last_input_ = input;

  const bool triggered =
    (edge_ == Edge::Rising  && rising) ||
    (edge_ == Edge::Falling && falling);

  if (triggered) {
    if (!active_ || retrigger_) {
      active_ = true;
      start_ms_ = now;
    }
  }

  if (active_ && (now - start_ms_) >= pulse_ms_) {
    active_ = false;
  }

  return active_;
}
