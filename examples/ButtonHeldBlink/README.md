# ButtonHeldBlink Example

This example demonstrates how to combine **Debounce** and **PeriodicTimer** from the GPIOUtils library to create a simple interactive LED behavior.

## Overview

- A pushbutton is connected to **pin 2** (active-low, using `INPUT_PULLUP`)
- An LED is connected to **pin 5**
- The button is debounced using the `Debounce` class
- A `PeriodicTimer` is used to generate a 250 ms blink interval

### Behavior

- When the button is **not pressed**, the LED remains **OFF**
- While the button is **held down**, the LED **blinks continuously** at 250 ms intervals

## Wiring

- **Button**
  - One side → GND
  - Other side → pin 2
- **LED**
  - Anode → pin 5 (through a resistor, e.g. 220Ω)
  - Cathode → GND

## Code Summary

- `Debounce` ensures stable button input
- `PeriodicTimer::tick()` provides a non-blocking timing signal
- The LED toggles state only while the button is held

## Notes

- The blink timer runs continuously in the background
- The LED only responds to the timer when the button is pressed
- This means the blink phase is not reset when the button is pressed

If you prefer the LED to always start from OFF when the button is pressed, you can reset or restart the timer on the button press edge.

## File

- `ButtonHeldBlink.ino`

## Part of GPIOUtils

This example is part of the GPIOUtils toolkit:
https://github.com/topquark22/GPIOUtils
