#include <GPIOUtils.h>

constexpr uint8_t POT_PIN = A0;
constexpr int DEAD_BAND = 2;

Dejitter pot(POT_PIN, DEAD_BAND);

void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  pot.begin();
}

void loop() {
  int raw = analogRead(POT_PIN);
  int clean = pot.read();
  Serial.print(raw);
  Serial.print('\t');
  Serial.println(clean);
  delay(20);
}
