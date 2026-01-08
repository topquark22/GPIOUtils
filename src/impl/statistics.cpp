#include "statistics.h"

Statistics::Statistics() {
  reset();
}

void Statistics::reset() {
  count_ = 0;
  min_ = 0;
  max_ = 0;
  mean_ = 0.0;
}

void Statistics::add(uint32_t sample) {
  if (count_ == 0) {
    min_ = max_ = sample;
    mean_ = sample;
    count_ = 1;
    return;
  }

  if (sample < min_) min_ = sample;
  if (sample > max_) max_ = sample;

  // running mean: mean_{n+1} = mean_n + (x - mean_n)/(n+1)
  count_++;
  mean_ += (static_cast<double>(sample) - mean_) / static_cast<double>(count_);
}

uint32_t Statistics::count() const { return count_; }
uint32_t Statistics::min() const { return min_; }
uint32_t Statistics::max() const { return max_; }

double Statistics::mean() const { return mean_; }
float Statistics::meanf() const { return static_cast<float>(mean_); }
