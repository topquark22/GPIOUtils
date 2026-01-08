#pragma once
/*
  Statistics - lightweight running stats for uint32_t samples.

  Tracks:
    - count
    - min / max
    - mean (running average)

  Notes:
    - mean is stored as double for numerical stability on AVR and larger targets.
*/

#include <Arduino.h>

class Statistics {
public:
  Statistics();

  void reset();
  void add(uint32_t sample);

  uint32_t count() const;
  uint32_t min() const;
  uint32_t max() const;

  double mean() const;
  float meanf() const;

private:
  uint32_t count_;
  uint32_t min_;
  uint32_t max_;
  double mean_;
};
