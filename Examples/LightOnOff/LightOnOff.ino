/*
  LightManager Library - LightOnOff

 Demonstrates the use of lightOn and lightOff.  The LightManager
 library works with all SmartVisionLights lights that are compatible with the
 5 pin M12 connector.

 This sketch turns the light on with a serial message, and off with a serial message.

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
    Serial.println("Ready to control a light!");
    Serial.println("Enter one of the following commands:");
    Serial.println("'On' to turn on the light.");
    Serial.println("'Off' to turn off the light.");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.avaiable() > 0) {
    String input = Serial.readString();
    input.trim();
    if (input == "On") {
      light.lightOn();
      Serial.println("Light on!\n");
    } elseif (input == "Off") {
      light.lightOff();
      Serial.println("Light off!\n");
    } else {
      Serial.print("Invalid Command!");
      Serial.println("Enter one of the following commands:");
      Serial.println("'On' to turn on the light.");
      Serial.println("'Off' to turn off the light.");
    }
  }
}