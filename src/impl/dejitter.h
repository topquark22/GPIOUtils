#pragma once
#include <Arduino.h>

#ifndef GPIOUTILS_PUBLIC_INCLUDE
#warning "Include <gpioutils.h> instead of including impl/* directly."
#endif

class Dejitter {
public:
  // Backwards-compatible: deadband = 1, snap = 1
  explicit Dejitter(uint8_t pin);

  // deadband only: snap defaults to deadband
  Dejitter(uint8_t pin, int deadband);

  // full control
  Dejitter(uint8_t pin, int deadband, int snap);

  void begin();
  int read();

  int value() const { return value_; }
  int deadband() const { return deadband_; }
  int snap() const { return snap_; }

private:
  static constexpr int kAdcMin = 0;
  static constexpr int kAdcMax = 1023;

  uint8_t pin_;
  int deadband_;
  int snap_;
  int value_;
  bool initialized_;
};
