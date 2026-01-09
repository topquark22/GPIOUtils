#include <GPIOUtils.h>

constexpr uint8_t LED_PIN = 2;

constexpr uint32_t PERIOD_MS = 500;

PeriodicTimer blink(PERIOD_MS);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  blink.start();
}

void loop() {
  if (blink.tick()) {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  }
}
