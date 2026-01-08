#include "toggle.h"

Toggle::Toggle(bool initial_state)
: state_(initial_state),
  toggled_(false)
{
}

void Toggle::begin() {
  // symmetry only
}

bool Toggle::set(bool new_state) {
  if (state_ != new_state) {
    state_ = new_state;
    toggled_ = true;
    return true;
  }
  return false;
}

void Toggle::trigger() {
  state_ = !state_;
  toggled_ = true;
}

bool Toggle::read() {
  toggled_ = false;
  return state_;
}

bool Toggle::state() const {
  return state_;
}

bool Toggle::toggled() const {
  return toggled_;
}
