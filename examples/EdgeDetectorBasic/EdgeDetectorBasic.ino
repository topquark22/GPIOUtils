#include <gpioutils.h>

const uint8_t PIN_IN = 3;

EdgeDetector ed(PIN_IN, INPUT_PULLUP);

void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  ed.begin();
}

void loop() {
  ed.read();
  if (ed.rose()) Serial.println("Rising edge");
  if (ed.fell()) Serial.println("Falling edge");
}
