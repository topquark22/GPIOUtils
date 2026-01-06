# OneShotEventBasic

This example demonstrates **GPIOUtils::OneShotEvent**, an event-driven
non-blocking one-shot (monostable).

---

## What problem this solves

Sometimes an event is very short, but you want its effect to last longer.

`OneShotEvent` converts a momentary trigger into a fixed-duration true signal.

---

## Sketch behavior

- A trigger event starts a one-shot pulse
- Output remains true for a fixed duration
- No `delay()` is used

---

## Notes

- `OneShotEvent` does not read GPIO pins.
- It is designed to be triggered by events from other utilities.

---

Part of the **GPIOUtils** Arduino utility library.
