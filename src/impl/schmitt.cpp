#include "schmitt.h"

static int clamp_adc(int v) {
  if (v < 0) return 0;
  if (v > 1023) return 1023;
  return v;
}

void Schmitt::init_(uint8_t pin, int lo, int hi, bool initial_state) {
  pin_ = pin;

  // Ensure ordering
  if (lo > hi) {
    int tmp = lo; lo = hi; hi = tmp;
  }

  th_lo_ = clamp_adc(lo);
  th_hi_ = clamp_adc(hi);

  // If thresholds collapse, behavior degenerates to a single threshold.
  // Still well-defined, just not much hysteresis.
  state_ = initial_state;
  last_adc_ = -1;

  pinMode(pin_, INPUT);
}

Schmitt::Schmitt(uint8_t pin, int th_lo, int th_hi, bool initial_state) {
  init_(pin, th_lo, th_hi, initial_state);
}

Schmitt::Schmitt(uint8_t pin, int center, int hysteresis, bool initial_state) {
  // Interpret "hysteresis" as half-width in ADC counts.
  // If you prefer it as full-width, change +/- hysteresis/2.
  const int lo = center - hysteresis;
  const int hi = center + hysteresis;
  init_(pin, lo, hi, initial_state);
}

bool Schmitt::read() {
  const int v = analogRead(pin_);
  last_adc_ = v;

  if (!state_) {
    if (v >= th_hi_) state_ = true;
  } else {
    if (v <= th_lo_) state_ = false;
  }
  return state_;
}
