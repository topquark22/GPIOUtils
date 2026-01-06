# SchmittAnalogThreshold

This example demonstrates **GPIOUtils::Schmitt** for clean analog thresholding.

---

## What problem this solves

Analog signals hovering near a threshold can chatter.

A Schmitt trigger adds hysteresis to eliminate chatter.

---

## Hardware setup

- Potentiometer wiper → **A0**

---

## Sketch behavior

- Converts analog input to a stable boolean
- Output changes only when thresholds are crossed

---

Part of the **GPIOUtils** Arduino utility library.
