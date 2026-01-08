#include "oneshot_event.h"

OneShotEvent::OneShotEvent(uint32_t pulse_ms, bool retrigger)
: pulse_ms_(pulse_ms),
  retrigger_(retrigger),
  active_(false),
  start_ms_(0)
{
}

void OneShotEvent::begin() {
  // symmetry only
}

void OneShotEvent::trigger() {
  const uint32_t now = millis();
  if (!active_ || retrigger_) {
    active_ = true;
    start_ms_ = now;
  }
}

bool OneShotEvent::read() {
  if (active_ && (millis() - start_ms_) >= pulse_ms_) {
    active_ = false;
  }
  return active_;
}

void OneShotEvent::reset() {
  active_ = false;
}

bool OneShotEvent::is_active() const {
  return active_;
}

uint32_t OneShotEvent::pulse_ms() const {
  return pulse_ms_;
}

void OneShotEvent::set_pulse_ms(uint32_t ms) {
  pulse_ms_ = ms;
}
