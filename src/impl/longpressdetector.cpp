#include "longpressdetector.h"

LongPressDetector::LongPressDetector(uint32_t longpress_ms)
: longpress_ms_(longpress_ms),
  pressed_(false),
  long_pressed_state_(false),
  long_pressed_event_(false),
  press_start_ms_(0)
{
}

void LongPressDetector::reset()
{
  pressed_ = false;
  long_pressed_state_ = false;
  long_pressed_event_ = false;
  press_start_ms_ = millis();
}

bool LongPressDetector::update(bool pressed)
{
  long_pressed_event_ = false;
  const uint32_t now = millis();

  if (pressed) {
    if (!pressed_) {
      // new press
      pressed_ = true;
      long_pressed_state_ = false;
      press_start_ms_ = now;
      return true;
    }

    if (!long_pressed_state_ && (now - press_start_ms_) >= longpress_ms_) {
      long_pressed_state_ = true;
      long_pressed_event_ = true;
    }
    return true;
  }

  // released
  pressed_ = false;
  long_pressed_state_ = false;
  return false;
}
