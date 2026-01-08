#include <gpioutils.h>

static const uint8_t PIN_POT = A0;

// Example: your pot doesn't hit the rails.
// Replace these numbers with what you actually observe.
AnalogCalibrator cal(65, 970);

void setup() {
  Serial.begin(115200);
  while (!Serial) { /* optional */ }
  Serial.println("AnalogCalibratorBasic: reading A0, printing normalized + mapped values.");
}

void loop() {
  int raw = analogRead(PIN_POT);

  float u = cal.normalize(raw);            // 0..1
  int pwm = (int)cal.map_int(raw, 0, 255); // 0..255
  float deg = cal.map_float(raw, 0.0f, 270.0f);

  Serial.print("raw=");
  Serial.print(raw);
  Serial.print("  u=");
  Serial.print(u, 4);
  Serial.print("  pwm=");
  Serial.print(pwm);
  Serial.print("  deg=");
  Serial.println(deg, 1);

  delay(50); // only for serial readability in this demo
}
