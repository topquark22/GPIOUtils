# examples/LatchBasic/README.md
# LatchBasic

## Introduction

Demonstrates a basic SET/RESET latch using two debounced buttons and the `Latch` class. This is the classic “two-button state memory” pattern.

---

## Behaviour

- Two buttons:
  - SET button sets the latch ON
  - RESET button sets the latch OFF
- LED on `D5` reflects the latch state:
  - ON when latched
  - OFF when reset

---

## Wiring

- SET button:
  - Between `D2` (`PIN_SET`) and `GND`
  - Uses `INPUT_PULLUP`
- RESET button:
  - Between `D3` (`PIN_RST`) and `GND`
  - Uses `INPUT_PULLUP`
- LED:
  - LED anode → `D5` (`PIN_LED`) through a resistor
  - LED cathode → `GND`

---

## Key points illustrated

- Two independent debounced inputs driving a single stable state.
- Using edge events (`fell()`) to change state exactly once per press.
- A latch as a simple “remembered mode” or “armed/disarmed” state.

---

## Why this example exists

People often build state machines for simple “set/reset” behaviour. A latch is a named, reusable abstraction. This example is a reference for the canonical wiring and logic.
