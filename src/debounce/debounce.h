#pragma once

#include <Arduino.h>

/**
 * @brief Debounced digital input (button/switch).
 *
 * Holds a stable state and updates it only when the raw input has remained
 * unchanged for debounce_ms milliseconds.
 *
 * Typical usage:
 *   Debounce btn(2, INPUT_PULLUP, 25);
 *   void loop() {
 *     if (btn.fell()) { ... }   // button pressed (active-low)
 *   }
 */
class Debounce {
public:
  /**
   * @param pin GPIO pin number
   * @param mode pinMode mode (e.g., INPUT, INPUT_PULLUP)
   * @param debounce_ms time input must remain stable before accepting (ms)
   * @param initial_state optional initial stable state (default: read pin at construction)
   */
  Debounce(uint8_t pin, uint8_t mode, uint32_t debounce_ms, bool initial_state = true);

  /**
   * Backward-friendly convenience constructor: INPUT mode.
   */
  Debounce(uint8_t pin, uint32_t debounce_ms);

  /**
   * Sample the pin, update internal debounced state, and return stable state.
   * Call this once per loop (or more), no delays required.
   */
  bool read();

  // Debounced state accessors
  bool stable() const { return stable_; }
  bool raw() const { return raw_; }

  // Event helpers based on debounced transitions since last read()
  bool changed() const { return changed_; }
  bool rose() const { return rose_; }
  bool fell() const { return fell_; }

private:
  uint8_t pin_;
  uint32_t debounce_ms_;

  bool stable_;        // last accepted stable state
  bool raw_;           // most recent raw reading
  bool last_raw_;      // raw reading seen when timer started

  uint32_t last_change_ms_;  // time when raw last changed
  bool changed_;
  bool rose_;
  bool fell_;
};
