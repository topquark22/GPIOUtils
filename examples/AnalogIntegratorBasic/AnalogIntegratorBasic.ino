#include <GPIOUtils.h>

/*
  AnalogIntegratorBasic

  Integrates a normalized potentiometer (0..1) over time, producing "seconds at full scale".

  Hook a pot wiper to A0.
  Open Serial Monitor at 115200.
*/

static const uint8_t PIN_A = A0;

AnalogIntegrator integ(1.0f); // scale factor

uint32_t lastPrint = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial) { /* optional */ }
}

void loop() {
  uint16_t adc = analogRead(PIN_A);
  float x = adcToFloat(adc);      // 0..1
  float area = integ.update(x);   // x * seconds

  uint32_t now = millis();
  if ((uint32_t)(now - lastPrint) >= 250) {
    lastPrint = now;
    Serial.print("x=");
    Serial.print(x, 3);
    Serial.print(" integral=");
    Serial.println(area, 3);
  }
}
