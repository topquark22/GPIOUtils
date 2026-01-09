# examples/MultiPressBasic/README.md
# MultiPressBasic

## Introduction

Demonstrates `MultiPress` for counting quick successive button presses (single / double / triple, etc.), then acting on the final count. It also uses `OneShotEvent` to generate a fixed-duration LED pulse after a recognized pattern.

---

## Behaviour

- Button on `D2` is pressed multiple times.
- `MultiPress` waits for a “quiet gap” after the last press, then reports the total count once.
- If the count is exactly **2** (double-press):
  - the LED on `D5` turns ON for about `1500 ms`, then turns OFF.

---

## Wiring

- Button:
  - Between `D2` (`BUTTON_PIN`) and `GND`
  - (As written, `MultiPress` is configured with timing parameters and assumes pull-up style wiring.)
- LED:
  - LED anode → `D5` (`LED_PIN`) through a resistor
  - LED cathode → `GND`

---

## Key points illustrated

- Multi-press gesture recognition (count presses, then “commit” once).
- “Final gap” concept: don’t decide until the user stops pressing.
- Driving an output using a logical one-shot (`OneShotEvent`) rather than delay loops.

---

## Why this example exists

Double-click / double-press style interactions show up everywhere, and the usual DIY implementations are fragile (timing edge cases, repeated triggers, blocking delays). This example provides a reliable baseline pattern you can adapt to “1 press = X, 2 presses = Y, 3 presses = Z.”
