#include "pulsegenerator.h"

namespace {
  inline bool time_reached(uint32_t now, uint32_t target) {
    return (int32_t)(now - target) >= 0;
  }
} // namespace


PulseGenerator::PulseGenerator(uint32_t on_ms, uint32_t off_ms, bool start_high)
: on_ms_(on_ms == 0 ? 1 : on_ms),
  off_ms_(off_ms == 0 ? 1 : off_ms)
{
  start(start_high);
}

void PulseGenerator::set_periods(uint32_t on_ms, uint32_t off_ms) {
  on_ms_ = (on_ms == 0 ? 1 : on_ms);
  off_ms_ = (off_ms == 0 ? 1 : off_ms);
  // Recompute next toggle relative to now to avoid long stale periods.
  uint32_t now = millis();
  next_toggle_ms_ = now + (state_ ? on_ms_ : off_ms_);
}

void PulseGenerator::start(bool start_high) {
  running_ = true;
  state_ = start_high;
  uint32_t now = millis();
  next_toggle_ms_ = now + (state_ ? on_ms_ : off_ms_);
  changed_ = rose_ = fell_ = false;
}

void PulseGenerator::stop(bool output_low) {
  running_ = false;
  bool new_state = output_low ? false : state_;
  changed_ = (new_state != state_);
  rose_ = (!state_ && new_state);
  fell_ = (state_ && !new_state);
  state_ = new_state;
}

void PulseGenerator::update() {
  changed_ = rose_ = fell_ = false;
  if (!running_) return;

  uint32_t now = millis();
  if (time_reached(now, next_toggle_ms_)) {
    bool prev = state_;
    state_ = !state_;

    changed_ = true;
    rose_ = (!prev && state_);
    fell_ = (prev && !state_);

    // Cadence-preserving schedule.
    next_toggle_ms_ += (state_ ? on_ms_ : off_ms_);
    // If loop was stalled, avoid rapid catch-up toggles.
    if (time_reached(now, next_toggle_ms_ + (state_ ? on_ms_ : off_ms_))) {
      next_toggle_ms_ = now + (state_ ? on_ms_ : off_ms_);
    }
  }
}