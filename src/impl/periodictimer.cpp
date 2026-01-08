#include "periodictimer.h"

PeriodicTimer::PeriodicTimer(uint32_t period_ms, bool start_immediately)
: period_ms_(period_ms),
  next_ms_(0),
  running_(false)
{
  if (start_immediately) {
    start();
  }
}

void PeriodicTimer::set_period(uint32_t period_ms)
{
  period_ms_ = period_ms;
  // keep schedule sane
  if (running_) {
    reset();
  }
}

void PeriodicTimer::start()
{
  running_ = true;
  reset();
}

void PeriodicTimer::restart()
{
  start();
}

void PeriodicTimer::stop()
{
  running_ = false;
}

void PeriodicTimer::reset()
{
  const uint32_t now = millis();
  next_ms_ = now + period_ms_;
}

bool PeriodicTimer::expired() const
{
  if (!running_) return false;
  const uint32_t now = millis();
  return (int32_t)(now - next_ms_) >= 0;
}

bool PeriodicTimer::tick()
{
  if (!running_) return false;
  if (period_ms_ == 0) return true; // degenerate: always tick

  const uint32_t now = millis();
  if ((int32_t)(now - next_ms_) < 0) {
    return false;
  }

  // advance at least once, and catch up if we fell behind
  do {
    next_ms_ += period_ms_;
  } while ((int32_t)(now - next_ms_) >= 0);

  return true;
}
