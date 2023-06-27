#ifndef LIGHTMANAGER_h
#define LIGHTMANAGER_h

#include <Arduino.h>

enum TriggerType = {PNP = 0, NPN = 1}
enum DelayUnits = {MS = 0, US = 1}

class Light {
    private:
        uint8_t TRIGGER_PIN
        uint8_t TRIGGER_MODE
        uint8_t ANALOG_PIN
    public:
        void init(uint8_t triggerPin, TriggerType triggerMode = PNP, uint8_t analogPin = NULL);
        void lightOn();
        void lightOff();
        void strobe(int numberOfStrobes, int onTime, int offTime, DelayUnits units = MS);
        void setAnalogLevel(uint8_t level);
        void setTriggerPin(uint8_t triggerPin);
        void setAnalogPin(uint8_t analogPin);
        uint8_t getTriggerPin();
}

#endif