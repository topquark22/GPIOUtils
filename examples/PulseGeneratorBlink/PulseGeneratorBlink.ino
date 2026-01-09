#include <Arduino.h>
#include <GPIOUtils.h>

static constexpr uint8_t BUTTON_PIN = 2;  // active LOW
static constexpr uint8_t LED_PIN    = 5;

// 250ms on / 250ms off = 3 visible blinks in ~1.5s
static constexpr uint32_t ON_MS  = 250;
static constexpr uint32_t OFF_MS = 250;

Debounce btn(BUTTON_PIN, INPUT_PULLUP);

// PulseGenerator is pure logic (does not own a pin)
PulseGenerator pg(ON_MS, OFF_MS, true);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  btn.begin();

  // Keep generator idle at boot
  pg.stop(true);
}

void loop() {
  btn.read();
  pg.update();

  // Drive the LED from the generator state
  digitalWrite(LED_PIN, pg.state() ? HIGH : LOW);

  // Restart and blink 3 times on each press
  if (btn.fell()) {
    pg.trigger(3);
  }
}
