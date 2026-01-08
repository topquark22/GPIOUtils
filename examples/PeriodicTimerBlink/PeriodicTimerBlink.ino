#include <gpioutils.h>

constexpr uint32_t PERIOD_MS = 500;

PeriodicTimer blink(PERIOD_MS);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  blink.start();
}

void loop() {
  if (blink.tick()) {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }
}
