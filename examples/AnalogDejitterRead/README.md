# examples/AnalogDejitterRead/README.md
# AnalogDejitterRead

## Introduction

Demonstrates `Dejitter` as a simple way to remove tiny analog “flicker” from a potentiometer (or other analog source) by applying a deadband.

---

## Behaviour

- Reads the analog input on `A0` through a `Dejitter` filter.
- Prints the filtered value to the Serial Monitor.
- Updates about every 20 ms.

---

## Wiring

- Analog source:
  - Pot wiper (or sensor output) → `A0`
  - Ensure the pot ends are at `5V` and `GND` (if using a pot)
- Serial Monitor: `115200` baud

---

## Key points illustrated

- Deadband-style smoothing: ignore small changes that are likely noise.
- Keeping the output steady when the knob is “not really moving”.
- Using Serial output to visually verify filtering.

---

## Why this example exists

When you map a pot directly to something visible (PWM brightness, motor speed, UI), small ADC noise can create jittery output. This example gives a minimal, easy-to-understand baseline for “make it stop twitching.”
