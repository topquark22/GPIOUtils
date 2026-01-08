# AutoRepeatBasic

Demonstrates `AutoRepeat`, which generates repeated events while a button is held.

## Wiring

- Button between **D2** and **GND**
- Uses `INPUT_PULLUP` (released = HIGH, pressed = LOW)

## Behavior

- Press and hold the button.
- After an initial delay (500 ms), the sketch prints `value = ...` repeatedly.
- Repeat rate is 150 ms per step.

## Notes

`AutoRepeat` does **not** read a pin itself—pair it with `Debounce` (or your own stable pressed signal).
