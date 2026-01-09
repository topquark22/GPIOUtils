#include "pulsegenerator.h"

PulseGenerator::PulseGenerator(
    uint8_t pin,
    unsigned long period_ms,
    bool active_high)
    : pin_(pin),
      period_ms_(period_ms),
      active_high_(active_high) {}

void PulseGenerator::begin()
{
  pinMode(pin_, OUTPUT);
  set_output_(false);
  running_ = false;
}

void PulseGenerator::trigger(int32_t num_cycles)
{
  if (num_cycles == 0)
  {
    return;
  }

  remaining_cycles_ = num_cycles;
  running_ = true;
  output_on_ = false;
  last_toggle_ms_ = millis();
}

void PulseGenerator::stop()
{
  running_ = false;
  set_output_(false);
}

bool PulseGenerator::active() const
{
  return running_;
}

void PulseGenerator::update()
{
  if (!running_)
  {
    return;
  }

  unsigned long now = millis();

  if (now - last_toggle_ms_ < period_ms_ / 2)
  {
    return;
  }

  last_toggle_ms_ = now;

  // Toggle output
  output_on_ = !output_on_;
  set_output_(output_on_);

  // Count pulse when we transition OFF
  if (!output_on_)
  {
    if (remaining_cycles_ > 0)
    {
      remaining_cycles_--;
      if (remaining_cycles_ == 0)
      {
        stop();
      }
    }
  }
}

void PulseGenerator::set_output_(bool on)
{
  bool level = on ? active_high_ : !active_high_;
  digitalWrite(pin_, level ? HIGH : LOW);
}
