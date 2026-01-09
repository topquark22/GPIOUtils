#include <GPIOUtils.h>

static const uint8_t PIN_BTN = 2; // button to GND, use INPUT_PULLUP

Debounce btn(PIN_BTN, INPUT_PULLUP, 25);
AutoRepeat rep(500, 150); // 500ms delay, then repeat every 150ms

int value = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial) { /* optional */ }
  btn.begin();
  Serial.println("AutoRepeatBasic: hold the button to repeat.");
}

void loop() {
  // Debounce returns current logic level (HIGH when released with pullup)
  bool level = btn.read();
  bool pressed = !level; // active-low

  rep.update(pressed);

  if (rep.fired()) {
    value++;
    Serial.print("value = ");
    Serial.println(value);
  }
}
