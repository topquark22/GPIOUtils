#pragma once
#include <Arduino.h>

#ifndef GPIOUTILS_PUBLIC_INCLUDE
#warning "Include <gpioutils.h> instead of including impl/* directly."
#endif

class Schmitt {
public:
  // Tag type to disambiguate (center, hysteresis) construction.
  struct CenterHysteresisTag { explicit constexpr CenterHysteresisTag() = default; };
  static constexpr CenterHysteresisTag CenterHysteresis{};

  // Threshold-based constructor (recommended / unambiguous)
  Schmitt(uint8_t pin, int th_lo, int th_hi, bool initial_state = false);

  // Center/hysteresis constructor (tagged to avoid overload collision)
  Schmitt(uint8_t pin, int center, int hysteresis,
          CenterHysteresisTag /*tag*/, bool initial_state = false);

  void begin();
  bool read();
  bool state() const { return state_; }

private:
  uint8_t pin_;
  int th_lo_;
  int th_hi_;
  bool state_;
};
