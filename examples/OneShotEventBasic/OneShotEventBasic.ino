/*
  OneShotEventBasic

  Demonstrates GPIOUtils::OneShotEvent as a logical (non-GPIO) one-shot.

  A trigger event causes the output to remain true for a fixed duration.
  This example uses Serial input as the trigger to emphasize that
  OneShotEvent does NOT own GPIO.

  Open the Serial Monitor and press any key to trigger the one-shot.
*/

#include <gpioutils.h>

constexpr uint32_t PULSE_MS = 500;

OneShotEvent pulse(PULSE_MS);

void setup() {
  Serial.begin(115200);
  while (!Serial) { /* wait for USB Serial if needed */ }

  Serial.println("OneShotEventBasic");
  Serial.println("Press any key to trigger the one-shot.");
}

void loop() {
  // Trigger the one-shot from a non-GPIO event
  if (Serial.available()) {
    Serial.read();        // consume one byte
    pulse.trigger();
    Serial.println("Triggered");
  }

  // Read logical one-shot state
  if (pulse.read()) {
    Serial.println("One-shot ACTIVE");
  }

  // No delay() required; timing is internal
}
