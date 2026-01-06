# RateLimiterRampPWM

This example demonstrates **GPIOUtils::RateLimiter** for smooth PWM transitions.

---

## What problem this solves

Sudden value changes can cause harsh transitions.

`RateLimiter` limits how fast values change over time.

---

## Hardware setup

- Potentiometer → **A0**
- LED (PWM capable pin)

---

## Sketch behavior

- Pot sets target brightness
- LED brightness ramps smoothly

---

## Notes

This is **not averaging**; steps are preserved but spread over time.

---

Part of the **GPIOUtils** Arduino utility library.
