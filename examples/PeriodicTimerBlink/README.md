# examples/PeriodicTimerBlink/README.md
# PeriodicTimerBlink

## Introduction

Demonstrates `PeriodicTimer`, a simple periodic tick source. This example uses it to blink the built-in LED at a steady rate without `delay()`.

---

## Behaviour

- After reset, the built-in LED toggles every `PERIOD_MS` (500 ms).
- The blink runs continuously.

---

## Wiring

- No external wiring required (uses `LED_BUILTIN`).

---

## Key points illustrated

- Periodic timing using `tick()` instead of delay loops.
- Writing a responsive `loop()` that keeps running freely.
- Using a timer as a “clock” that triggers work at fixed intervals.

---

## Why this example exists

The `delay()`-based blink is the first thing people learn, but it blocks everything else. This example shows the minimal non-blocking equivalent: a periodic timer that scales to real sketches.
