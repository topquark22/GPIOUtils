#include <gpioutils.h>

constexpr uint8_t POT_PIN = A0;
constexpr uint8_t LED_PIN = 9;

Dejitter pot(POT_PIN, 1);
RateLimiter lim(300.0f, 600.0f);

void setup() {
  pot.begin();
  lim.begin();
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int adc = pot.read();
  float target = (adc * 255.0f) / 1023.0f;
  float y = lim.read(target);
  analogWrite(LED_PIN, (int)(y + 0.5f));
}
