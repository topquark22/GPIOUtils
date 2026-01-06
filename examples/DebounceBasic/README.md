# DebounceBasic

This example demonstrates how to use **GPIOUtils::Debounce** to reliably read a
mechanical pushbutton without false triggers caused by contact bounce.

The sketch detects clean button press events and toggles an LED exactly once per
press.

---

## What problem this solves

Mechanical buttons do not switch cleanly. When pressed or released, the contacts
typically bounce for several milliseconds, producing multiple rapid transitions.

Without debouncing, a single press can be interpreted as many presses.

`Debounce`:
- filters out contact bounce
- produces a stable logical state
- provides clean edge events (`rose()`, `fell()`)

---

## Hardware setup

- Pushbutton between **digital pin 2** and **GND**
- LED on **digital pin 5**

The button uses the internal pull-up resistor (`INPUT_PULLUP`), so:
- released = HIGH
- pressed  = LOW

---

## Sketch behavior

- The button input is debounced with a 25 ms stability window
- Each clean **button press** toggles the LED state
- A message is printed to the Serial Monitor on each debounced press

---

## Relevant code excerpt

```cpp
Debounce button(2, INPUT_PULLUP, 25);

void setup() {
  button.begin();
}

void loop() {
  button.read();
  if (button.fell()) {
    // button pressed
  }
}
