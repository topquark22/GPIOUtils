#include "autorepeat.h"

namespace {
  inline bool time_reached(uint32_t now, uint32_t target) {
    return (int32_t)(now - target) >= 0;
  }
} // namespace


AutoRepeat::AutoRepeat(uint32_t initial_delay_ms, uint32_t repeat_ms)
: initial_delay_ms_(initial_delay_ms),
  repeat_ms_(repeat_ms == 0 ? 1 : repeat_ms) // avoid lockup if 0
{
  reset();
}

void AutoRepeat::reset() {
  pressed_ = false;
  fired_ = false;
  next_fire_ms_ = 0;
}

void AutoRepeat::update(bool pressed) {
  uint32_t now = millis();
  fired_ = false;

  // Edge: released -> pressed
  if (pressed && !pressed_) {
    pressed_ = true;
    next_fire_ms_ = now + initial_delay_ms_;
    return;
  }

  // Edge: pressed -> released
  if (!pressed && pressed_) {
    reset();
    return;
  }

  if (!pressed_) return;

  if (time_reached(now, next_fire_ms_)) {
    fired_ = true;
    // Schedule next repeat. Use += to preserve cadence.
    next_fire_ms_ += repeat_ms_;
    // If loop was stalled for a long time, catch up just enough to avoid bursty repeats.
    if (time_reached(now, next_fire_ms_ + repeat_ms_)) {
      next_fire_ms_ = now + repeat_ms_;
    }
  }
}