#include <Arduino.h>
#include <GPIOUtils.h>

static constexpr uint8_t BUTTON_PIN = 2;
static constexpr uint8_t LED_PIN    = 5;

// Blink parameters
static constexpr unsigned long BLINK_PERIOD_MS = 500; // full period

// -1 for infinite
const int NUM_BLINKS = 3;

Debounce btn(BUTTON_PIN, INPUT_PULLUP);

// period is full cycle (on + off)
PulseGenerator blinker(
  LED_PIN,
  BLINK_PERIOD_MS,
  true   // active HIGH LED
);

void setup() {
  btn.begin();
  blinker.begin();
}

void loop() {
  // Update stateful helpers
  btn.read();
  blinker.update();

  // On button press, trigger 3 blinks
  if (btn.fell()) {
    // Optional guard: ignore if already running
    if (!blinker.active()) {
      blinker.trigger(NUM_BLINKS);
    }
  }
}
