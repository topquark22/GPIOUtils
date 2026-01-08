#pragma once
/*
  AnalogIntegrator - integrate a scalar signal over time.

  Notes:
    - Uses trapezoidal integration between samples.
    - Call update(value) regularly (whenever you have a new sample).
    - dt is derived from millis() and interpreted as seconds.
*/

#include <Arduino.h>

class AnalogIntegrator {
public:
  explicit AnalogIntegrator(float scale = 1.0f);

  void reset();

  void setScale(float scale);
  float scale() const;

  float update(float value);

  float value() const;

private:
  float scale_;
  bool hasPrev_;
  float prevValue_;
  uint32_t prevMs_;
  float integral_;
};
