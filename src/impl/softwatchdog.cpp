#include "softwatchdog.h"

SoftWatchdog::SoftWatchdog(uint32_t timeoutMs)
: timeoutMs_(timeoutMs), lastKickMs_(millis())
{
}

void SoftWatchdog::setTimeout(uint32_t timeoutMs) {
  timeoutMs_ = timeoutMs;
}

void SoftWatchdog::kick() {
  lastKickMs_ = millis();
}

bool SoftWatchdog::expired() const {
  return static_cast<uint32_t>(millis() - lastKickMs_) >= timeoutMs_;
}

uint32_t SoftWatchdog::ageMs() const {
  return static_cast<uint32_t>(millis() - lastKickMs_);
}

uint32_t SoftWatchdog::timeoutMs() const {
  return timeoutMs_;
}
