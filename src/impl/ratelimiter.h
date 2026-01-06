#pragma once
#include <Arduino.h>

#ifndef GPIOUTILS_PUBLIC_INCLUDE
#warning "Include <gpioutils.h> instead of including impl/* directly."
#endif

/**
 * @brief Rate limiter (slew limiter) for scalar values.
 *
 * Limits how fast the output can change toward the input:
 *  - max_rise_per_sec limits upward change rate
 *  - max_fall_per_sec limits downward change rate
 *
 * This is NOT an averaging filter. It preserves steps, but spreads them over time.
 * Useful for PWM brightness ramps, smoothing pot-controlled parameters, etc.
 */
class RateLimiter {
public:
  /**
   * @param max_rise_per_sec Maximum upward change per second (units/sec)
   * @param max_fall_per_sec Maximum downward change per second (units/sec)
   * @param initial_value Starting output value
   */
  RateLimiter(float max_rise_per_sec,
              float max_fall_per_sec,
              float initial_value = 0.0f);

  void begin();               // initializes internal timer (call in setup)
  float read(float input);    // update toward input, return limited output

  float value() const { return y_; }
  void set_value(float v) { y_ = v; last_ms_ = millis(); } // force output now

private:
  float max_rise_per_sec_;
  float max_fall_per_sec_;

  float y_;
  uint32_t last_ms_;
  bool started_;
};
