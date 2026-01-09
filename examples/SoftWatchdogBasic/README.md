# examples/SoftWatchdogBasic/README.md
# SoftWatchdogBasic

## Introduction

Demonstrates `SoftWatchdog`, a software watchdog that expires if it is not “kicked” often enough. This is useful for detecting stalled logic, missing events, or dead loops.

---

## Behaviour

- LED on `D5` indicates watchdog status:
  - OFF when the watchdog is healthy
  - ON when the watchdog has expired
- Every `KICK_PERIOD_MS` (~200 ms), the sketch attempts to kick the watchdog.
- Holding the button prevents kicks, simulating a stalled system.
- Serial prints a status line about once per second.

---

## Wiring

- Button:
  - Between `D2` (`PIN_BTN`) and `GND`
  - Uses `INPUT_PULLUP`
- LED:
  - LED anode → `D5` (`PIN_LED`) through a resistor
  - LED cathode → `GND`
- Serial Monitor: `115200` baud

---

## Key points illustrated

- A watchdog as “expected activity is missing” detection.
- Scheduling periodic actions using `millis()` deltas.
- A simple way to simulate failure modes (hold button → no kick → expire).

---

## Why this example exists

Many bugs look like “it stopped responding” but you don’t know when or why. A watchdog gives you a hard signal when expected periodic activity isn’t happening. This example shows the minimal pattern and a safe way to test it.
