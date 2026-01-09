# examples/RateLimiterRampPWM/README.md
# RateLimiterRampPWM

## Introduction

Demonstrates `RateLimiter` for smoothing *how fast* a value is allowed to change (slew-rate limiting), using a potentiometer as the target and PWM LED brightness as the output. It also uses `Dejitter` to steady the input.

---

## Behaviour

- Pot on `A0` sets a target brightness (0..255).
- The output brightness ramps toward the target:
  - one rate for increasing
  - another rate for decreasing
- LED on `D5` updates continuously using `analogWrite()`.

---

## Wiring

- Potentiometer:
  - One outer terminal → `5V`
  - Other outer terminal → `GND`
  - Wiper → `A0` (`POT_PIN`)
- LED (PWM-capable pin recommended):
  - LED anode → `D5` (`LED_PIN`) through a resistor
  - LED cathode → `GND`

---

## Key points illustrated

- Slew-rate limiting: controlling *dY/dt*, not just filtering noise.
- Different rise/fall dynamics (often desirable in UI/controls).
- Combining input conditioning (`Dejitter`) with output conditioning (`RateLimiter`).

---

## Why this example exists

Low-pass filtering is not the same as “limit how fast something can move.” Rate limiting is the right tool for smoothing setpoints, brightness ramps, motor commands, etc., while still reaching the target quickly and predictably.
