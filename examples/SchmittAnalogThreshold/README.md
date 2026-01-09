# examples/SchmittAnalogThreshold/README.md
# SchmittAnalogThreshold

## Introduction

Demonstrates `Schmitt`, a hysteresis threshold for analog signals. It turns a noisy analog value into a stable digital HIGH/LOW decision with separate rising and falling thresholds.

---

## Behaviour

- Reads analog input on `A0`.
- Applies hysteresis thresholds (as constructed): low and high boundaries.
- Outputs the resulting boolean:
  - Drives LED on `D5`
  - Prints `HIGH` or `LOW` to Serial

---

## Wiring

- Analog source:
  - Pot wiper (or sensor output) → `A0`
  - If using a pot: ends to `5V` and `GND`
- LED:
  - LED anode → `D5` (`PIN_LED`) through a resistor
  - LED cathode → `GND`
- Serial Monitor: `115200` baud

---

## Key points illustrated

- Hysteresis prevents “chatter” around a single threshold.
- Turning analog signals into stable digital decisions.
- Observing the state both visually (LED) and textually (Serial).

---

## Why this example exists

If you compare an analog reading to a single threshold, noise can make it flip rapidly near the boundary. A Schmitt trigger is the standard fix. This example shows the embedded-software equivalent.
