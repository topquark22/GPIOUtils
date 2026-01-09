#pragma once
#include <Arduino.h>

#ifndef GPIOUTILS_PUBLIC_INCLUDE
#warning "Include <GPIOUtils.h> instead of including impl/* directly."
#endif

/**
 * @brief Generate "key repeat" events while a boolean pressed signal is held.
 *
 * This class does NOT own a GPIO pin. Pair it with Debounce (or any source)
 * that provides a stable pressed/released state.
 *
 * Semantics:
 * - On the transition to pressed, no event is generated immediately.
 * - After initial_delay_ms elapses, fired() becomes true once.
 * - While still pressed, fired() becomes true every repeat_ms thereafter.
 * - On release, the internal schedule resets.
 *
 * Usage:
 *   AutoRepeat ar(500, 150);  // 500 ms delay, then 150 ms repeat
 *   ...
 *   bool pressed = ...;       // stable
 *   ar.update(pressed);
 *   if (ar.fired()) { ... }   // do one repeat step
 */
class AutoRepeat {
public:
  AutoRepeat(uint32_t initial_delay_ms, uint32_t repeat_ms);

  void reset();

  /**
   * @brief Update with current pressed state. Call frequently from loop().
   */
  void update(bool pressed);

  bool pressed() const { return pressed_; }

  /**
   * @brief True if a repeat event fired on the most recent update().
   */
  bool fired() const { return fired_; }

  uint32_t initial_delay_ms() const { return initial_delay_ms_; }
  uint32_t repeat_ms() const { return repeat_ms_; }

private:
  uint32_t initial_delay_ms_;
  uint32_t repeat_ms_;

  bool pressed_{false};
  bool fired_{false};
  uint32_t next_fire_ms_{0};
};
