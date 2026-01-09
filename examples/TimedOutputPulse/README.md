# examples/TimedOutputPulse/README.md
# TimedOutputPulse

## Introduction

Demonstrates `TimedOutput`, a helper that owns a GPIO output pin and supports timed pulses. This sketch shows a repeated pulse pattern (with delays mainly for demonstration clarity).

---

## Behaviour

- Pulses the LED ON for about 500 ms using `led.pulse(500)`.
- Waits until the output has actually turned OFF again (by polling `led.read()`).
- Then waits ~1500 ms and repeats.

---

## Wiring

- LED:
  - LED anode → `D5` through a resistor
  - LED cathode → `GND`

---

## Key points illustrated

- `TimedOutput` owns the output pin and its state.
- `pulse(duration_ms)` schedules an ON window without manual timers.
- `read()` both returns current output state and services the timing.

---

## Why this example exists

Timed pulses show up everywhere (beeps, indicator flashes, actuators). People often hand-roll timing logic around a pin. This example shows the “own the pin, schedule pulses” model in its simplest form.
