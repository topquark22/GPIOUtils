# GPIOUtils Examples

This directory contains small, focused Arduino sketches demonstrating how to use
the components in **GPIOUtils** and how to **compose** them into useful behaviors.

All examples include:
- a self-contained `.ino` sketch
- a per-example `README.md` explaining the problem being solved

All sketches include the umbrella header:

```cpp
#include <gpioutils.h>
```

---

## Index of examples

### Analog input examples

#### DejitterBasic
Suppresses small ADC flicker using a deadband.

- 📄 [README](DejitterBasic/README.md)
- 🧪 Sketch: `DejitterBasic/DejitterBasic.ino`

---

#### AnalogDejitterRead
Compares raw ADC readings with dejittered output.

- 📄 [README](AnalogDejitterRead/README.md)
- 🧪 Sketch: `AnalogDejitterRead/AnalogDejitterRead.ino`

---

#### SchmittAnalogThreshold
Converts an analog input into a stable boolean using hysteresis.

- 📄 [README](SchmittAnalogThreshold/README.md)
- 🧪 Sketch: `SchmittAnalogThreshold/SchmittAnalogThreshold.ino`

---

#### RateLimiterRampPWM
Smoothly ramps PWM output using a slew limiter.

- 📄 [README](RateLimiterRampPWM/README.md)
- 🧪 Sketch: `RateLimiterRampPWM/RateLimiterRampPWM.ino`

---

## Digital input examples

#### DebounceBasic
Debounces a mechanical pushbutton and generates clean press events.

- 📄 [README](DebounceBasic/README.md)
- 🧪 Sketch: `DebounceBasic/DebounceBasic.ino`

---

#### EdgeDetectorBasic
Detects rising and falling edges on a clean digital signal.

- 📄 [README](EdgeDetectorBasic/README.md)
- 🧪 Sketch: `EdgeDetectorBasic/EdgeDetectorBasic.ino`

---

## Event and timing examples

#### OneShotEventBasic
Demonstrates an event-driven one-shot (monostable) without GPIO ownership.

- 📄 [README](OneShotEventBasic/README.md)
- 🧪 Sketch: `OneShotEventBasic/OneShotEventBasic.ino`

---

#### TimedOutputPulse
Pulses a digital output for a fixed duration without `delay()`.

- 📄 [README](TimedOutputPulse/README.md)
- 🧪 Sketch: `TimedOutputPulse/TimedOutputPulse.ino`

---

## Composition examples (recommended patterns)

#### PulseStretcherButtonToLED
Implements a pulse stretcher using composition:

```
Debounce → OneShotEvent → TimedOutput
```

- 📄 [README](PulseStretcherButtonToLED/README.md)
- 🧪 Sketch: `PulseStretcherButtonToLED/PulseStretcherButtonToLED.ino`

---

#### ToggleOnPress
Implements press-to-toggle behavior using:

```
Debounce → Toggle
```

- 📄 [README](ToggleOnPress/README.md)
- 🧪 Sketch: `ToggleOnPress/ToggleOnPress.ino`

---

## Notes

- All GPIO-owning classes require `begin()` to configure hardware.
- Event/value utilities (`OneShotEvent`, `Toggle`, `RateLimiter`) do not touch GPIO.
- All examples avoid `delay()` except where explicitly used for Serial readability.

These examples are meant to be read, modified, and combined.
They illustrate the **composition-first philosophy** of GPIOUtils.

---

Part of the **GPIOUtils** Arduino utility library.
