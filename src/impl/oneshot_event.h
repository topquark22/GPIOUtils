#pragma once
#include <Arduino.h>

#ifndef GPIOUTILS_PUBLIC_INCLUDE
#warning "Include <GPIOUtils.h> instead of including impl/* directly."
#endif

/**
 * @brief Event-driven one-shot / monostable.
 *
 * Call trigger() on an event; read() returns true for pulse_ms milliseconds.
 * Optionally, the pulse can be scheduled to begin after a delay.
 */
class OneShotEvent {
public:
  explicit OneShotEvent(uint32_t pulse_ms, bool retrigger = true);
  OneShotEvent(uint32_t pulse_ms, uint32_t delay_ms, bool retrigger = true);

  void begin();

  void trigger();
  bool read();

  void reset();

  bool is_active() const;
  uint32_t pulse_ms() const;
  void set_pulse_ms(uint32_t ms);

private:
  enum State : uint8_t {
    IDLE,
    DELAYING,
    ACTIVE
  };

  uint32_t pulse_ms_;
  uint32_t delay_ms_;
  bool retrigger_;
  State state_;
  uint32_t start_ms_;
};