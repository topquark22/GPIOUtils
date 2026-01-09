#include <GPIOUtils.h>

/*
  MultiPressBasic

  Double-press the button to light the LED for a fixed duration.

  Pin conventions:
    BUTTON_PIN = 2  (wired to GND, INPUT_PULLUP)
    LED_PIN    = 5

  Behavior:
    - MultiPress returns 0 while presses are still occurring
    - After the final quiet gap, it returns the total press count ONCE
    - If the count is exactly 2, an LED pulse is triggered
*/

static const uint8_t BUTTON_PIN = 2;
static const uint8_t LED_PIN    = 5;

// Timing parameters
static const uint32_t DEBOUNCE_MS     = 30;
static const uint32_t FINAL_GAP_MS    = 400;
static const uint32_t SEQ_TIMEOUT_MS  = 2000;

// LED pulse duration
static const uint32_t LED_PULSE_MS = 1500;

// MultiPress owns the pin AND the mode
MultiPress mp(
  BUTTON_PIN,
 // INPUT_PULLUP,
  DEBOUNCE_MS,
  FINAL_GAP_MS,
  SEQ_TIMEOUT_MS
);

// Event-driven one-shot pulse
OneShotEvent ledPulse(LED_PULSE_MS, /*retrigger=*/true);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  mp.begin();
  ledPulse.begin();
}

void loop() {
  mp.update();

  const uint8_t presses = mp.takeCount();
  if (presses == 2) {
    ledPulse.trigger();
  }

  digitalWrite(LED_PIN, ledPulse.read() ? HIGH : LOW);
}
