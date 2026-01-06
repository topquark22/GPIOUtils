#include "timedoutput.h"

TimedOutput::TimedOutput(uint8_t pin,
                         uint8_t mode,
                         bool active_high,
                         bool retrigger)
: pin_(pin),
  mode_(mode),
  active_high_(active_high),
  retrigger_(retrigger),
  logical_on_(false),
  pulsing_(false),
  start_ms_(0),
  duration_ms_(0)
{
}

void TimedOutput::begin() {
  pinMode(pin_, mode_);
  off(); // ensures pin is driven to the OFF level
}

void TimedOutput::write_(bool logical_on) {
  logical_on_ = logical_on;

  const uint8_t level =
    (logical_on_ == active_high_) ? HIGH : LOW;

  digitalWrite(pin_, level);
}

bool TimedOutput::read() {
  if (pulsing_) {
    const uint32_t now = millis();
    if ((now - start_ms_) >= duration_ms_) {
      pulsing_ = false;
      write_(false); // auto-off
    }
  }
  return logical_on_;
}

void TimedOutput::on() {
  pulsing_ = false;
  write_(true);
}

void TimedOutput::off() {
  pulsing_ = false;
  write_(false);
}

void TimedOutput::pulse(uint32_t duration_ms) {
  const uint32_t now = millis();

  if (!pulsing_) {
    pulsing_ = true;
    duration_ms_ = duration_ms;
    start_ms_ = now;
    write_(true);
    return;
  }

  // Already pulsing
  if (retrigger_) {
    duration_ms_ = duration_ms;
    start_ms_ = now;
    write_(true); // keep ON
  }
}
