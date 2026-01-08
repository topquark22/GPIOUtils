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
  explicit Toggle(bool initial_state = false);

  void begin(); // symmetry only

  bool set(bool new_state);
  void trigger();
  bool read();

  bool state() const;
  bool toggled() const;

private:
  bool state_;
  bool toggled_;
};
