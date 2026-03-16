/*
  OneShotEventWithDelay

  Demonstrates GPIOUtils::OneShotEvent as a logical (non-GPIO) one-shot,
  with initial activation delay.

  A trigger event causes the output to delay for 1 s, and then remain
  true for 500 ms.

  This example uses Serial input as the trigger to emphasize that
  OneShotEvent does NOT own GPIO.

  Open the Serial Monitor and press any key to trigger the one-shot.
*/

#include <GPIOUtils.h>

constexpr uint32_t PULSE_MS = 500;
constexpr uint32_t DELAY_MS = 1000;

OneShotEvent pulse(PULSE_MS, DELAY_MS);

void setup() {
  Serial.begin(115200);
  while (!Serial) { /* wait for USB Serial if needed */ }

  Serial.println("OneShotEventWithDelay");
  Serial.println("Press Enter key to trigger the one-shot.");
}

bool prev_state = LOW;

void loop() {
  // Trigger the one-shot from a non-GPIO event
  if (Serial.available()) {
    Serial.read();        // consume one byte
    pulse.trigger();
    Serial.println("Triggered");
    Serial.println("Delaying 1s");
  }

  // Read logical one-shot state
  if (prev_state == LOW && pulse.read()) {
    Serial.println("One-shot went HIGH");
    prev_state = HIGH;
  } else if (prev_state == HIGH && !pulse.read()) {
    Serial.println("One-shot went LOW");
    prev_state = LOW;
  }

  // No delay() required; timing is internal
}
