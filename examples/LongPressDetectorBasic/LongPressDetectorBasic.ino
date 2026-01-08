#include <gpioutils.h>

constexpr uint8_t BUTTON_PIN = 2;
constexpr uint8_t LED_PIN    = 5;

constexpr uint32_t DEBOUNCE_MS  = 25;
constexpr uint32_t LONGPRESS_MS = 800;

Debounce button(BUTTON_PIN, INPUT_PULLUP, DEBOUNCE_MS);
LongPressDetector lp(LONGPRESS_MS);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  button.begin();
}

void loop() {
  const bool stable = button.read();

  // With INPUT_PULLUP, pressed is LOW.
  const bool pressed = !stable;
  lp.update(pressed);

  if (lp.long_pressed()) {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  }
}
