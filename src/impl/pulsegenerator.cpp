#include "pulsegenerator.h"

namespace
{
  // millis()-wrap-safe: true when now has reached/passed target.
  inline bool time_reached(uint32_t now, uint32_t target)
  {
    return (int32_t)(now - target) >= 0;
  }
} // namespace

PulseGenerator::PulseGenerator(uint32_t on_ms, uint32_t off_ms, bool start_high)
    : on_ms_(on_ms == 0 ? 1 : on_ms),
      off_ms_(off_ms == 0 ? 1 : off_ms)
{
  // Do NOT auto-start. Stay idle until start() or trigger().
  running_ = false;
  state_ = start_high;
  num_cycles_ = 0;

  // Initialize timing to something sane even while idle.
  next_toggle_ms_ = millis();

  changed_ = rose_ = fell_ = false;
}

void PulseGenerator::set_periods(uint32_t on_ms, uint32_t off_ms)
{
  on_ms_ = (on_ms == 0 ? 1 : on_ms);
  off_ms_ = (off_ms == 0 ? 1 : off_ms);

  // Recompute next toggle relative to now to avoid stale long waits.
  uint32_t now = millis();
  next_toggle_ms_ = now + (state_ ? on_ms_ : off_ms_);
}

void PulseGenerator::start(bool start_high)
{
  running_ = true;
  state_ = start_high;
  num_cycles_ = -1; // infinite

  uint32_t now = millis();
  next_toggle_ms_ = now + (state_ ? on_ms_ : off_ms_);

  changed_ = rose_ = fell_ = false;
}

void PulseGenerator::trigger(int num_cycles)
{
  // Explicit semantic: trigger(0) == stop()
  if (num_cycles == 0)
  {
    stop();
    return;
  }

  // Restart immediately, even if already running.
  running_ = true;

  // Deterministic restart phase: start ON/high.
  // If you want "restart low then first toggle goes high", change this to false.
  state_ = true;

  num_cycles_ = num_cycles; // -1 allowed for infinite

  uint32_t now = millis();
  next_toggle_ms_ = now + on_ms_;

  changed_ = rose_ = fell_ = false;
}

void PulseGenerator::stop(bool output_low)
{
  running_ = false;

  bool new_state = output_low ? false : state_;

  changed_ = (new_state != state_);
  rose_ = (!state_ && new_state);
  fell_ = (state_ && !new_state);

  state_ = new_state;
}

void PulseGenerator::update()
{
  changed_ = rose_ = fell_ = false;

  if (!running_)
    return;

  // Completed requested cycles?
  if (num_cycles_ == 0)
  {
    running_ = false;
    return;
  }

  uint32_t now = millis();
  if (!time_reached(now, next_toggle_ms_))
    return;

  bool prev = state_;
  state_ = !state_;

  // Count full cycles on the OFF edge.
  if (state_ == false && num_cycles_ > 0)
  {
    num_cycles_--;
  }

  changed_ = true;
  rose_ = (!prev && state_);
  fell_ = (prev && !state_);

  // Cadence-preserving schedule: advance from previous deadline,
  // rather than anchoring to "now" every time.
  next_toggle_ms_ += (state_ ? on_ms_ : off_ms_);

  // If loop was stalled a long time, avoid rapid catch-up toggles.
  uint32_t next_period = (state_ ? on_ms_ : off_ms_);
  if (time_reached(now, next_toggle_ms_ + next_period))
  {
    next_toggle_ms_ = now + next_period;
  }
}
