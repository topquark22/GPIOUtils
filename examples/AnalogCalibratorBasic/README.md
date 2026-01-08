# AnalogCalibratorBasic

Demonstrates `AnalogCalibrator`, which clamps and maps `analogRead()` values using a calibrated raw range.

## Wiring

- Potentiometer wiper to **A0**
- Ends to **5V** and **GND**

## Behavior

- Reads `analogRead(A0)`
- Prints:
  - normalized `u` in **0..1**
  - mapped `pwm` in **0..255**
  - mapped `deg` in **0..270**

## Notes

If your pot reads inverted (higher when turned "down"), just swap the range:

```cpp
AnalogCalibrator cal(970, 65);  // inverted range
```
