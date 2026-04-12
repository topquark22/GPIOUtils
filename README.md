# GPIOUtils

**GPIOUtils** is a lightweight, composable toolkit for writing clean, non-blocking Arduino code.

It solves the small but persistent problems that make embedded code messy:
- switch bounce
- noisy analog signals
- timing logic scattered everywhere
- awkward state machines
- one-off hacks that don’t scale

Instead of monolithic frameworks, GPIOUtils gives you **small building blocks** that snap together cleanly.

---

## 🚀 What this library actually lets you do

With a few simple components, you can build behaviour like:

- A button with **debounce + long-press + auto-repeat**
- An analog input with **noise suppression + hysteresis**
- A clean event pipeline like:

```
button → debounce → edge → long-press → one-shot → timed output
```

- Non-blocking timing like:
  - periodic tasks
  - pulse generation
  - delayed triggers
  - rate-limited signals

All without `delay()` and without tangled logic.

---

## 🧩 Design philosophy

GPIOUtils follows a few strict rules:

### 1. No hidden side effects
Constructors never touch hardware.  
All setup happens explicitly in:

```cpp
begin();
```

---

### 2. Clear ownership of pins
- If a class owns a pin → it configures it  
- If it doesn’t → it never touches hardware

---

### 3. Composition over complexity

Instead of giant helper classes, everything is designed to chain:

```
raw input → conditioning → event → timing → output
```

You build exactly what you need—nothing more.

---

## 📦 Components overview

### 🔹 Analog conditioning

- **AnalogCalibrator**  
  Fix real-world ADC range issues (inputs that don’t hit full scale)

- **Dejitter**  
  Removes small analog noise (deadband filtering)

- **Schmitt**  
  Converts noisy analog signals into stable digital states (hysteresis)

---

### 🔹 Digital input cleanup

- **Debounce**  
  Clean up mechanical switches

- **EdgeDetector**  
  Detect rising/falling edges cleanly

- **GlitchFilter**  
  Reject short spikes and false triggers

---

### 🔹 Event & timing logic (no GPIO required)

- **OneShotEvent**  
  Fire a fixed-duration event (optionally delayed)

- **PulseGenerator**  
  Generate pulse trains (finite or continuous)

- **AutoRepeat**  
  Keyboard-style repeating input

- **MultiPress**  
  Detect double/triple clicks

- **LongPressDetector**  
  Detect press-and-hold actions

- **Toggle**  
  Convert events into persistent state

- **RateLimiter**  
  Smooth or constrain value changes

- **PeriodicTimer**  
  Generate regular ticks without blocking

---

### 🔹 Output control

- **TimedOutput** *(owns a pin)*  
  Drive outputs with:
  - timed pulses
  - scheduled transitions
  - non-blocking control

---

### 🔹 Utility helpers

- `adcToU8()` → ADC → 8-bit  
- `adcToFloat()` → normalized  
- `adcToFloat(min, max)` → scaled range  

---

## 🧠 Example: clean, readable logic

Instead of tangled code:

```cpp
if (buttonPressed && !lastState && millis() - lastTime > 50) { ... }
```

You get:

```cpp
Debounce button(2);
EdgeDetector edge;
OneShotEvent pulse(1000);

void loop() {
    bool clean = button.update();
    if (edge.rising(clean)) {
        pulse.trigger();
    }

    if (pulse.update()) {
        digitalWrite(LED_PIN, HIGH);
    } else {
        digitalWrite(LED_PIN, LOW);
    }

    // Do something else (nonblocking) ...
}
```

Readable. Testable. Composable.

---

## 📁 Structure

```
GPIOUtils/
  src/
    GPIOUtils.h
    impl/
  examples/
```

Only include:

```cpp
#include <GPIOUtils.h>
```

---

## 📘 Examples

Start here:  
👉 `examples/README.md`

---

## 🎯 Why use GPIOUtils?

- No blocking (`delay()`-free)
- No frameworks or magic
- Small, focused components
- Easy to reason about
- Works on any Arduino-compatible board

---

## ⚙️ Philosophy in one sentence

> “Do one thing well, and compose everything else.”
