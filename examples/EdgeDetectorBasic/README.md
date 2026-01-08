# EdgeDetectorBasic

This example demonstrates how to use **GPIOUtils::EdgeDetector** to detect
rising and falling edges on a clean digital signal.

Unlike `Debounce`, this example assumes the input signal does **not** bounce.

---

## What problem this solves

Sometimes you want to react **only when a signal changes**, not continuously
while it stays high or low.

`EdgeDetector` detects:
- rising edges (LOW → HIGH)
- falling edges (HIGH → LOW)

---

## Hardware setup

- Digital signal source connected to **pin 3**
- Serial Monitor output

---

## Sketch behavior

- Reads the digital pin continuously
- Prints messages on rising and falling edges

---

## Notes

- `EdgeDetector` does not debounce.
- For mechanical buttons, use `Debounce` instead.

---

Part of the **GPIOUtils** Arduino utility library.
