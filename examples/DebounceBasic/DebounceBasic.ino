#include <gpioutils.h>

constexpr uint8_t BUTTON_PIN = 2;
constexpr uint8_t LED_PIN = 5;
constexpr uint32_t DEBOUNCE_MS = 25;

Debounce button(BUTTON_PIN, INPUT_PULLUP, DEBOUNCE_MS);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  button.begin();
}

void loop() {
  button.read();
  if (button.fell()) {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  }
}
