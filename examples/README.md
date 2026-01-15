# GPIOUtils Examples

This directory contains small, focused example sketches demonstrating individual classes and idioms provided by the **GPIOUtils** library.


Each example is intentionally narrow in scope. Rather than showing “big applications,” these sketches illustrate **one concept at a time**, using minimal wiring and logic. They are meant to be read, modified, and reused as building blocks.

All examples are **non-blocking** unless explicitly stated.

---

## Wiring

Pin conventions used by all examples (unless noted):

| function | pinMode |symbol | pin |
|----------|-------|-----|---|
| voltage divider | INPUT | POT_PIN | A0 |
| mechanical pushbutton | INPUT_PULLUP | BUTTON_PIN | 2 |
| digital signal (clean) | INPUT | SIGNAL_PIN | 3 |
| LED 1 | OUTPUT |  LED_PIN | 5 |
| LED 2 | OUTPUT |  LED2_PIN | 6 |

---

## Example index

### Analog & signal conditioning

- **AnalogCalibratorBasic**  
  Normalize and remap real-world ADC readings that don’t reach 0 or full scale.

- **AnalogDejitterRead**  
  Remove small analog noise using a deadband and observe the effect via Serial output.

- **AnalogIntegratorBasic**  
  Integrate a normalized analog signal over time (“area under the curve”).

- **DejitterBasic**  
  Side-by-side comparison of raw vs dejittered ADC readings.

- **SchmittAnalogThreshold**  
  Convert a noisy analog signal into a stable digital decision using hysteresis.

---

### Buttons, edges, and gestures

- **DebounceBasic**  
  Clean a mechanical button and trigger an action once per press.

- **EdgeDetectorBasic**  
  Detect rising and falling edges on a clean digital signal.

- **EventLatchBasic**
  Detect an event and set a latch. The latch is cleared when read.

- **GlitchFilterBasic**  
  Reject short spikes by requiring a minimum stable time.

- **LongPressDetectorBasic**  
  Detect press-and-hold gestures (long press vs short press).

- **MultiPressBasic**  
  Count multiple quick presses (single, double, triple, etc.) and act once.

- **ToggleOnPress**  
  Toggle a remembered state on each button press.

---

### Timing, pulses, and rate control

- **PeriodicTimerBlink**  
  Blink an LED at a fixed rate without using `delay()`.

- **PulseGeneratorBlink**  
  Generate a finite blink pattern (N blinks) triggered by a button.

- **PulseStretcherButtonToLED**  
  Stretch a brief button press into a guaranteed-visible output pulse.

- **OneShotEventBasic**  
  Trigger a fixed-duration logical event from any source (Serial in this example).

- **TimedOutputPulse**  
  Schedule timed pulses while letting a class own the output pin.

- **RateLimiterRampPWM**  
  Smooth how fast a value changes (slew-rate limiting), not just noise.

---

### Control & safety patterns

- **AutoRepeatBasic**  
  Keyboard-style auto-repeat behavior when holding a button.

- **LatchBasic**  
  Classic SET / RESET latch using two buttons.

- **SoftWatchdogBasic**  
  Detect stalled logic by requiring periodic “kicks.”

---

## How to use these examples

1. Pick the example closest to your problem.
2. Read its `README.md` first — behavior and intent are documented there.
3. Open the `.ino` file and scan it top to bottom.
4. Copy the pattern, not necessarily the entire sketch.

These examples are designed to be **composable**: many real sketches will use several of these classes together.

---

## Design philosophy

GPIOUtils examples follow a few consistent principles:

- No `delay()` unless explicitly teaching why it’s bad
- Clear separation between:
  - input conditioning
  - timing / logic
  - output driving
- Logic classes do **not** secretly own GPIO unless their name says they do
- Time is always handled safely (`millis()` deltas, wrap-safe comparisons)

If you understand the examples in this folder, you should be able to assemble reliable, responsive Arduino sketches without reinventing timing or input logic each time.
