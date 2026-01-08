#pragma once
/*
  SoftWatchdog - a simple software watchdog timer.

  Detects when some expected activity has not occurred within a timeout.
  This does NOT reset the MCU; it only reports expiration so your sketch can
  take action (log, safe-state outputs, etc.).
*/

#include <Arduino.h>

class SoftWatchdog {
public:
  explicit SoftWatchdog(uint32_t timeoutMs);

  void setTimeout(uint32_t timeoutMs);
  void kick();

  /**
   * @brief Returns true if the time since the last kick is >= timeout.
   */
  bool expired() const;

  /**
   * @brief Milliseconds since last kick.
   */
  uint32_t ageMs() const;

  uint32_t timeoutMs() const;

private:
  uint32_t timeoutMs_;
  uint32_t lastKickMs_;
};
