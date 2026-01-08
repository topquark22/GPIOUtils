#include <gpioutils.h>

static const uint8_t LED_PIN = LED_BUILTIN;

// 200 ms ON, 800 ms OFF
PulseGenerator pg(200, 800, true);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  pg.update();
  digitalWrite(LED_PIN, pg.state() ? HIGH : LOW);
}
