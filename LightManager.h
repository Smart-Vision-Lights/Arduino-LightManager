#ifndef LIGHTMANAGER_h
#define LIGHTMANAGER_h

#include <Arduino.h>

#define PNP (0)
#define NPN (1)
#define MILLIS (0)
#define MICROS (1)

class LightManager {
    private:
        uint8_t TRIGGER_PIN;
        uint8_t TRIGGER_MODE;
        uint8_t ANALOG_PIN;
    public:
        LightManager(uint8_t triggerPin, uint8_t triggerMode = PNP, uint8_t analogPin = NULL);
        void lightOn();
        void lightOff();
        void strobe(int numberOfStrobes, int onTime, int offTime, uint8_t units = MILLIS);
        void setAnalogLevel(uint8_t level);
        void setTriggerPin(uint8_t triggerPin);
        void setAnalogPin(uint8_t analogPin);
        uint8_t getTriggerPin();
};

#endif