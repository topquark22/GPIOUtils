# examples/LongPressDetectorBasic/README.md
# LongPressDetectorBasic

## Introduction

Demonstrates `LongPressDetector` for detecting a “press-and-hold” gesture, using `Debounce` to provide a clean pressed signal.

---

## Behaviour

- Button is active-LOW on `D2`.
- If the button is held continuously for about `LONGPRESS_MS` (800 ms):
  - the LED toggles once.
- Short presses do nothing.

---

## Wiring

- Button:
  - Between `D2` (`BUTTON_PIN`) and `GND`
  - Uses `INPUT_PULLUP`
- LED:
  - LED anode → `D5` (`LED_PIN`) through a resistor
  - LED cathode → `GND`

---

## Key points illustrated

- Combining `Debounce` (clean input) with `LongPressDetector` (gesture).
- “Pressed” logic inversion when using pull-ups (`pressed = !stable`).
- Triggering an action only when a timing condition is met.

---

## Why this example exists

A long-press is a common UI gesture, but it’s easy to implement in a way that retriggers repeatedly, or triggers too early because of bounce. This example shows the clean separation: debounce first, then gesture detection.
