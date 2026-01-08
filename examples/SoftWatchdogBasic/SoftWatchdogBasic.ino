#include <gpioutils.h>

/*
  SoftWatchdogBasic

  A software watchdog that detects when expected activity stops.

  - LED on pin 5 turns ON when watchdog has expired.
  - Every ~200ms we "kick" the watchdog unless the user holds the button.

  Button on pin 2 to GND (INPUT_PULLUP):
    Hold the button to simulate a stalled system (no kicks).
*/

static const uint8_t PIN_BTN = 2;
static const uint8_t PIN_LED = 5;

static const uint32_t KICK_PERIOD_MS = 200;
static const uint32_t TIMEOUT_MS = 800; // must be > KICK_PERIOD_MS

SoftWatchdog wd(TIMEOUT_MS);

uint32_t lastKickAttemptMs = 0;
uint32_t lastPrintMs = 0;

void setup()
{
  pinMode(PIN_BTN, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);

  Serial.begin(115200);

  wd.begin();
  lastKickAttemptMs = millis();
  lastPrintMs = millis();
}

void loop()
{
  const uint32_t now = millis();
  const bool held = (digitalRead(PIN_BTN) == LOW);

  // Kick on a schedule unless the button is held down.
  if ((uint32_t)(now - lastKickAttemptMs) >= KICK_PERIOD_MS)
  {
    lastKickAttemptMs = now;
    if (!held)
    {
      wd.kick();
    }
  }

  // LED ON if expired, OFF otherwise.
  digitalWrite(PIN_LED, wd.expired() ? HIGH : LOW);

  // Optional status print once per second.
  if ((uint32_t)(now - lastPrintMs) >= 1000)
  {
    lastPrintMs = now;
    Serial.print("held=");
    Serial.print(held ? "yes" : "no");
    Serial.print(" ageMs=");
    Serial.print(wd.ageMs());
    Serial.print(" timeoutMs=");
    Serial.print(wd.timeoutMs());
    Serial.print(" expired=");
    Serial.println(wd.expired() ? "YES" : "no");
  }
}
