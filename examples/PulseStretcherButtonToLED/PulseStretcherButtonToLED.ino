#include <gpioutils.h>

Debounce btn(2, INPUT_PULLUP, 25);
OneShotEvent pulse(120);
TimedOutput led(13);

void setup() {
  btn.begin();
  led.begin();
}

void loop() {
  btn.read();
  if (btn.fell()) pulse.trigger();
  if (pulse.read()) led.on();
  else led.off();
}
