#include <gpioutils.h>

Debounce btn(2, INPUT_PULLUP, 25);
Toggle latch;

void setup() {
  btn.begin();
  latch.begin();
  pinMode(13, OUTPUT);
}

void loop() {
  btn.read();

  if (btn.fell()) {
    latch.trigger();
  }

  digitalWrite(13, latch.read() ? HIGH : LOW);
}
