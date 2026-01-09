#include "multipress.h"

MultiPress::MultiPress(uint8_t pin,
                       uint8_t mode,
                       uint32_t debounce_ms,
                       uint32_t final_gap_ms,
                       uint32_t sequence_timeout_ms)
: btn_(pin, debounce_ms),
  final_gap_ms_(final_gap_ms),
  seq_timeout_ms_(sequence_timeout_ms),
  in_progress_count_(0),
  t_first_ms_(0),
  t_last_press_ms_(0),
  pending_count_(0),
  started_(false)
{
}

void MultiPress::reset() {
  in_progress_count_ = 0;
  t_first_ms_ = 0;
  t_last_press_ms_ = 0;
  pending_count_ = 0;
}

void MultiPress::begin() {
  reset();
  started_ = true;

  // Delegate initialization to the owned Debounce object
  btn_.begin();
}

void MultiPress::update() {
  // Fail-safe: auto-start if user forgot begin()
  if (!started_) {
    begin();
  }

  const uint32_t now = millis();

  btn_.read();

  // If a result is already pending, do not start a new sequence yet.
  if (pending_count_ != 0) {
    return;
  }

  // Finalize sequence after quiet period.
  if (in_progress_count_ > 0) {
    const uint32_t gap = (uint32_t)(now - t_last_press_ms_);
    if (gap >= final_gap_ms_) {
      pending_count_ = in_progress_count_;
      in_progress_count_ = 0;
      return;
    }

    // Optional overall timeout
    if (seq_timeout_ms_ > 0) {
      const uint32_t age = (uint32_t)(now - t_first_ms_);
      if (age >= seq_timeout_ms_) {
        pending_count_ = in_progress_count_;
        in_progress_count_ = 0;
        return;
      }
    }
  }

  // Count debounced press edges (active-low button → FALLING edge)
  if (btn_.fell()) {
    if (in_progress_count_ == 0) {
      t_first_ms_ = now;
    }
    t_last_press_ms_ = now;
    ++in_progress_count_;
  }
}

uint8_t MultiPress::takeCount() {
  const uint8_t n = pending_count_;
  pending_count_ = 0;
  return n;
}
