#pragma once
#include <Arduino.h>

#ifndef GPIOUTILS_PUBLIC_INCLUDE
#warning "Include <gpioutils.h> instead of including impl/* directly."
#endif

/**
 * @brief Calibrate and map raw analogRead() values to normalized or scaled units.
 *
 * The most common use is to account for real-world end-stops:
 * - pots that only read (e.g.) 65..970 instead of 0..1023
 * - sensors with a known min/max
 *
 * This class performs:
 * - clamping to the calibrated raw range
 * - optional inversion (if raw_min > raw_max)
 * - mapping to [0,1] or to arbitrary output ranges
 *
 * Usage:
 *   AnalogCalibrator cal(65, 970);
 *   int raw = analogRead(A0);
 *   float u = cal.normalize(raw);      // 0..1
 *   int pwm = cal.map_int(raw, 0, 255);
 */
class AnalogCalibrator {
public:
  AnalogCalibrator(int16_t raw_min = 0, int16_t raw_max = 1023);

  void set_raw_range(int16_t raw_min, int16_t raw_max);

  int16_t raw_min() const { return raw_min_; }
  int16_t raw_max() const { return raw_max_; }

  /**
   * @brief Clamp raw to [raw_min, raw_max] accounting for inverted ranges.
   */
  int16_t clamp(int16_t raw) const;

  /**
   * @brief Normalize raw to 0..1 (float). Inverted ranges are handled.
   */
  float normalize(int16_t raw) const;

  /**
   * @brief Map raw to an integer range [out_min, out_max], inclusive.
   */
  int32_t map_int(int16_t raw, int32_t out_min, int32_t out_max) const;

  /**
   * @brief Map raw to a float range [out_min, out_max].
   */
  float map_float(int16_t raw, float out_min, float out_max) const;

private:
  int16_t raw_min_;
  int16_t raw_max_;

  int16_t lo_() const { return raw_min_ < raw_max_ ? raw_min_ : raw_max_; }
  int16_t hi_() const { return raw_min_ < raw_max_ ? raw_max_ : raw_min_; }
  bool inverted_() const { return raw_min_ > raw_max_; }
};
