#include <GPIOUtils.h>

const uint8_t PIN_LED = 5;

Schmitt sch(A0, 480, 540);

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
