#include <GPIOUtils.h>

constexpr uint8_t BUTTON_PIN = 2;
constexpr uint8_t LED_PIN    = 5;

constexpr uint32_t DEBOUNCE_MS = 25;
constexpr uint32_t BLINK_MS    = 250;

// Active-low pushbutton on pin 2 using INPUT_PULLUP.
Debounce button(BUTTON_PIN, INPUT_PULLUP, DEBOUNCE_MS);

// Blink timer: toggles LED state every 250 ms while button is held.
PeriodicTimer blink(BLINK_MS);

bool led_state = false;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    button.begin();
    blink.start();
}

void loop() {
    // Update debounced button state.
    const bool pressed = (button.read() == LOW);

    if (!pressed) {
        // Button not held: LED remains off.
        led_state = false;
        digitalWrite(LED_PIN, LOW);
        return;
    }

    // While button is held, blink continuously.
    if (blink.tick()) {
        led_state = !led_state;
        digitalWrite(LED_PIN, led_state ? HIGH : LOW);
    }
}