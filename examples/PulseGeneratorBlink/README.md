# PulseGeneratorBlink

Demonstrates `PulseGenerator`, a non-blocking square-wave / blink pattern generator.

## Behavior

- On button press, the built-in LED turns ON for 200 ms, OFF for 800 ms, repeating 3 times.
- No `delay()` is used.

## Notes

`PulseGenerator` does **not** own a pin. Call `update()` frequently and drive an output using `state()`.
