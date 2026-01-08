#pragma once
/*
  Latch - a simple set/reset latch.

  - set() forces true
  - reset() forces false
  - update(setSignal, resetSignal) applies set/reset inputs (set wins if both true by default)
*/

#include <Arduino.h>

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
