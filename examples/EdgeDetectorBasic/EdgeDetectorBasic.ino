#include <gpioutils.h>

EdgeDetector ed(3, INPUT);

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
