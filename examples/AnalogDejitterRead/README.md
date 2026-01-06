# AnalogDejitterRead

This example compares raw ADC readings with dejittered values.

---

## What problem this solves

ADC readings often flicker even when the input is steady.

`Dejitter` suppresses this noise using a deadband.

---

## Hardware setup

- Potentiometer wiper → **A0**
- Pot ends → 5V and GND

---

## Sketch behavior

- Prints raw and dejittered values to Serial
- Small fluctuations are removed from the clean signal

---

Part of the **GPIOUtils** Arduino utility library.
