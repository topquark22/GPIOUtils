# LongPressDetectorBasic

Demonstrates `LongPressDetector` paired with `Debounce`.

- `Debounce` provides a stable button state.
- `LongPressDetector` turns that stable state into a one-shot event when the
  press duration crosses a threshold.

This example toggles an LED when the button is held for ~800 ms.
