# examples/EdgeDetectorBasic/README.md
# EdgeDetectorBasic

## Introduction

Demonstrates `EdgeDetector` for detecting clean rising and falling edges on a digital input (assumed already clean: no debounce here). It also shows using edges to drive an LED and log events.

---

## Behaviour

- Monitors an input pin (`PIN_IN = 3`) configured with `INPUT_PULLUP`.
- On a rising edge, prints `Rising edge` and turns the LED ON.
- On a falling edge, prints `Falling edge` and turns the LED OFF.

---

## Wiring

- Input source (button or signal):
  - If using a button: between `D3` (`PIN_IN`) and `GND`
  - Because `INPUT_PULLUP` is used, pressed = LOW, released = HIGH
- LED:
  - LED anode → `D5` (`PIN_LED`) through a resistor
  - LED cathode → `GND`
- Serial Monitor: `115200` baud

---

## Key points illustrated

- Edge detection without writing your own “previous state” logic.
- Separating edge events (`rose()`, `fell()`) from steady levels.
- When you do *not* need debounce (e.g., a clean digital signal).

---

## Why this example exists

A lot of embedded logic is event-driven (“on transition, do X”). People often re-implement edge detection repeatedly (and sometimes incorrectly). This example provides the simplest reference pattern for “tell me when it changed.”
