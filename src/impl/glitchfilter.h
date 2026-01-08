#pragma once
#include <Arduino.h>

#ifndef GPIOUTILS_PUBLIC_INCLUDE
#warning "Include <gpioutils.h> instead of including impl/* directly."
#endif

/**
 * @brief Rejects short glitches on a digital input by requiring a candidate state
 *        to persist for a minimum time before accepting it.
 *
 * This is similar to debouncing, but is intended for electrical glitches
 * (brief spikes) rather than mechanical bounce patterns.
 */
class GlitchFilter {
public:
  GlitchFilter(uint8_t pin, uint8_t mode, uint32_t min_stable_ms);
  GlitchFilter(uint8_t pin, uint32_t min_stable_ms); // convenience: INPUT

  void begin();

  // Call frequently. Returns filtered stable state.
  bool read();

  bool stable() const { return stable_; }
  bool raw() const { return raw_; }

  bool changed() const { return changed_; }
  bool rose() const { return rose_; }
  bool fell() const { return fell_; }

  void set_min_stable_ms(uint32_t ms) { min_stable_ms_ = ms; }
  uint32_t min_stable_ms() const { return min_stable_ms_; }

private:
  uint8_t pin_;
  uint8_t mode_;
  uint32_t min_stable_ms_;

  bool stable_;
  bool raw_;
  bool candidate_;
  uint32_t candidate_since_ms_;

  bool changed_;
  bool rose_;
  bool fell_;
};
