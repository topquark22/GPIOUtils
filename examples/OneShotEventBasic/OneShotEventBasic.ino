#include <gpioutils.h>

OneShotEvent pulse(1000);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(115200);
}

void loop() {
  if (Serial.available()) {
    Serial.read();
    pulse.trigger();
  }
  if (pulse.read()) {
    Serial.println("Pulse active");
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
