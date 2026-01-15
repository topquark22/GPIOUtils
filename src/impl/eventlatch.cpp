#include "EventLatch.h"

namespace gpioutils {

void EventLatch::begin()
{
  state_ = false;
}

void EventLatch::begin(bool startHigh)
{
  state_ = startHigh;
}

void EventLatch::trigger()
{
  state_ = true;
}

bool EventLatch::read()
{
  const bool was_set = state_;
  state_ = false;
  return was_set;
}

bool EventLatch::peek() const
{
  return state_;
}

void EventLatch::clear()
{
  state_ = false;
}

} // namespace gpioutils
