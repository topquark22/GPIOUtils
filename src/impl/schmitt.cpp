#include "schmitt.h"

constexpr Schmitt::CenterHysteresisTag Schmitt::CenterHysteresis;

Schmitt::Schmitt(uint8_t pin, int th_lo, int th_hi, bool initial_state)
: pin_(pin), th_lo_(th_lo), th_hi_(th_hi), state_(initial_state)
{
  // (Optional) you can normalize if th_lo > th_hi, but not required
}

Schmitt::Schmitt(uint8_t pin, int center, int hysteresis,
                 CenterHysteresisTag, bool initial_state)
: pin_(pin),
  th_lo_(center - hysteresis),
  th_hi_(center + hysteresis),
  state_(initial_state)
{
}

void Schmitt::begin() {
  // analog pins don't strictly need pinMode, but keeping convention is fine
  pinMode(pin_, INPUT);

  // Initialize state based on current reading (optional but usually desired)
  int v = analogRead(pin_);
  if (v >= th_hi_) state_ = true;
  else if (v <= th_lo_) state_ = false;
}

bool Schmitt::read() {
  int v = analogRead(pin_);
  if (!state_ && v >= th_hi_) state_ = true;
  else if (state_ && v <= th_lo_) state_ = false;
  return state_;
}
