#pragma once
/*
  GPIOUtils - public umbrella header

  Users should include ONLY this file:

      #include <gpioutils.h>

  All implementation headers live under src/impl/.
*/

#define GPIOUTILS_PUBLIC_INCLUDE 1

#include <Arduino.h>

//
// Analog input utilities
//
#include "impl/analogcalibrator.h"
#include "impl/analogintegrator.h"
#include "impl/dejitter.h"
#include "impl/schmitt.h"

//
// Digital input utilities
//
#include "impl/debounce.h"
#include "impl/edgedetector.h"
#include "impl/glitchfilter.h"
#include "impl/multipress.h"

//
// Event / value-driven utilities (no GPIO ownership)
//
#include "impl/oneshot_event.h"
#include "impl/toggle.h"
#include "impl/ratelimiter.h"
#include "impl/periodictimer.h"
#include "impl/longpressdetector.h"
#include "impl/autorepeat.h"

//
// Digital output utilities
//
#include "impl/timedoutput.h"
#include "impl/pulsegenerator.h"

//
// -----------------------------------------------------------------------------
// Inline utility helpers
// -----------------------------------------------------------------------------

//
// Small utilities
//
#include "impl/latch.h"
#include "impl/softwatchdog.h"

/**
 * @brief Convert a 10-bit ADC reading (0..1023) to an 8-bit value (0..255),
 *        with proper rounding.
 */
static inline uint8_t adcToU8(uint16_t adc)
{
  // Scale by 255/1023 with rounding
  return (adc * 255u + 511u) / 1023u;
}

/**
 * @brief Convert a 10-bit ADC reading (0..1023) to a float in the range [0.0, 1.0].
 */
static inline float adcToFloat(uint16_t adc)
{
  return adc * (1.0f / 1023.0f);
}

/**
 * @brief Convert a 10-bit ADC reading (0..1023) to a float in an arbitrary range.
 */
static inline float adcToFloat(uint16_t adc, float minVal, float maxVal)
{
  return minVal + (maxVal - minVal) * (adc * (1.0f / 1023.0f));
}
