# examples/PulseStretcherButtonToLED/README.md
# PulseStretcherButtonToLED

## Introduction

Demonstrates a “pulse stretcher” built by composition: `Debounce → OneShotEvent → TimedOutput`. A brief button press becomes a guaranteed-visible LED pulse of fixed duration.

---

## Behaviour

- LED is normally OFF.
- Each clean button press triggers a one-shot lasting `PULSE_MS` (150 ms).
- While the one-shot is active, the LED is ON; afterwards it turns OFF.
- No `delay()` is required; the loop remains responsive.

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

- Building behavior from small parts instead of a monolithic class.
- Debounced edge triggers (`fell()`) driving a one-shot.
- `TimedOutput` handling the LED pin I/O while preserving timing guarantees.

---

## Why this example exists

Some input events are too short to see (or to reliably catch in a human-visible way). A pulse stretcher is the standard fix: “any press, even a tap, becomes a clean, fixed-length output pulse.”
