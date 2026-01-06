#include <gpioutils.h>

OneShotEvent pulse(200);

void setup() {
  Serial.begin(115200);
  while (!Serial) {}
}

void loop() {
  if (Serial.available()) {
    Serial.read();
    pulse.trigger();
  }
  if (pulse.read()) {
    Serial.println("Pulse active");
  }
}
