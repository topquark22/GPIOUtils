#pragma once

#include <Arduino.h>

#ifndef GPIOUTILS_PUBLIC_INCLUDE
#warning "Include <GPIOUtils.h> instead of including impl/* directly."
#endif

/*
  SoftWatchdog - a simple software watchdog timer.

  Detects when some expected activity has not occurred within a timeout.
  This does NOT reset the MCU; it only reports expiration so your sketch can
  take action (log, safe-state outputs, etc.).
*/

class SoftWatchdog
{
public:
  explicit SoftWatchdog(uint32_t timeoutMs);

  /** Change timeout at runtime. */
  void setTimeout(uint32_t timeoutMs);

  /** Start/restart the watchdog "now". Call in setup(), or anytime you want to reset it. */
  void begin();

  /** Reset the watchdog timer (record activity). */
  void kick();

  /** Returns true if the time since the last kick is >= timeout. */
  bool expired() const;

  /** Milliseconds since last kick. */
  uint32_t ageMs() const;

  /** Configured timeout in milliseconds. */
  uint32_t timeoutMs() const { return timeoutMs_; }

private:
  uint32_t timeoutMs_;
  uint32_t lastKickMs_;
};
