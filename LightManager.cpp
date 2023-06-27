#include "LightManager.h"

LightManager::init(uint8_t triggerPin, TriggerType triggerMode = PNP, uint8_t analogPin = NULL) {
    TRIGGER_PIN = triggerPin;
    TRIGGER_MODE = triggerMode;
    if (analogPin != NULL) ANALOG_PIN = analogPin;
    digitalWrite(TRIGGER_PIN, LOW);
}

LightManager::lightOn() {
    digitalWrite(TRIGGER_PIN, HIGH);
}

LightManager::lightOff() {
    digitalWrite(TRIGGER_PIN, LOW);
}

LightManager::strobe(int numberOfStrobes, int onTime, int offTime, DelayUnits units = MS) {
    for (int x = 0; x < numberOfStrobes; x++) {
        lightOn();
        if (units == MS)
            delay(onTime);
        else
            delayMicroseconds(onTime);
        lightOff();
        if (units == MS) {
            delay(offTime);
        }
        else{
            delayMicroseconds(offTime);
        }
    }
}

LightManager::setAnalogLevel(uint8_t level) {
    analogWrite(ANALOG_PIN, level);
}

LightManager::setTriggerPin(uint8_t triggerPin) {
    TRIGGER_PIN = triggerPin;
    pinMode(TRIGGER_PIN, OUTPUT);
    digitalWrite(TRIGGER_PIN, LOW);
}

LightManager::setAnalogPin(uint8_t analogPin) {
    ANALOG_PIN = analogPin;
    analogWrite(ANALOG_PIN, 255);
}

LightManager::getTriggerPin() {
    return TRIGGER_PIN;
}