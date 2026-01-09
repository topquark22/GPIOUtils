#include <GPIOUtils.h>

Debounce btn(2, INPUT_PULLUP, 25);
Toggle latch;
constexpr uint8_t LED_PIN = 5;

void setup() {
  btn.begin();
  latch.begin();
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  btn.read();
  if (btn.fell()) latch.trigger();
  digitalWrite(LED_PIN, latch.read());
}
