/*
  PulseStretcherButtonToLED

  Demonstrates a pulse stretcher built by composition:

      Debounce → OneShotEvent → TimedOutput

  A momentary button press produces a visible LED pulse
  of fixed duration, without delay().

  Wiring:
    - Button between pin 2 and GND (INPUT_PULLUP)
    - LED on pin 5
*/

#include <GPIOUtils.h>

constexpr uint8_t BUTTON_PIN = 2;
constexpr uint8_t LED_PIN    = 5;
constexpr uint32_t DEBOUNCE_MS = 25;
constexpr uint32_t PULSE_MS    = 150;

Debounce     button(BUTTON_PIN, INPUT_PULLUP, DEBOUNCE_MS);
OneShotEvent pulse(PULSE_MS);
TimedOutput  led(LED_PIN);

void setup() {
  button.begin();
  led.begin();
}

void loop() {
  // Update input
  button.read();

  // Trigger one-shot on clean button press (active-low → falling edge)
  if (button.fell()) {
    pulse.trigger();
  }

  // Drive LED from one-shot state
  if (pulse.read()) {
    led.on();
  } else {
    led.off();
  }

  // Maintain timed output
  led.read();
}
