#include <gpioutils.h>

TimedOutput led(13);

void setup() {
  led.begin();
}

void loop() {
  led.pulse(150);
  delay(1000);
  led.read();
}
