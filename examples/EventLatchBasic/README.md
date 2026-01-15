## EventLatchBasic

Demonstrates the `EventLatch` component, which captures an event and remembers it until explicitly consumed.

One button latches an event, while a second button reads and clears it.  
Two LEDs are used to make the behavior visible: one shows that an event is currently latched, and the other shows the result of the read-and-clear operation.

This example illustrates:

- read-to-clear event semantics
- non-destructive inspection using `peek()`
- separation of event production and consumption
- reliable handling of transient events without timing or delays