# examples/PulseGeneratorBlink/README.md
# PulseGeneratorBlink

## Introduction

Demonstrates `PulseGenerator` as a reusable blink-pattern generator, triggered by a debounced button press. Unlike a simple toggle, this generates a timed pulse train (a short burst of blinks).

---

## Behaviour

- LED is normally OFF.
- On each button press:
  - If the pulse generator is idle, it triggers a burst of `NUM_BLINKS` blinks (default: 3).
  - Blink period is `BLINK_PERIOD_MS` (default: 500 ms, full on+off cycle).
- Additional presses while the burst is running are ignored (because of the `active()` guard).

---

## Wiring

- Button:
  - Between `D2` (`BUTTON_PIN`) and `GND`
  - Uses `INPUT_PULLUP` via `Debounce`
- LED:
  - LED anode → `D5` (`LED_PIN`) through a resistor
  - LED cathode → `GND`
  - Configured as active-HIGH (`true` in the constructor)

---

## Key points illustrated

- Using `Debounce` for a clean “press” event (`fell()`).
- Triggered pulse trains: `trigger(n)` produces a finite number of cycles.
- Non-blocking periodic output: call `update()` frequently; no delays required.
- Optional “busy” behavior: `active()` can be used to ignore retriggers.

---

## Why this example exists

A lot of UI feedback is “blink N times” (status, error codes, acknowledgment) rather than “toggle”. People often implement this with blocking loops and delays. This example shows a clean event-driven approach that stays responsive.
