#include <gpioutils.h>

constexpr uint8_t BUTTON_PIN = 2;
constexpr uint8_t LED_PIN    = 5;

// Reject pulses/glitches shorter than this.
constexpr uint32_t MIN_STABLE_MS = 8;

GlitchFilter button(BUTTON_PIN, INPUT_PULLUP, MIN_STABLE_MS);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  button.begin();
}

void loop() {
  button.read();
  if (button.fell()) { // button press (active-low)
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  }
}
