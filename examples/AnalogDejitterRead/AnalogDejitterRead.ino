#include <GPIOUtils.h>

Dejitter pot(A0, 1);

void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  pot.begin();
}

void loop() {
  Serial.println(pot.read());
  delay(20);
}
