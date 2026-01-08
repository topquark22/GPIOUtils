# GPIOUtils Examples

This directory contains small, focused Arduino sketches demonstrating how to use
the components in **GPIOUtils** and how to **compose** them into useful behaviors.

All sketches include the umbrella header:

```cpp
#include <gpioutils.h>
```

## Analog input examples

### AnalogCalibratorBasic
- 📄 [README](AnalogCalibratorBasic/README.md)
- 🧪 Sketch: `AnalogCalibratorBasic/AnalogCalibratorBasic.ino`

### AnalogDejitterRead
- 📄 [README](AnalogDejitterRead/README.md)
- 🧪 Sketch: `AnalogDejitterRead/AnalogDejitterRead.ino`

### DejitterBasic
- 📄 [README](DejitterBasic/README.md)
- 🧪 Sketch: `DejitterBasic/DejitterBasic.ino`

### SchmittAnalogThreshold
- 📄 [README](SchmittAnalogThreshold/README.md)
- 🧪 Sketch: `SchmittAnalogThreshold/SchmittAnalogThreshold.ino`

## Digital input examples

### DebounceBasic
- 📄 [README](DebounceBasic/README.md)
- 🧪 Sketch: `DebounceBasic/DebounceBasic.ino`

### EdgeDetectorBasic
- 📄 [README](EdgeDetectorBasic/README.md)
- 🧪 Sketch: `EdgeDetectorBasic/EdgeDetectorBasic.ino`

### GlitchFilterBasic
- 📄 [README](GlitchFilterBasic/README.md)
- 🧪 Sketch: `GlitchFilterBasic/GlitchFilterBasic.ino`

## Event / timing / value utilities

### AutoRepeatBasic
- 📄 [README](AutoRepeatBasic/README.md)
- 🧪 Sketch: `AutoRepeatBasic/AutoRepeatBasic.ino`

### LongPressDetectorBasic
- 📄 [README](LongPressDetectorBasic/README.md)
- 🧪 Sketch: `LongPressDetectorBasic/LongPressDetectorBasic.ino`

### OneShotEventBasic
- 📄 [README](OneShotEventBasic/README.md)
- 🧪 Sketch: `OneShotEventBasic/OneShotEventBasic.ino`

### PeriodicTimerBlink
- 📄 [README](PeriodicTimerBlink/README.md)
- 🧪 Sketch: `PeriodicTimerBlink/PeriodicTimerBlink.ino`

### RateLimiterRampPWM
- 📄 [README](RateLimiterRampPWM/README.md)
- 🧪 Sketch: `RateLimiterRampPWM/RateLimiterRampPWM.ino`

### ToggleOnPress
- 📄 [README](ToggleOnPress/README.md)
- 🧪 Sketch: `ToggleOnPress/ToggleOnPress.ino`

## Digital output examples

### PulseGeneratorBlink
- 📄 [README](PulseGeneratorBlink/README.md)
- 🧪 Sketch: `PulseGeneratorBlink/PulseGeneratorBlink.ino`

### PulseStretcherButtonToLED
- 📄 [README](PulseStretcherButtonToLED/README.md)
- 🧪 Sketch: `PulseStretcherButtonToLED/PulseStretcherButtonToLED.ino`

### TimedOutputPulse
- 📄 [README](TimedOutputPulse/README.md)
- 🧪 Sketch: `TimedOutputPulse/TimedOutputPulse.ino`


## Utility and instrumentation examples

### StatisticsBasic
- 📄 [README](StatisticsBasic/README.md)
- 🧪 Sketch: `StatisticsBasic/StatisticsBasic.ino`

### LatchBasic
- 📄 [README](LatchBasic/README.md)
- 🧪 Sketch: `LatchBasic/LatchBasic.ino`

### SoftWatchdogBasic
- 📄 [README](SoftWatchdogBasic/README.md)
- 🧪 Sketch: `SoftWatchdogBasic/SoftWatchdogBasic.ino`

### AnalogIntegratorBasic
- 📄 [README](AnalogIntegratorBasic/README.md)
- 🧪 Sketch: `AnalogIntegratorBasic/AnalogIntegratorBasic.ino`


---

## Notes

- GPIO-owning classes require `begin()` to configure hardware.
- Event/value utilities (`OneShotEvent`, `Toggle`, `RateLimiter`, `PeriodicTimer`, `LongPressDetector`, `AutoRepeat`) do not touch GPIO.
- Examples avoid `delay()` except where explicitly used for Serial readability.

These examples are meant to be read, modified, and combined.
They illustrate the **composition-first philosophy** of GPIOUtils.

---

Part of the **GPIOUtils** Arduino utility library.
