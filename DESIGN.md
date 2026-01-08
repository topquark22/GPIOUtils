# GPIOUtils Design Paradigm

GPIOUtils is a toolbox of small, predictable building blocks for Arduino GPIO work.

## Core rules

### 1) No stateless classes
If something has no persistent state and no timing/history, it should not be a class.

### 2) Pure math helpers are local and private (Pattern A)
Pure math helpers (e.g., clamp/map/deadband/scale) live **only** inside the `.cpp` file of the feature that uses them:

- implemented as `inline` functions inside an anonymous `namespace { ... }`
- not declared in headers
- not exported as public API

This keeps headers focused on behavior and prevents the library from accumulating a “math utilities” dumping ground.

### 3) Anything stateful or time-based gets a normal `.h/.cpp`
If a component remembers anything (previous value, latched state, timers, counters, hysteresis, cadence, etc.), it earns:

- a class
- a header with declarations
- a `.cpp` with definitions

No “include-only” `.cpp` files.

## Rationale
- Locality: helpers live beside the feature they support.
- Predictability: public headers show what users can rely on.
- Build hygiene: no fake translation units; no accidental API surface area.
