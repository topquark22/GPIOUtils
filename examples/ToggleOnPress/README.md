# ToggleOnPress

This example demonstrates a press-to-toggle latch built using:

```
Debounce → Toggle
```

---

## What problem this solves

You want a button to toggle a state instead of acting momentarily.

---

## Hardware setup

- Button on **pin 2** (INPUT_PULLUP)
- LED on **pin 13**

---

## Sketch behavior

- Each clean button press toggles the LED state
- No repeated toggling while held

---

## Notes

- `Toggle` is event-driven and does not touch GPIO.
- `Debounce` provides clean press events.

---

Part of the **GPIOUtils** Arduino utility library.
