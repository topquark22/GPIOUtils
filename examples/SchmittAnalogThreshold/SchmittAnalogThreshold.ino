#include <gpioutils.h>

Schmitt sch(A0, 480, 540);

void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  sch.begin();
}

void loop() {
  Serial.println(sch.read() ? "HIGH" : "LOW");
}
