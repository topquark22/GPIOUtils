#pragma once
#include <Arduino.h>

#ifndef GPIOUTILS_PUBLIC_INCLUDE
#warning "Include <gpioutils.h> instead of including impl/* directly."
#endif

/**
 * @brief Event-driven toggle latch.
 *
 * Each trigger() flips the internal boolean state.
 * Typical use: toggle an LED or mode with a button press.
 */
class Toggle {
public:
  /**
   * @param initial_state starting state (default: false)
   */
  explicit Toggle(bool initial_state = false)
  : state_(initial_state),
    toggled_(false)
  {}

  void begin() {} // symmetry only

  /**
   * @brief Flip the state.
   */
  void trigger() {
    state_ = !state_;
    toggled_ = true;
  }

  /**
   * @brief Return current state.
   * Clears the toggled() flag.
   */
  bool read() {
    toggled_ = false;
    return state_;
  }

  bool state() const { return state_; }

  /**
   * @brief True if the state changed since last read().
   */
  bool toggled() const { return toggled_; }

private:
  bool state_;
  bool toggled_;
};
