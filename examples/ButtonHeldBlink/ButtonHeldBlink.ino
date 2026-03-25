#include <GPIOUtils.h>

constexpr uint8_t BUTTON_PIN = 2;
constexpr uint8_t LED_PIN    = 5;

constexpr uint32_t DEBOUNCE_MS = 25;
constexpr uint32_t BLINK_MS    = 250;

// Active-low pushbutton on pin 2 using INPUT_PULLUP.
Debounce button(BUTTON_PIN, INPUT_PULLUP, DEBOUNCE_MS);

// Blink timer: toggles LED state every 250 ms while button is held.
PeriodicTimer blink(BLINK_MS);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  button.begin();
  blink.start();
}

void loop() {

  // active-low button pressed condition
  const bool condition = !button.read(); 

  if (!condition) {
  // Button not held: LED remains off.
    digitalWrite(LED_PIN, LOW);
  } else {
  // While button is held, blink continuously.
    if (blink.tick()) {
      digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    }
  }

  // Do something else...

}