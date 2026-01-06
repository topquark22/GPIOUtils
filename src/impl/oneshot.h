#pragma once

#include <Arduino.h>

#ifndef GPIOUTILS_PUBLIC_INCLUDE
#warning "Include <gpioutils.h> instead of including impl/* directly."
#endif

/**
 * @brief One-shot / monostable pulse generator driven by a GPIO input.
 *
 * On a selected input edge, output becomes true for pulse_ms milliseconds,
 * then automatically returns false.
 */
class OneShot {
public:
  enum class Edge {
    Rising,
    Falling
  };

  /**
   * @param pin GPIO input pin
   * @param mode pinMode mode (e.g., INPUT, INPUT_PULLUP)
   * @param edge which edge triggers the pulse
   * @param pulse_ms pulse width in milliseconds
   * @param retrigger restart pulse if triggered while active
   */
  OneShot(uint8_t pin,
          uint8_t mode,
          Edge edge,
          uint32_t pulse_ms,
          bool retrigger = true);

  /**
   * @brief Configure pinMode and initialize internal state.
   * Call once from setup().
   */
  void begin();

  /**
   * @brief Sample the pin, update state, and return output.
   * Call regularly from loop().
   */
  bool read();

  bool is_active() const { return active_; }

private:
  uint8_t pin_;
  uint8_t mode_;
  Edge edge_;
  uint32_t pulse_ms_;
  bool retrigger_;

  bool last_input_;
  bool active_;
  uint32_t start_ms_;
};
