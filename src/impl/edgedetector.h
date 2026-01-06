#pragma once
#include <Arduino.h>

#ifndef GPIOUTILS_PUBLIC_INCLUDE
#warning "Include <gpioutils.h> instead of including impl/* directly."
#endif

/**
 * @brief Edge detector for a digital GPIO input.
 *
 * Detects rising and falling edges without debouncing.
 * If you need bounce suppression, put Debounce in front of your logic instead.
 *
 * Usage:
 *   EdgeDetector ed(2, INPUT_PULLUP);
 *   void setup(){ ed.begin(); }
 *   void loop(){
 *     ed.read();
 *     if(ed.fell()) { ... } // active-low press
 *   }
 */
class EdgeDetector {
public:
  EdgeDetector(uint8_t pin, uint8_t mode);

  // Convenience constructor: INPUT
  explicit EdgeDetector(uint8_t pin);

  void begin();

  /**
   * @brief Sample the pin and update edge flags. Returns current logic level.
   */
  bool read();

  bool state() const { return state_; }

  bool changed() const { return changed_; }
  bool rose() const { return rose_; }
  bool fell() const { return fell_; }

private:
  uint8_t pin_;
  uint8_t mode_;

  bool state_;     // current logic level
  bool prev_;      // previous logic level

  bool changed_;
  bool rose_;
  bool fell_;
};
