#pragma once

#include <Arduino.h>
#include "debounce.h"

#ifndef GPIOUTILS_PUBLIC_INCLUDE
#warning "Include <gpioutils.h> instead of including impl/* directly."
#endif

/**
 * @brief Count multiple button presses, reporting only after the sequence ends.
 *
 * Owns the GPIO pin and debounces internally (active-low, INPUT_PULLUP).
 *
 * Behavior:
 *  - Counts debounced press edges.
 *  - The sequence is considered "finished" after final_gap_ms of no new presses.
 *  - takeCount() returns 0 until the sequence is finished, then returns the total
 *    count ONCE and clears it.
 *
 * Optional:
 *  - sequence_timeout_ms (0 disables) limits how long a sequence is allowed to stay
 *    open from first press. If exceeded, the sequence is finalized immediately.
 */
class MultiPress {
public:
  MultiPress(uint8_t pin,
             uint32_t debounce_ms,
             uint32_t final_gap_ms,
             uint32_t sequence_timeout_ms = 0);

  /** Call from setup() to initialize internal timers/state. */
  void begin();

  /** Call frequently (e.g., each loop). */
  void update();

  /**
   * @brief Returns the finished sequence count (>=1) or 0 if no finished sequence.
   * One-shot "consume": it clears the pending result.
   */
  uint8_t takeCount();

  /** Clears any in-progress sequence and any pending result. */
  void reset();

  uint32_t final_gap_ms() const { return final_gap_ms_; }
  uint32_t sequence_timeout_ms() const { return seq_timeout_ms_; }

private:
  Debounce btn_;

  uint32_t final_gap_ms_;
  uint32_t seq_timeout_ms_;

  // In-progress sequence
  uint8_t  in_progress_count_;
  uint32_t t_first_ms_;
  uint32_t t_last_press_ms_;

  // Finished result waiting to be consumed
  uint8_t pending_count_;

  bool started_;
};
