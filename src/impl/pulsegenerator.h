#pragma once

#include <Arduino.h>

class PulseGenerator
{
public:
  PulseGenerator(
      uint8_t pin,
      unsigned long period_ms,
      bool active_high = true);

  void begin();

  // Start generating pulses
  // num_cycles > 0 : finite number of pulses
  // num_cycles == -1 : infinite pulses
  void trigger(int32_t num_cycles = -1);

  void stop();

  void update();

  bool active() const;

private:
  void set_output_(bool on);

  uint8_t pin_;
  unsigned long period_ms_;
  bool active_high_;

  bool running_ = false;
  bool output_on_ = false;

  unsigned long last_toggle_ms_ = 0;

  int32_t remaining_cycles_ = 0; // -1 = infinite
};
