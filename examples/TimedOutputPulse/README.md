# TimedOutputPulse

This example demonstrates **GPIOUtils::TimedOutput**, a non-blocking timed
digital output.

---

## What problem this solves

Turning an output on for a fixed time without blocking code execution.

`TimedOutput` allows pulsing outputs without `delay()`.

---

## Hardware setup

- LED connected to **pin 5**

---

## Sketch behavior

- Triggers a timed pulse
- LED turns off automatically after the duration

---

## Notes

- `read()` must be called regularly to update timing.
- Supports active-high and active-low outputs.

---

Part of the **GPIOUtils** Arduino utility library.
