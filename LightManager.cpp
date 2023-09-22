#include "LightManager.h"

LightManager::LightManager(uint8_t triggerPin, uint8_t triggerMode = PNP, uint8_t analogPin = NULL) {
    TRIGGER_PIN = triggerPin;
    TRIGGER_MODE = triggerMode;
    if (analogPin != NULL) ANALOG_PIN = analogPin;
    digitalWrite(TRIGGER_PIN, LOW);
}

void LightManager::lightOn() {
    digitalWrite(TRIGGER_PIN, HIGH);
}

void LightManager::lightOff() {
    digitalWrite(TRIGGER_PIN, LOW);
}

void LightManager::strobe(int numberOfStrobes, int onTime, int offTime, uint8_t units = MILLIS) {
    for (int x = 0; x < numberOfStrobes; x++) {
        lightOn();
        if (units == MILLIS) {
            delay(offTime);
        }
        else{
            delayMicroseconds(offTime);
        }
        lightOff();
        if (units == MILLIS) {
            delay(offTime);
        }
        else{
            delayMicroseconds(offTime);
        }
    }
}

void LightManager::setAnalogLevel(uint8_t level) {
    analogWrite(ANALOG_PIN, level);
}

void LightManager::setTriggerPin(uint8_t triggerPin) {
    TRIGGER_PIN = triggerPin;
    pinMode(TRIGGER_PIN, OUTPUT);
    digitalWrite(TRIGGER_PIN, LOW);
}

void LightManager::setAnalogPin(uint8_t analogPin) {
    ANALOG_PIN = analogPin;
    analogWrite(ANALOG_PIN, 255);
}

uint8_t LightManager::getTriggerPin() {
    return TRIGGER_PIN;
}