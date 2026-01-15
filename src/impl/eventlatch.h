#pragma once

#include <Arduino.h>

/**
 * @brief A tiny read-to-clear event latch.
 *
 * - begin():          starts LOW
 * - begin(startHigh): starts HIGH if true, LOW if false
 * - trigger():        latches HIGH
 * - read():           returns state, then clears to LOW
 * - peek():           returns state without clearing
 * - clear():          clears to LOW
 */
class EventLatch {
public:
  EventLatch() = default;

  // Start LOW
  void begin();

  // Start HIGH if startHigh == true, else LOW
  void begin(bool startHigh);

  // Latch HIGH
  void trigger();

  // Read-to-clear
  bool read();

  // Read without clearing
  bool peek() const;

  // Clear to LOW
  void clear();

private:
  bool state_ = false; // false = LOW, true = HIGH
};
