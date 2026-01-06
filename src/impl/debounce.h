#pragma once
#include <Arduino.h>

class Debounce {
public:
  Debounce(uint8_t pin, uint8_t mode, uint32_t debounce_ms);
  Debounce(uint8_t pin, uint32_t debounce_ms); // convenience: INPUT

  void begin();

  // Call frequently (e.g., each loop). Returns debounced stable state.
  bool read();

  bool stable() const { return stable_; }
  bool raw() const { return raw_; }

  bool changed() const { return changed_; }
  bool rose() const { return rose_; }
  bool fell() const { return fell_; }

private:
  uint8_t pin_;
  uint8_t mode_;
  uint32_t debounce_ms_;

  bool stable_;
  bool raw_;
  bool last_raw_;

  uint32_t last_change_ms_;

  bool changed_;
  bool rose_;
  bool fell_;
};
