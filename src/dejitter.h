#pragma once

#include <Arduino.h>

/**
 * Dejitter an analog input pin
 */
class Dejitter {
public:
  Dejitter(uint8_t pin);

  int read();

private:
  uint8_t pin_;
  int prev_value;
};