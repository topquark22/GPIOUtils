#include "dejitter.h"

Dejitter::Dejitter(uint8_t pin)
: pin_(pin), deadband_(1), snap_(1), value_(0), initialized_(false) {}

Dejitter::Dejitter(uint8_t pin, int deadband)
: pin_(pin),
  deadband_(deadband),
  snap_(deadband < 0 ? 0 : deadband),
  value_(0),
  initialized_(false) {}

Dejitter::Dejitter(uint8_t pin, int deadband, int snap)
: pin_(pin),
  deadband_(deadband < 0 ? 0 : deadband),
  snap_(snap < 0 ? 0 : snap),
  value_(0),
  initialized_(false) {}

void Dejitter::begin() {
  pinMode(pin_, INPUT);
  value_ = analogRead(pin_);
  initialized_ = true;
}

int Dejitter::read() {
  int v = analogRead(pin_);

  if (!initialized_) {
    value_ = v;
    initialized_ = true;
    return value_;
  }

  // Endpoint snap: guarantee reachability of 0 and 1023
  if (v <= kAdcMin + snap_) {
    value_ = kAdcMin;
    return value_;
  }
  if (v >= kAdcMax - snap_) {
    value_ = kAdcMax;
    return value_;
  }

  // Deadband hold
  if (abs(v - value_) > deadband_) {
    value_ = v;
  }

  return value_;
}
