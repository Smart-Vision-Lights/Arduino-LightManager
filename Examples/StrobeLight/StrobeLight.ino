/*
  LightManager Library - StrobeLight

 Demonstrates the use of strobe.  The LightManager
 library works with all SmartVisionLights lights that are compatible with the
 5 pin M12 connector.

 This sketch strobes the light 10 times with a 10% duty cycle.

  The circuit:
 * Light PNP pin to digital 3
 * Light Analog line to power supply 24v
 * Light GND to power supply GND and arduino GND
 * Light +24 to power supply 24v

 Library originally added 27 Jun 2023
 by Matthew J. Reynolds
 example added 27 Jun 2023
 by Matthew J. Reynolds

 This example code is in the public domain.

 https://github.com/Smart-Vision-Lights/Arduino-LightManager
*/

//include the library code:
#include <LightManager.h>

//initialize the library by assigning the PNP pin. The mode will default to PNP, and the analog will default to NULL.
const int triggerPin = 3;
LightManager light(triggerPin);

void setup() {
    //start a serial monitor:
    Serial.begin(9600);
    while(!Serial);
}

void loop() {
  // Strobe the light by setting the strobe parameters
  const int numberOfStrobes = 10;
  const int onTime = 100;
  const int offTime = 900;
  Serial.println("Strobing Light!");
  light.strobe(numberOfStrobes, onTime, offTime);
  Serial.println("Done Strobing!");

}