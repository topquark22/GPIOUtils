#pragma once

#include <Arduino.h>

#ifndef GPIOUTILS_PUBLIC_INCLUDE
#warning "Include <gpioutils.h> instead of including impl/* directly."
#endif

/**
 * @brief Simple ADC deadband (dejitter) filter for potentiometer inputs.
 *
 * Holds the last accepted ADC value and ignores small variations
 * within a configurable deadband.
 */
class Dejitter {
public:
  /**
   * @brief Construct with default deadband (1 ADC count).
   *
   * Backward-compatible constructor.
   */
  explicit Dejitter(uint8_t pin);

  /**
   * @brief Construct with a user-defined deadband.
   *
   * @param pin Arduino analog pin (e.g., A0)
   * @param deadband Maximum delta (in ADC counts) to ignore
   */
  Dejitter(uint8_t pin, int deadband);

  /**
   * @return Filtered ADC reading
   */
  int read();

private:
  uint8_t pin_;      // Analog input pin
  int deadband_;     // Ignored delta (in ADC counts)
  int prev_value;    // Last accepted value
};
