#include <gpioutils.h>

/*
  SoftWatchdogBasic

  A software watchdog that detects when expected activity stops.

  - LED on pin 13 turns ON when watchdog has expired.
  - Every ~200ms we "kick" the watchdog unless the user holds the button.

  Button on pin 2 to GND (INPUT_PULLUP):
    Hold the button to simulate a stalled system (no kicks).
*/

static const uint8_t PIN_BTN = 2;
static const uint8_t PIN_LED = 13;

Debounce btn(PIN_BTN, INPUT_PULLUP, 25);
SoftWatchdog wd(2000); // 2 seconds

uint32_t lastKick = 0;

void setup() {
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  btn.read();
  uint32_t now = millis();

  // Kick unless button held (simulate failure)
  bool held = (btn.state() == LOW); // INPUT_PULLUP: LOW means pressed
  if (!held && (uint32_t)(now - lastKick) >= 200) {
    lastKick = now;
    wd.kick();
  }

  digitalWrite(PIN_LED, wd.expired() ? HIGH : LOW);
}
