## PulseGeneratorBlink

**Demonstrates:** `PulseGenerator`, `Debounce`

This example shows how to use **`PulseGenerator` as a pure timing/state generator** (it does not own a GPIO pin) to blink an LED a fixed number of times when a button is pressed.

### Behavior

- On startup, the LED is **off**
- Each button press causes the LED to **blink exactly 3 times**
- Pressing the button again **restarts the blink sequence immediately**
- The implementation is fully **non-blocking**

### Wiring

| Signal | Pin |
|------|-----|
| Button | D2 (INPUT_PULLUP) |
| LED | D5 |
| GND | Common ground |

The button is assumed to be **active LOW** using the internal pull-up resistor.

### Key points illustrated

- `PulseGenerator` does **not** drive pins directly  
  The sketch drives the LED using `pg.state()`.
- `trigger(n)` **always restarts**, even if already running
- `trigger(0)` is equivalent to `stop()`
- No implicit behavior at startup — the generator is idle until triggered
- Timing is handled by calling `update()` from `loop()`

### Why this example exists

This sketch is intentionally simple and focused. It demonstrates:

- how to separate **timing logic** from **GPIO control**
- how to build repeatable, restartable pulse patterns
- how to avoid `delay()` while still producing deterministic output

For more advanced patterns (infinite pulsing, retrigger cancellation, or combining with `MultiPress`), see the other `PulseGenerator` examples.
