# examples/AnalogIntegratorBasic/README.md
# AnalogIntegratorBasic

## Introduction

Demonstrates `AnalogIntegrator`, which integrates a normalized analog signal over time. It’s useful when you want “accumulated amount” (area under the curve) rather than instant readings.

---

## Behaviour

- Reads a potentiometer on `A0`.
- Converts ADC to a normalized `x` in the range 0..1.
- Continuously integrates `x` over time and prints:
  - `x` (current normalized value)
  - `integral` (“seconds at full scale”)
- Prints about every 250 ms.

---

## Wiring

- Potentiometer:
  - One outer terminal → `5V`
  - Other outer terminal → `GND`
  - Wiper → `A0` (`PIN_A`)
- Serial Monitor: `115200` baud

---

## Key points illustrated

- Integrating a signal vs. just sampling it.
- Normalizing ADC values before integration (0..1 is a convenient domain).
- Overflow-safe time handling using `millis()` deltas.

---

## Why this example exists

A lot of real problems are “how long / how much” rather than “what is it right now” (energy use, dose, exposure, duty time). This example shows how to accumulate an analog input cleanly without ad-hoc timing math scattered through your sketch.
