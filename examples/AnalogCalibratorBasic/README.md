# examples/AnalogCalibratorBasic/README.md
# AnalogCalibratorBasic

## Introduction

Demonstrates `AnalogCalibrator`, a small helper for dealing with real-world analog inputs that don’t actually reach the ADC rails (0 and 1023). It shows how to normalize and remap raw ADC readings into useful ranges.

---

## Behaviour

- Continuously reads a potentiometer on `A0`.
- Prints three derived values to the Serial Monitor:
  - `raw` (the ADC reading)
  - `u` (a normalized 0..1 value after calibration)
  - `pwm` (a mapped integer 0..255)
  - `deg` (a mapped float 0..270)
- Output updates roughly every 50 ms (for readability).

---

## Wiring

- Potentiometer:
  - One outer terminal → `5V`
  - Other outer terminal → `GND`
  - Wiper (middle) → `A0` (`PIN_POT`)
- Serial Monitor: `115200` baud

---

## Key points illustrated

- Real analog sensors/pots often have a “dead zone” near the ends.
- Converting raw ADC values into:
  - normalized 0..1
  - integer ranges (e.g. PWM)
  - float ranges (e.g. degrees)
- Keeping calibration parameters explicit (min/max observed).

---

## Why this example exists

Beginners often assume `analogRead()` naturally spans the full range. In practice, mechanical pots and sensors frequently miss the rails. This example shows a clean way to compensate, so your UI or control logic can still behave as if it reaches 0% and 100%.
