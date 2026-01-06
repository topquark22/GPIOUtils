#include "edgedetector.h"

EdgeDetector::EdgeDetector(uint8_t pin, uint8_t mode)
: pin_(pin),
  mode_(mode),
  state_(false),
  prev_(false),
  changed_(false),
  rose_(false),
  fell_(false)
{
}

EdgeDetector::EdgeDetector(uint8_t pin)
: EdgeDetector(pin, INPUT)
{
}

void EdgeDetector::begin() {
  pinMode(pin_, mode_);
  const bool r = (digitalRead(pin_) != LOW);
  state_ = prev_ = r;
}

bool EdgeDetector::read() {
  changed_ = rose_ = fell_ = false;

  const bool r = (digitalRead(pin_) != LOW);
  state_ = r;

  if (state_ != prev_) {
    changed_ = true;
    rose_ = (!prev_ && state_);
    fell_ = (prev_ && !state_);
    prev_ = state_;
  }

  return state_;
}
