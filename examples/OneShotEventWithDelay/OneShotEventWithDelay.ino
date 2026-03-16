/*
  OneShotEventBasic

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
