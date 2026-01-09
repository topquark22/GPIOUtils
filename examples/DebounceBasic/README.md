# examples/DebounceBasic/README.md
# DebounceBasic

## Introduction

Demonstrates `Debounce` for clean pushbutton handling, using edge events (`fell()`) to toggle an LED.

---

## Behaviour

- LED starts in an undefined state (whatever the pin powers up as).
- Each physical button press toggles the LED state once.
- Button bounce is filtered so you don’t get multiple toggles per press.

---

## Wiring

- Button:
  - One side → `GND`
  - Other side → `D2` (`BUTTON_PIN`)
  - Pin uses `INPUT_PULLUP` (no external resistor required)
- LED:
  - LED anode → `D5` (`LED_PIN`) through a resistor (220–1kΩ)
  - LED cathode → `GND`

---

## Key points illustrated

- Debouncing with a configurable time (`DEBOUNCE_MS`).
- Using edge events (`fell()`) instead of level polling.
- Active-LOW button logic when using pull-ups.

---

## Why this example exists

Mechanical switches bounce. Without debouncing, “one press” often becomes many. This is the canonical minimal pattern for “do something once per press.”
