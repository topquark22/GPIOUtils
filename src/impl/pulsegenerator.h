#pragma once
#include <Arduino.h>

#ifndef GPIOUTILS_PUBLIC_INCLUDE
#warning "Include <GPIOUtils.h> instead of including impl/* directly."
#endif

/**
 * @brief Non-blocking square-wave / blink pattern generator.
 *
 * This class does NOT own a GPIO pin. Call update() frequently and then
 * drive an output pin with state().
 *
 * Usage:
 *   PulseGenerator pg(200, 800); // 200 ms ON, 800 ms OFF
 *   ...
 *   pg.update();
 *   digitalWrite(LED_BUILTIN, pg.state());
 */
class PulseGenerator {
public:
  PulseGenerator(uint32_t on_ms, uint32_t off_ms, bool start_high = true);

  void set_periods(uint32_t on_ms, uint32_t off_ms);
  void start(bool start_high = true);
  void stop(bool output_low = true);

  /**
   * @brief Update timing and edge flags. Call frequently from loop().
   */
  void update();

  bool running() const { return running_; }
  bool state() const { return state_; }

  bool changed() const { return changed_; }
  bool rose() const { return rose_; }
  bool fell() const { return fell_; }

private:
  uint32_t on_ms_;
  uint32_t off_ms_;

  bool running_{true};
  bool state_{true}; // high=ON
  uint32_t next_toggle_ms_{0};

  bool changed_{false};
  bool rose_{false};
  bool fell_{false};
};
