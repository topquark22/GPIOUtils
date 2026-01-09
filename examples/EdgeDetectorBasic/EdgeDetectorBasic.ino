#include <GPIOUtils.h>

// assume clean input (no debounce)
const uint8_t PIN_IN = 3;

const uint8_t PIN_LED = 5;

EdgeDetector ed(PIN_IN, INPUT_PULLUP);

void setup() {
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(115200);
  while (!Serial) {}
  ed.begin();
}

void loop() {
  ed.read();
  if (ed.rose()) {
    Serial.println("Rising edge");
    digitalWrite(PIN_LED, HIGH);
  }
  if (ed.fell()) {
    Serial.println("Falling edge");
    digitalWrite(PIN_LED, LOW);
  }
}
