#include <Arduino.h>
#include <GPIOUtils.h>

// Pins
static constexpr uint8_t PIN_TRIGGER_BTN = 2; // momentary button to GND
static constexpr uint8_t PIN_READ_BTN    = 3; // momentary button to GND

static constexpr uint8_t PIN_LATCH_LED   = 5; // shows latched state (peek)
static constexpr uint8_t PIN_READ_LED    = 6; // shows read-and-clear result

// Components
EdgeDetector triggerEdge(PIN_TRIGGER_BTN, INPUT_PULLUP);
EdgeDetector readEdge   (PIN_READ_BTN,    INPUT_PULLUP);

EventLatch event;

void setup()
{
  pinMode(PIN_LATCH_LED, OUTPUT);
  pinMode(PIN_READ_LED,  OUTPUT);

  triggerEdge.begin();
  readEdge.begin();

  event.begin(); // start LOW (no pending event)
}

void loop()
{
  // Sample inputs
  triggerEdge.read();
  readEdge.read();

  // Button on pin 2 triggers the event
  if (triggerEdge.fell())
  {
    event.trigger();
  }

  // LED on pin 5 reflects latched state (non-destructive)
  digitalWrite(PIN_LATCH_LED, event.peek() ? HIGH : LOW);

  // Button on pin 3 consumes the event (read-to-clear)
  if (readEdge.fell())
  {
    digitalWrite(PIN_READ_LED, event.read() ? HIGH : LOW);
  }
}
