# GPIOUtils – Design Principles

GPIOUtils is a small collection of focused utility classes for writing **responsive, non-blocking Arduino sketches**.  
The library is intentionally opinionated. Its APIs reflect a set of design rules that aim to make timing, input handling, and GPIO behavior **predictable, composable, and easy to reason about**.

This document explains those principles.

---

## 1. Non-blocking by default

GPIOUtils avoids `delay()` and other blocking constructs.

Time-based behavior is expressed as:
- elapsed-time comparisons using `millis()` or `micros()`
- state machines advanced incrementally

Every class is designed so that:
- `loop()` continues to run freely
- multiple behaviors can coexist without interfering with each other

If something takes time, it is modeled as **state over time**, not a pause.

---

## 2. Logic is separated from GPIO

Many classes in GPIOUtils are **pure logic**:
- they do not own pins
- they do not call `digitalWrite()` internally
- they produce states, events, or timing signals

Examples:
- `PulseGenerator`
- `OneShotEvent`
- `PeriodicTimer`
- `RateLimiter`

Other classes **explicitly own GPIO** and say so in their name or role:
- `TimedOutput`
- simple LED or pin-driving examples

This separation allows:
- reuse of logic with different outputs
- testing via Serial or mock inputs
- composition without hidden side effects

If a class touches hardware, it is obvious.

---

## 3. Time is always handled safely

All time comparisons are done using **delta arithmetic**, not absolute comparisons.

The canonical pattern is:

```cpp
if ((uint32_t)(now - last) >= interval)
