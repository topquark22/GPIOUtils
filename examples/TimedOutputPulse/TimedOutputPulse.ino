#include <gpioutils.h>

TimedOutput led(5);

void setup() {
  led.begin();
}

void loop() {
  led.pulse(500);
  bool v = led.read();
  while (HIGH == v) {
    v = led.read();
  }
  delay(1500);
}
