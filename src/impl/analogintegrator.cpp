#include "analogintegrator.h"

AnalogIntegrator::AnalogIntegrator(float scale)
: scale_(scale)
{
  reset();
}

void AnalogIntegrator::reset() {
  hasPrev_ = false;
  prevValue_ = 0.0f;
  prevMs_ = millis();
  integral_ = 0.0f;
}

void AnalogIntegrator::setScale(float scale) {
  scale_ = scale;
}

float AnalogIntegrator::scale() const {
  return scale_;
}

float AnalogIntegrator::update(float value) {
  uint32_t now = millis();

  if (!hasPrev_) {
    hasPrev_ = true;
    prevValue_ = value;
    prevMs_ = now;
    return integral_;
  }

  uint32_t dtMs = static_cast<uint32_t>(now - prevMs_);
  prevMs_ = now;

  // Convert to seconds
  float dt = dtMs * 0.001f;

  // Trapezoid area: (v_prev + v_curr)/2 * dt
  integral_ += scale_ * (0.5f * (prevValue_ + value) * dt);
  prevValue_ = value;

  return integral_;
}

float AnalogIntegrator::value() const {
  return integral_;
}
