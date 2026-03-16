#pragma once
/*
  Latch - a simple set/reset latch.

  - set() forces true
  - reset() forces false
  - update(setSignal, resetSignal) applies set/reset inputs (set wins if both true by default)
*/

#include <Arduino.h>

#ifndef GPIOUTILS_PUBLIC_INCLUDE
#warning "Include <GPIOUtils.h> instead of including impl/* directly."
#endif

class Latch {
public:
  explicit Latch(bool initial = false);

  void set();
  void reset();
  void toggle();

  void update(bool setSignal, bool resetSignal, bool setWins = true);

  bool value() const;

private:
  bool state_;
};
