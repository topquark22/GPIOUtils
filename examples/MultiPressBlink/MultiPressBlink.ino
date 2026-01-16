#include <GPIOUtils.h>

/*
  MultiPressBasic

  Multi-press the button n times to make the LED blink n times.

  Pin conventions:
    BUTTON_PIN = 2  (wired to GND, INPUT_PULLUP)
    LED_PIN    = 5

  Behavior:
    - MultiPress returns 0 while presses are still occurring
    - After the final quiet gap, it triggers the pulse generator to output n pulses
*/

static const uint8_t BUTTON_PIN = 2;
static const uint8_t LED_PIN    = 5;

// Timing parameters
static const uint32_t DEBOUNCE_MS     = 30;
static const uint32_t FINAL_GAP_MS    = 400;
static const uint32_t SEQ_TIMEOUT_MS  = 2000;

// MultiPress owns the pin AND the mode
MultiPress mp(
  BUTTON_PIN,
 // INPUT_PULLUP,
  DEBOUNCE_MS,
  FINAL_GAP_MS,
  SEQ_TIMEOUT_MS
);

// 250ms on / 250ms off = n visible blinks in ~ n * 0.5 s
static constexpr uint32_t ON_MS  = 250;
static constexpr uint32_t OFF_MS = 250;

// PulseGenerator is pure logic (does not own a pin)
PulseGenerator pg(ON_MS, OFF_MS, true);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  mp.begin();
  pg.stop(true);
}

void loop() {
  mp.update();
  pg.update();

  const uint8_t presses = mp.takeCount();
  if (presses > 0) {
    pg.trigger(presses);
  }

  digitalWrite(LED_PIN, pg.state() ? HIGH : LOW);
}
