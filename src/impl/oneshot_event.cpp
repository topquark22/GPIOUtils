#include "oneshot_event.h"

OneShotEvent::OneShotEvent(uint32_t pulse_ms, bool retrigger)
: OneShotEvent(pulse_ms, 0, retrigger)
{
}

OneShotEvent::OneShotEvent(uint32_t pulse_ms, uint32_t delay_ms, bool retrigger)
: pulse_ms_(pulse_ms),
  delay_ms_(delay_ms),
  retrigger_(retrigger),
  state_(IDLE),
  start_ms_(0)
{
}

void OneShotEvent::begin() {
  // symmetry only
}

void OneShotEvent::trigger() {
  const uint32_t now = millis();
  if (state_ == IDLE || retrigger_) {
    start_ms_ = now;
    state_ = (delay_ms_ > 0) ? DELAYING : ACTIVE;
  }
}

bool OneShotEvent::read() {
  const uint32_t now = millis();

  if (state_ == DELAYING && (now - start_ms_) >= delay_ms_) {
    state_ = ACTIVE;
    start_ms_ = now;
  }

  if (state_ == ACTIVE && (now - start_ms_) >= pulse_ms_) {
    state_ = IDLE;
  }

  return state_ == ACTIVE;
}

void OneShotEvent::reset() {
  state_ = IDLE;
}

bool OneShotEvent::is_active() const {
  return state_ == ACTIVE;
}

bool OneShotEvent::is_pending() const {
  return state_ == DELAYING;
}

uint32_t OneShotEvent::pulse_ms() const {
  return pulse_ms_;
}

void OneShotEvent::set_pulse_ms(uint32_t ms) {
  pulse_ms_ = ms;
}