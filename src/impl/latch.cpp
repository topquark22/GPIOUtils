#include "latch.h"

Latch::Latch(bool initial)
: state_(initial)
{
}

void Latch::set() {
  state_ = true;
}

void Latch::reset() {
  state_ = false;
}

void Latch::toggle() {
  state_ = !state_;
}

void Latch::update(bool setSignal, bool resetSignal, bool setWins) {
  if (setSignal && resetSignal) {
    state_ = setWins ? true : false;
  } else if (setSignal) {
    state_ = true;
  } else if (resetSignal) {
    state_ = false;
  }
}

bool Latch::value() const {
  return state_;
}
