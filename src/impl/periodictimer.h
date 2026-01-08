#pragma once
#include <Arduino.h>

#ifndef GPIOUTILS_PUBLIC_INCLUDE
#warning "Include <gpioutils.h> instead of including impl/* directly."
#endif

/**
 * @brief A simple non-blocking periodic timer (millis-based, rollover-safe).
 *
 * Typical usage:
 *   PeriodicTimer t(1000); // 1 second
 *   ...
 *   if (t.tick()) { ... }  // runs once per period
 */
class PeriodicTimer {
public:
  explicit PeriodicTimer(uint32_t period_ms = 0, bool start_immediately = true);

  void set_period(uint32_t period_ms);
  uint32_t period() const { return period_ms_; }

  void start();     // start counting from "now"
  void stop();
  bool running() const { return running_; }

  void restart();   // alias of start()
  void reset();     // set next tick to now + period (keeps running state)

  /**
   * @brief Returns true once when the timer elapses, then schedules the next tick.
   *
   * This uses "next += period" (not "next = now + period") to reduce drift.
   * If the loop is late, it will catch up by advancing next tick forward
   * (but still returns true only once per call).
   */
  bool tick();

  /**
   * @brief True if elapsed, without advancing the schedule.
   */
  bool expired() const;

private:
  uint32_t period_ms_;
  uint32_t next_ms_;
  bool running_;
};
