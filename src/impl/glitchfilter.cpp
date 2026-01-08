#include "glitchfilter.h"

GlitchFilter::GlitchFilter(uint8_t pin, uint8_t mode, uint32_t min_stable_ms)
: pin_(pin),
  mode_(mode),
  min_stable_ms_(min_stable_ms),
  stable_(false),
  raw_(false),
  candidate_(false),
  candidate_since_ms_(0),
  changed_(false),
  rose_(false),
  fell_(false)
{
}

GlitchFilter::GlitchFilter(uint8_t pin, uint32_t min_stable_ms)
: GlitchFilter(pin, INPUT, min_stable_ms)
{
}

void GlitchFilter::begin()
{
  pinMode(pin_, mode_);
  raw_ = digitalRead(pin_);
  stable_ = raw_;
  candidate_ = stable_;
  candidate_since_ms_ = millis();
  changed_ = rose_ = fell_ = false;
}

bool GlitchFilter::read()
{
  changed_ = rose_ = fell_ = false;

  raw_ = digitalRead(pin_);
  const uint32_t now = millis();

  if (raw_ == stable_) {
    // back to stable; abandon any pending candidate
    candidate_ = stable_;
    candidate_since_ms_ = now;
    return stable_;
  }

  // raw differs from stable. Track a candidate state.
  if (raw_ != candidate_) {
    candidate_ = raw_;
    candidate_since_ms_ = now;
    return stable_;
  }

  // candidate has persisted; accept after min_stable_ms
  if ((now - candidate_since_ms_) >= min_stable_ms_) {
    const bool prev = stable_;
    stable_ = candidate_;
    changed_ = true;
    rose_ = (!prev && stable_);
    fell_ = (prev && !stable_);
  }

  return stable_;
}
