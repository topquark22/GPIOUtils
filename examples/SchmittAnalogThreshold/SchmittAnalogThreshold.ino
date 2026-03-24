#include <GPIOUtils.h>

const uint8_t PIN_POT = A0;
const uint8_t PIN_LED = 5;

Schmitt sch(PIN_POT, 400, 600);

void setup() {
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(115200);
  while (!Serial) {}
  sch.begin();
}

void loop() {
  bool v = sch.read();
  digitalWrite(PIN_LED, v);
  Serial.println(v ? "HIGH" : "LOW");
}
