# examples/ToggleOnPress/README.md
# ToggleOnPress

## Introduction

Demonstrates a simple “toggle latch” driven by a debounced button press. This is the classic “press once for ON, press again for OFF” behavior.

---

## Behaviour

- Each button press toggles an internal latch state.
- LED on `D5` reflects the latch:
  - ON when latched
  - OFF when unlatched

---

## Wiring

- Button:
  - Between `D2` and `GND`
  - Uses `INPUT_PULLUP` (via `Debounce`)
- LED:
  - LED anode → `D5` (`LED_PIN`) through a resistor
  - LED cathode → `GND`

---

## Key points illustrated

- Debounced edge detection (`fell()`) as the trigger event.
- A toggle-style latch that remembers state between presses.
- Output driven directly from logical state (`latch.read()`).

---

## Why this example exists

Toggling modes is a basic UI primitive, but it’s often implemented with fragile “if pressed then invert” logic that retriggers on bounce. This example is the clean reference for “toggle once per press.”
