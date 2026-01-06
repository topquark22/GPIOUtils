# DejitterBasic

This example demonstrates how to use **GPIOUtils::Dejitter** to suppress
small analog fluctuations (“jitter”) from a potentiometer or other analog source.

The sketch prints both the **raw ADC reading** and the **dejittered value**
to the Serial Monitor so the effect is easy to observe.

---

## What problem this solves

Even when a potentiometer is not moving, `analogRead()` often fluctuates by
±1 or ±2 counts due to ADC noise, power supply ripple, or wiring.

`Dejitter` applies a simple **deadband**:
- Small changes are ignored
- Real movement is passed through immediately
- No averaging, lag, or smoothing is introduced

---

## Hardware setup

- Potentiometer wiper → **A0**
- Potentiometer ends → **5V** and **GND**

No other components are required.

---

## Sketch behavior

- Reads the potentiometer in two ways:
  - Raw: direct `analogRead()`
  - Clean: `Dejitter::read()`
- Prints both values side-by-side to the Serial Monitor
- Small flicker appears only in the raw reading

---

## Relevant code excerpt

```cpp
Dejitter pot(A0, 1);  // deadband of +/-1 ADC count

void setup() {
  pot.begin();
}

void loop() {
  int raw = analogRead(A0);
  int clean = pot.read();
}
