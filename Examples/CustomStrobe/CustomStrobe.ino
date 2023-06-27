/*
  LightManager Library - CustomStrobe

 Demonstrates the creation of a custome strobe using lightOn and lightOff.  The LightManager
 library works with all SmartVisionLights lights that are compatible with the
 5 pin M12 connector.

 This sketch will show you how to create a custom strobe to trigger a light or other I/O device along with your strobe.

  The circuit:
 * Light PNP pin to digital 3
 * Light Analog line to power supply +24v
 * Light GND to power supply GND and arduino GND
 * Light +24 to power supply +24v
 * Camera trigger line on digital 5

 Library originally added 27 Jun 2023
 by Matthew J. Reynolds
 example added 27 Jun 2023
 by Matthew J. Reynolds

 This example code is in the public domain.
*/

// include the library code:
#include <LightManager.h>

// initialize the library by assigning the PNP pin. The mode will default to PNP, and the analog will default to NULL.
const int triggerPin = 3;
LightManager light(triggerPin);

// define your light on time and your light off time. Your on time will be equal to your camera exposure.
const int onTime = 100;
const int offTime = 900;

// define external camera trigger pin. We will use D5
const int cameraTriggerPin = 5

void setup() {
  // open a serial monitor
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Starting custom strobe!")

  // Set external camera pin starting state.
  digitalWrite(cameraTriggerPin, LOW);
}

void loop() {
  // put your strobe code here, to run repeatedly:
  light.lightOn();
  digitalWrite(cameraTriggerPin, HIGH);
  delay(onTime);
  digitalWrite(cameraTriggerPin, LOW);
  light.lightOff();
  delay(offTime);
}