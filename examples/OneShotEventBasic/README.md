# examples/OneShotEventBasic/README.md
# OneShotEventBasic

## Introduction

Demonstrates `OneShotEvent` as a purely logical one-shot timer (it does not own GPIO). The trigger in this example is Serial input to emphasize that it can be driven by any event source.

---

## Behaviour

- Open the Serial Monitor at `115200` baud.
- Press any key (send any character):
  - prints `Triggered`
  - one-shot becomes ACTIVE for about `500 ms`
- While active, the sketch prints `One-shot ACTIVE` repeatedly (as fast as the loop runs).

---

## Wiring

- No external wiring required.
- Serial Monitor: `115200` baud

---

## Key points illustrated

- One-shot timers can be used without tying them to a pin.
- Triggering from non-GPIO events (Serial, network, timers, state machines, etc.).
- The one-shot manages time internally; you just call `trigger()` and `read()`.

---

## Why this example exists

Many sketches bake timing into ad-hoc state variables. A reusable one-shot simplifies “make a condition true for N milliseconds after an event,” regardless of where the event comes from.
