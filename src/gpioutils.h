#pragma once

#include <Arduino.h>

#include "dejitter/dejitter.h"
#include "schmitt/schmitt.h"

/**
 * Convert an analogRead() 10-bit value to 8-bit with rounding
 */
inline uint8_t adc10to8(int v) {
  return (v * 255 + 511) / 1023;
}

/**
 * Convert an analogRead() 10-bit value to float in range 0.0 .. 1.0
 */
inline float adc10toFloat(int v) {
  return v * (1.0f / 1023.0f);
}

/**
 * Convert an analogRead() 10-bit value to float with range spec
 */
inline float adc10toFloat(int v, float min, float max) {
  return min + (max - min) * (v * (1.0f / 1023.0f));
}