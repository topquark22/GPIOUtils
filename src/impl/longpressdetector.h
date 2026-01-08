#pragma once
#include <Arduino.h>

#ifndef GPIOUTILS_PUBLIC_INCLUDE
#warning "Include <gpioutils.h> instead of including impl/* directly."
#endif

/**
 * @brief Detects a long-press given a boolean "pressed" signal.
 *
 * This class does NOT own a GPIO pin; pair it with Debounce (or any source)
 * that provides a stable pressed/released state.
 *
 * Semantics:
 * - update(pressed) should be called frequently.
 * - long_pressed() is an event: it becomes true once when the press duration
 *   crosses the threshold, then clears on the next update() call.
 * - is_long_pressed() is a state: true after threshold while still pressed.
 */
class LongPressDetector {
public:
  explicit LongPressDetector(uint32_t longpress_ms);

  void set_longpress_ms(uint32_t ms) { longpress_ms_ = ms; }
  uint32_t longpress_ms() const { return longpress_ms_; }

  void reset();

  // Call frequently with current pressed state (true = pressed).
  bool update(bool pressed);

  bool pressed() const { return pressed_; }

  // Event: true only for one update cycle when threshold is reached.
  bool long_pressed() const { return long_pressed_event_; }

  // State: true while pressed after reaching threshold.
  bool is_long_pressed() const { return long_pressed_state_; }

private:
  uint32_t longpress_ms_;

  bool pressed_;
  bool long_pressed_state_;
  bool long_pressed_event_;
  uint32_t press_start_ms_;
};
