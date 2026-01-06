# PulseStretcherButtonToLED

This example demonstrates a **pulse stretcher** built using composition:

```
Debounce → OneShotEvent → TimedOutput
```

No dedicated pulse-stretcher class is required.

---

## What problem this solves

A button press may be very short, but you want a visible output pulse.

---

## Hardware setup

- Button on **pin 2** (INPUT_PULLUP)
- LED on **pin 13**

---

## Sketch behavior

- Button press is debounced
- A one-shot pulse is triggered
- LED lights for a fixed duration

---

## Notes

This example illustrates the design philosophy of GPIOUtils:
**compose simple building blocks instead of adding specialized classes**.

---

Part of the **GPIOUtils** Arduino utility library.
