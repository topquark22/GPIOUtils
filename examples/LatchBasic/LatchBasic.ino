#include <gpioutils.h>

/*
  LatchBasic

  Two buttons:
    - SET button on pin 2 (to GND, INPUT_PULLUP)
    - RESET button on pin 3 (to GND, INPUT_PULLUP)

  Latch drives LED on pin 5.
*/

static const uint8_t PIN_SET = 2;
static const uint8_t PIN_RST = 3;
static const uint8_t PIN_LED = 5;

Debounce setBtn(PIN_SET, INPUT_PULLUP, 25);
Debounce rstBtn(PIN_RST, INPUT_PULLUP, 25);

Latch latch(false);

void setup() {
  pinMode(PIN_LED, OUTPUT);
  setBtn.begin();
  rstBtn.begin();
}

void loop() {
  setBtn.read();
  rstBtn.read();

  if (setBtn.fell()) latch.set(); 
  if (rstBtn.fell()) latch.reset();

  digitalWrite(PIN_LED, latch.value() ? HIGH : LOW);
}
