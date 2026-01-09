# GPIOUtils Examples

This directory contains small, focused example sketches demonstrating the
individual building blocks provided by GPIOUtils.

Each example lives in its own subdirectory and is intended to be read,
compiled, and modified independently.

Pin conventions used by all examples (unless noted):
- POT_PIN    = A0
- BUTTON_PIN = 2
- SIGNAL_PIN = 3
- LED_PIN    = 5

---

## Digital Inputs

Examples related to buttons, switches, and digital signal conditioning.

- [`DebounceBasic/`](DebounceBasic)  
  Basic debouncing of a mechanical button.

- [`GlitchFilterBasic/`](GlitchFilterBasic)  
  Rejects short digital glitches while allowing real transitions.

- [`LongPressDetectorBasic/`](LongPressDetectorBasic)  
  Detects when a button has been held longer than a threshold.

- [`MultiPressBasic/`](MultiPressBasic)
  Captures multiple button presses within a short time period.

- [`ToggleOnPress/`](ToggleOnPress)  
  Toggle a state each time a button is pressed.

---

## Timing & Events

Examples demonstrating non-blocking time-based behavior.

- [`OneShotEventBasic/`](OneShotEventBasic)  
  Generate a single timed pulse in response to an event.

- [`PeriodicTimerBlink/`](PeriodicTimerBlink)  
  Use a periodic timer instead of `delay()`.

- [`PulseGeneratorBlink/`](PulseGeneratorBlink)  
  Generate a square-wave blink pattern without blocking.

- [`SoftWatchdogBasic/`](SoftWatchdogBasic)  
  Software watchdog that detects when expected activity stops.

---

## Analog Processing

Examples for stabilizing and shaping analog values.

- [`DejitterBasic/`](DejitterBasic)  
  Suppress small analog jitter while preserving full-range motion.

- [`AnalogCalibratorBasic/`](AnalogCalibratorBasic)  
  Map raw ADC values using calibrated endpoints.

- [`SchmittBasic/`](SchmittBasic)  
  Apply hysteresis to an analog signal to produce a clean digital state.

---

## Output Shaping

Examples that control how outputs change over time.

- [`RateLimiterRampPWM/`](RateLimiterRampPWM)  
  Ramp a PWM output toward a target value at a controlled rate.

---

## Notes

- These examples are intentionally minimal and composable.
- They are not frameworks; they demonstrate one concept at a time.
- Open each directory to see the corresponding `.ino` file.
