#include "ratelimiter.h"

RateLimiter::RateLimiter(float max_rise_per_sec,
                         float max_fall_per_sec,
                         float initial_value)
: max_rise_per_sec_(max_rise_per_sec),
  max_fall_per_sec_(max_fall_per_sec),
  y_(initial_value),
  last_ms_(0),
  started_(false)
{
}

void RateLimiter::begin() {
  last_ms_ = millis();
  started_ = true;
}

float RateLimiter::read(float input) {
  const unsigned long now = millis();

  // First call safety if begin() wasn't called
  if (!started_) {
    last_ms_ = now;
    started_ = true;
    y_ = input;        // or keep initial_value; choose one policy
    return y_;
  }

  const unsigned long dt_ms = now - last_ms_;
  last_ms_ = now;

  const float dt = dt_ms * 1.0e-3f; // seconds

  const float err = input - y_;
  if (err == 0.0f || dt <= 0.0f) return y_;

  // Compute maximum allowed step this update
  const float max_up   = max_rise_per_sec_ * dt;
  const float max_down = max_fall_per_sec_ * dt;

  if (err > 0.0f) {
    // moving up
    const float step = (err > max_up) ? max_up : err;
    y_ += step;
  } else {
    // moving down
    const float step = (-err > max_down) ? max_down : (-err);
    y_ -= step;
  }

  return y_;
}
