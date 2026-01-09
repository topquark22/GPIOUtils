#pragma once
#include <Arduino.h>

#ifndef GPIOUTILS_PUBLIC_INCLUDE
#warning "Include <GPIOUtils.h> instead of including impl/* directly."
#endif

/**
 * @brief Non-blocking timed digital output.
 *
 * Owns a GPIO output pin. Can be turned on/off, or pulsed for a duration
 * without delay().
 *
 * Example:
 *   TimedOutput led(13, OUTPUT, true); // active-high LED
 *   led.begin();
 *   led.pulse(120); // on for 120ms, then off automatically
 */
class TimedOutput {
public:
  /**
   * @param pin Output pin
   * @param mode Usually OUTPUT (kept configurable for completeness)
   * @param active_high If true, "on" drives HIGH; if false, "on" drives LOW
   * @param retrigger If true, pulse() while active restarts the timer
   */
  TimedOutput(uint8_t pin,
              uint8_t mode = OUTPUT,
              bool active_high = true,
              bool retrigger = true);

  /**
   * @brief Configure pinMode and initialize output to OFF.
   */
  void begin();

  /**
   * @brief Call regularly (e.g., each loop) to update timing state.
   * @return current logical state (true = ON, false = OFF)
   */
  bool read();

  /**
   * @brief Turn output ON indefinitely (cancels any timed pulse).
   */
  void on();

  /**
   * @brief Turn output OFF immediately (cancels any timed pulse).
   */
  void off();

  /**
   * @brief Pulse output ON for duration_ms, then auto-OFF.
   * If retrigger is enabled, calling pulse() while active restarts the timer.
   */
  void pulse(uint32_t duration_ms);

  bool is_on() const { return logical_on_; }
  bool is_pulsing() const { return pulsing_; }

private:
  void write_(bool logical_on);

  uint8_t pin_;
  uint8_t mode_;
  bool active_high_;
  bool retrigger_;

  bool logical_on_;     // logical state: true=ON, false=OFF
  bool pulsing_;        // true if currently in timed pulse mode
  uint32_t start_ms_;
  uint32_t duration_ms_;
};
