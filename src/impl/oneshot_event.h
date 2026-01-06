#pragma once
#include <Arduino.h>

/**
 * @brief Event-driven one-shot / monostable.
 *
 * Call trigger() on an event; read() returns true for pulse_ms milliseconds.
 */
class OneShotEvent {
public:
  explicit OneShotEvent(uint32_t pulse_ms, bool retrigger = true)
  : pulse_ms_(pulse_ms), retrigger_(retrigger), active_(false), start_ms_(0) {}

  void begin() {} // kept for symmetry with other components

  void trigger() {
    const uint32_t now = millis();
    if (!active_ || retrigger_) {
      active_ = true;
      start_ms_ = now;
    }
  }

  bool read() {
    if (active_ && (millis() - start_ms_) >= pulse_ms_) {
      active_ = false;
    }
    return active_;
  }

  void reset() { active_ = false; }

  bool is_active() const { return active_; }
  uint32_t pulse_ms() const { return pulse_ms_; }
  void set_pulse_ms(uint32_t ms) { pulse_ms_ = ms; }

private:
  uint32_t pulse_ms_;
  bool retrigger_;
  bool active_;
  uint32_t start_ms_;
};
