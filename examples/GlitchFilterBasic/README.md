# examples/GlitchFilterBasic/README.md
# GlitchFilterBasic

## Introduction

Demonstrates `GlitchFilter`, which rejects pulses shorter than a specified minimum stable time. This is useful for noisy digital lines or signals with occasional spikes.

---

## Behaviour

- Reads an active-LOW button on `D2` through a glitch filter.
- Any pulse shorter than `MIN_STABLE_MS` is ignored.
- Each accepted button press toggles an LED on `D5`.

---

## Wiring

- Button:
  - One side → `GND`
  - Other side → `D2` (`BUTTON_PIN`)
  - Pin uses `INPUT_PULLUP`
- LED:
  - LED anode → `D5` (`LED_PIN`) through a resistor
  - LED cathode → `GND`

---

## Key points illustrated

- Filtering glitches by minimum stable duration, not just “debounce time.”
- Cleaning a line that may have brief spikes even when not a mechanical switch.
- Using edge events (`fell()`) after filtering.

---

## Why this example exists

Not all noise looks like switch bounce. Sometimes you get narrow spikes that should be ignored entirely. This example shows a blunt, effective technique: “only accept changes that stay changed long enough.”
