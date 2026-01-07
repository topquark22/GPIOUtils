#include <gpioutils.h>

constexpr uint8_t POT_PIN = A0;
constexpr uint8_t LED_PIN = 5;

RateLimiter lim(300.0f, 600.0f);

void setup() {
  Serial.begin(115200); // DEBUG
  pinMode(POT_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  lim.begin();
}

void loop() {
  int adc = analogRead(POT_PIN);
  float target = (adc * 255.0f) / 1023.0f;
  Serial.println(target); 
  float y = lim.read(target);
  analogWrite(LED_PIN, (int)(y + 0.5f));
}
