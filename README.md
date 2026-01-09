# GPIOUtils

**GPIOUtils** is a small, focused Arduino utility library for cleaning up common
GPIO annoyances: noise, bounce, jitter, awkward timing logic, and state handling.

It is intentionally **not a framework**.
Each component does *one thing*, is easy to reason about, and composes cleanly
with the others.

📘 **Examples and usage:**  
See the full examples index here → [examples/README.md](examples/README.md)

---

## [Design philosophy](DESIGN.md)

### 1. Constructors do not touch hardware
All hardware configuration happens in `begin()`, never in constructors.
This allows:
- safe global/static instantiation
- predictable initialization order
- no hidden side effects

### 2. GPIO ownership implies `begin()`
If a class **owns a GPIO pin**, it:
- takes the pin in the constructor
- performs `pinMode()` in `begin()`

If a class does **not** touch GPIO, it never calls `pinMode()`.

### 3. Composition over specialization
Instead of large monolithic helpers, GPIOUtils provides small orthogonal
building blocks meant to be chained:

```
GPIO → conditioner → event/value → timing/state → output
```

Higher-level behaviors are deliberately documented rather than encoded
as extra classes.

---

## Library structure

```
GPIOUtils/
  src/
    GPIOUtils.h          // the only public header
    impl/                // internal headers and sources
  examples/
    README.md            // example index (recommended starting point)
```

Users should **only include**:

```cpp
#include <GPIOUtils.h>
```

---

## Components

GPIOUtils provides small, focused building blocks for common GPIO-related patterns.  
Most components are **logic-only** and do not own pins unless explicitly stated.

---

### Analog input utilities

- **AnalogCalibrator**  
  Normalizes ADC readings when real-world inputs do not reach the rails (0 or full scale).

- **Dejitter**  
  Suppresses small analog noise using a configurable deadband.

- **Schmitt**  
  Applies hysteresis to convert noisy analog signals into stable digital decisions.

---

### Digital input utilities

- **Debounce**  
  Filters mechanical switch bounce and provides clean edge events.

- **EdgeDetector**  
  Detects rising and falling edges on a clean digital signal.

- **GlitchFilter**  
  Rejects short, spurious pulses by requiring a minimum stable duration.

---

### Event and value utilities (logic only)

- **OneShotEvent**  
  Generates a fixed-duration logical event when triggered.

- **PulseGenerator**  
  Produces finite or continuous pulse trains with configurable on/off timing.

- **AutoRepeat**  
  Emits repeated events while an input remains active (keyboard-style repeat).

- **MultiPress**  
  Detects single, double, or multi-press gestures after a quiet interval.

- **LongPressDetector**  
  Detects press-and-hold gestures exceeding a specified duration.

- **Toggle**  
  Maintains a toggled state driven by discrete events.

- **RateLimiter**  
  Limits how fast a value may change over time (slew-rate control).

- **PeriodicTimer**  
  Generates periodic “tick” events at a fixed interval.

---

### Digital output utilities

- **TimedOutput**  
  Owns a GPIO output pin and supports scheduled pulses and timed state changes.

---

### Inline helper functions

Convenience functions for converting raw ADC readings into normalized or scaled values.


- `adcToU8()` — ADC → 8-bit conversion with rounding
- `adcToFloat()` — ADC → normalized float
- `adcToFloat(min, max)` — ADC → arbitrary float range

---

## Summary

GPIOUtils provides:
- small, predictable components
- explicit hardware ownership
- no hidden side effects
- clean composition instead of feature bloat

It is designed to quietly remove the small irritations that otherwise clutter
embedded GPIO code.

GPIOUtils is architecture-agnostic and uses only standard Arduino core APIs.
Behaviour may vary slightly depending on timing resolution and ADC characteristics of the target board.
