# GPIOUtils

**GPIOUtils** is a small, focused Arduino utility library for cleaning up common
GPIO annoyances: noise, bounce, jitter, awkward timing logic, and state handling.

It is intentionally **not a framework**.
Each component does *one thing*, is easy to reason about, and composes cleanly
with the others.

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
```

Users should **only include**:

```cpp
#include <gpioutils.h>
```

All headers under `impl/` are considered private.

---

## Components

### Analog input utilities

#### Dejitter
Suppresses tiny ADC fluctuations by holding the last stable value until the
input changes by more than a configurable deadband.

- Owns an analog pin
- Stateful
- Uses `begin()`

```cpp
Dejitter pot(A0, 1);

void setup() {
  pot.begin();
}

void loop() {
  int v = pot.read();
}
```

---

#### Schmitt
Analog Schmitt trigger with hysteresis. Returns a boolean output with clean
transitions.

- Owns an analog pin
- Configurable hysteresis
- Uses `begin()`

```cpp
Schmitt level(A0, 480, 540);

void setup() {
  level.begin();
}

void loop() {
  if (level.read()) {
    // signal is high
  }
}
```

---

### Digital input utilities

#### Debounce
Debounces a digital input (buttons, switches).

- Owns a digital pin
- Time-based debounce
- Provides edge events (`rose()`, `fell()`)

```cpp
Debounce btn(2, INPUT_PULLUP, 25);

void setup() {
  btn.begin();
}

void loop() {
  btn.read();
  if (btn.fell()) {
    // button pressed (active-low)
  }
}
```

---

#### EdgeDetector
Detects rising and falling edges on a digital input **without debouncing**.

- Owns a digital pin
- No time filtering

```cpp
EdgeDetector ed(3, INPUT);

void setup() {
  ed.begin();
}

void loop() {
  ed.read();
  if (ed.rose()) {
    // rising edge
  }
}
```

---

### Event- and value-driven utilities (no GPIO ownership)

These classes do **not** read or write pins.
They operate on events or values and compose with the GPIO-owning components.

---

#### OneShotEvent
Event-driven one-shot (monostable).

- Triggered explicitly by an event
- Output stays true for a fixed duration
- Non-blocking

```cpp
OneShotEvent pulse(120);

void loop() {
  if (event) pulse.trigger();
  bool active = pulse.read();
}
```

---

#### Toggle
Event-driven toggle latch.

- Each trigger flips the internal state
- Useful for press-to-toggle behavior

```cpp
Toggle latch;

void loop() {
  if (event) latch.trigger();
  bool on = latch.read();
}
```

---

#### RateLimiter
Limits how fast a value can change over time (slew limiter).

- Not an averaging filter
- Preserves steps but spreads them over time
- Uses `begin()` for time initialization

```cpp
RateLimiter lim(500.0f, 800.0f);

void setup() {
  lim.begin();
}

void loop() {
  float y = lim.read(target);
}
```

---

### Digital output utilities

#### TimedOutput
Non-blocking timed digital output.

- Owns an output pin
- Can be turned on/off
- Can be pulsed for a fixed duration
- Uses `begin()`

```cpp
TimedOutput led(13);

void setup() {
  led.begin();
}

void loop() {
  if (event) led.pulse(120);
  led.read();
}
```

Supports:
- active-high or active-low outputs
- retriggerable pulses

---

## Composition patterns (documented, not hard-coded)

Some common patterns are intentionally **not implemented as separate classes**
because they fall naturally out of composition.

### Pulse stretcher
```
Debounce → OneShotEvent → TimedOutput
```

### Toggle-on-press
```
Debounce → Toggle
```

### Smoothed analog control
```
analog pin → Dejitter → RateLimiter → PWM
```

### Thresholded analog event
```
analog pin → Schmitt → OneShotEvent
```

---

## Summary

GPIOUtils provides:
- small, predictable components
- explicit hardware ownership
- no hidden side effects
- clean composition instead of feature bloat

It is designed to quietly remove the small irritations that otherwise clutter
embedded GPIO code.

