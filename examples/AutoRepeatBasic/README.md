# examples/AutoRepeatBasic/README.md
# AutoRepeatBasic

## Introduction

Demonstrates `AutoRepeat`, a “keyboard-style” repeat generator, paired with `Debounce` for a clean button input. Useful for increment/decrement UI controls.

---

## Behaviour

- A button on pin `2` acts as an active-LOW input.
- When you hold the button:
  - waits ~500 ms (initial delay)
  - then “fires” repeatedly every ~150 ms
- Each repeat increments an integer `value` and prints it to Serial.

---

## Wiring

- Button:
  - One side → `GND`
  - Other side → `D2` (`PIN_BTN`)
  - Pin uses `INPUT_PULLUP` (no external resistor required)
- Serial Monitor: `115200` baud

---

## Key points illustrated

- Separating responsibilities:
  - `Debounce` produces a stable pressed/released signal
  - `AutoRepeat` turns “held” into a repeating event stream
- Active-LOW button convention with `INPUT_PULLUP`.
- Event-style usage: check `rep.fired()` rather than polling time manually.

---

## Why this example exists

People often implement hold-to-repeat using `delay()` loops or custom timers, which makes the rest of the sketch sluggish. This example shows a reusable, non-blocking pattern for responsive user controls.
