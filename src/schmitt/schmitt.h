#pragma once
#include <Arduino.h>

/**
 * @brief Schmitt trigger for an analog input.
 *
 * Reads an analog input and returns a boolean with hysteresis:
 * - Rising threshold:  value >= th_hi -> output becomes true
 * - Falling threshold: value <= th_lo -> output becomes false
 * - Between thresholds: output holds previous state
 */
class Schmitt {
public:
  // Backward-friendly: explicit thresholds in ADC counts (0..1023)
  Schmitt(uint8_t pin, int th_lo, int th_hi, bool initial_state = false);

  // Convenience: specify center + hysteresis width (in ADC counts)
  // Example: center=512, hyst=20 => th_lo=502, th_hi=522
  Schmitt(uint8_t pin, int center, int hysteresis, bool initial_state = false);

  bool read();          // reads ADC, updates internal state, returns state
  bool state() const { return state_; }  // returns current state without reading

  int last_adc() const { return last_adc_; }

private:
  void init_(uint8_t pin, int lo, int hi, bool initial_state);

  uint8_t pin_;
  int th_lo_;
  int th_hi_;
  bool state_;
  int last_adc_;
};
