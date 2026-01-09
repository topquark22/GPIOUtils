#include <GPIOUtils.h>

static const uint8_t BUTTON_PIN = 2; // to GND, uses INPUT_PULLUP
static const uint8_t LED_PIN    = 5;

MultiPress triple(3, 450, 2000); // 3 presses, <=450ms gap, 2s total timeout

bool led = false;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  const bool pressed = (digitalRead(BUTTON_PIN) == LOW);

  triple.update(pressed);

  if (triple.consume()) {
    led = !led;
    digitalWrite(LED_PIN, led ? HIGH : LOW);
  }
}
