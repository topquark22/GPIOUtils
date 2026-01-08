#include "softwatchdog.h"

SoftWatchdog::SoftWatchdog(uint32_t timeoutMs)
    : timeoutMs_(timeoutMs),
      lastKickMs_(0)
{
}

void SoftWatchdog::setTimeout(uint32_t timeoutMs)
{
  timeoutMs_ = timeoutMs;
}

void SoftWatchdog::begin()
{
  lastKickMs_ = millis();
}

void SoftWatchdog::kick()
{
  lastKickMs_ = millis();
}

uint32_t SoftWatchdog::ageMs() const
{
  return millis() - lastKickMs_;
}

bool SoftWatchdog::expired() const
{
  return ageMs() >= timeoutMs_;
}
