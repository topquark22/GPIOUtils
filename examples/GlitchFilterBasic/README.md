# GlitchFilterBasic

Demonstrates `GlitchFilter`, which rejects brief electrical glitches by requiring
a candidate input state to persist for a minimum time before accepting it.

This is similar to debouncing, but is aimed at short spikes on a line (long wires,
opto inputs, relays, etc.).
