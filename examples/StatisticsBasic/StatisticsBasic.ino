#include <gpioutils.h>

/*
  StatisticsBasic

  Prints running stats (min/max/mean) of loop interval in milliseconds.
  Open Serial Monitor at 115200.
*/

Statistics stats;
uint32_t lastPrint = 0;
uint32_t lastLoop = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial) { /* optional */ }
  lastLoop = millis();
}

void loop() {
  uint32_t now = millis();
  uint32_t dt = (uint32_t)(now - lastLoop);
  lastLoop = now;

  stats.add(dt);

  if ((uint32_t)(now - lastPrint) >= 1000) {
    lastPrint = now;
    Serial.print("count=");
    Serial.print(stats.count());
    Serial.print(" min=");
    Serial.print(stats.min());
    Serial.print(" max=");
    Serial.print(stats.max());
    Serial.print(" mean=");
    Serial.println(stats.meanf(), 3);
  }
}
