# GPIOUtils

**GPIOUtils** is a small, focused Arduino utility library for cleaning up common
GPIO annoyances: noise, bounce, jitter, awkward timing logic, and state handling.

It is intentionally **not a framework**.
Each component does *one thing*, is easy to reason about, and composes cleanly
with the others.

📘 **Examples and usage:**  
See the full examples index here → [examples/README.md](examples/README.md)

---

## Design philosophy

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
    gpioutils.h          // the only public header
    impl/                // internal headers and sources
  examples/
    README.md            // example index (recommended starting point)
```

Users should **only include**:

```cpp
#include <gpioutils.h>
```

---

## Components

### Analog input utilities

- **Dejitter** — suppresses small ADC flicker using a deadband
- **Schmitt** — analog Schmitt trigger with hysteresis

### Digital input utilities

- **Debounce** — debounced digital input with edge events
- **EdgeDetector** — edge detection without debouncing

### Event / value utilities (no GPIO ownership)

- **OneShotEvent** — event-driven monostable
- **Toggle** — event-driven toggle latch
- **RateLimiter** — slew limiter for values

### Digital output utilities

- **TimedOutput** — non-blocking timed digital output

---

## Inline helper functions

Available via `#include <gpioutils.h>`:

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

---

## License

(Insert your chosen license here.)
