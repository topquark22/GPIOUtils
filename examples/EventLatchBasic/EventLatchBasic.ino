#include <Arduino.h>
#include <GPIOUtils.h>

using namespace gpioutils;

// Pins
static constexpr uint8_t PIN_BUTTON = 2;   // momentary button to GND
static constexpr uint8_t PIN_LED    = 5;   // LED

// Components
EdgeDetector buttonEdge(PIN_BUTTON, INPUT_PULLUP);
EventLatch   event;

void setup()
{
  pinMode(PIN_LED, OUTPUT);

  buttonEdge.begin();
  event.begin();   // start LOW (no pending event)
}

void loop()
{
  // Update edge detector
  buttonEdge.update();

  // On falling edge (button press), latch an event
  if (buttonEdge.falling())
  {
    event.trigger();
  }

  // Poll the event latch (read-to-clear)
  if (event.read())
  {
    digitalWrite(PIN_LED, HIGH);
  }
  else
  {
    digitalWrite(PIN_LED, LOW);
  }
}
