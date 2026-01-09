# MultiPressBasic

This example demonstrates the **MultiPress** helper from **GPIOUtils**, which
detects and counts multiple button presses occurring within a short time window.

The sketch shows how to collect a button-press sequence and retrieve the final count
once the sequence is complete.

---

## What this example shows

- How to use `MultiPress` to detect **sequential button presses**
- How `MultiPress` internally manages debouncing and timing
- How to retrieve the final press count using `takeCount()`
- How the press count is only reported **after the sequence has ended**

---

## Hardware setup

- **Button**
  - Connected between **pin 2** and **GND**
  - Uses `INPUT_PULLUP` internally

No other hardware is required.

---

## Behaviour

- Each button press is debounced internally
- Presses are accumulated into a sequence
- When no further presses occur within the timeout window:
  - the sequence is finalized
  - `takeCount()` returns the number of presses
- After `takeCount()` is called:
  - the stored count is cleared
  - the next press starts a new sequence

Until the sequence is finalized, `takeCount()` returns `0`.

---

## Typical use cases

This pattern is useful for:

- mode selection using multi-tap input
- hidden or diagnostic commands
- extending UI functionality with a single button
- distinguishing between single-, double-, and triple-press actions

The logic remains non-blocking and does not rely on delays.

---

## Related examples

- **DebounceBasic** – basic debounced button input
- **OneShotBasic** – timed output pulses

