#include "analogcalibrator.h"

AnalogCalibrator::AnalogCalibrator(int16_t raw_min, int16_t raw_max)
: raw_min_(raw_min), raw_max_(raw_max) {}

void AnalogCalibrator::set_raw_range(int16_t raw_min, int16_t raw_max) {
  raw_min_ = raw_min;
  raw_max_ = raw_max;
}

int16_t AnalogCalibrator::clamp(int16_t raw) const {
  int16_t lo = lo_();
  int16_t hi = hi_();
  if (raw < lo) return lo;
  if (raw > hi) return hi;
  return raw;
}

float AnalogCalibrator::normalize(int16_t raw) const {
  int16_t lo = lo_();
  int16_t hi = hi_();
  int16_t c = clamp(raw);

  int32_t span = (int32_t)hi - (int32_t)lo;
  if (span <= 0) return 0.0f;

  float u = ((float)((int32_t)c - (int32_t)lo)) / (float)span; // 0..1
  if (inverted_()) u = 1.0f - u;
  if (u < 0.0f) u = 0.0f;
  if (u > 1.0f) u = 1.0f;
  return u;
}

int32_t AnalogCalibrator::map_int(int16_t raw, int32_t out_min, int32_t out_max) const {
  float u = normalize(raw);
  float y = (float)out_min + u * (float)(out_max - out_min);
  // Round to nearest integer.
  if (y >= 0.0f) return (int32_t)(y + 0.5f);
  return (int32_t)(y - 0.5f);
}

float AnalogCalibrator::map_float(int16_t raw, float out_min, float out_max) const {
  float u = normalize(raw);
  return out_min + u * (out_max - out_min);
}
