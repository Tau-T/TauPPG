//
// TauPPG.hpp
//
//
//Created by Matt Tao 
//

#include "TauPPG.h"

/*Functions we need
turn LED on and off
control brightness of LED
control gain of transimpedance amplifier (TIA)
control gain of bandpass
*/
const uint8_t ledPin = 30;

TauPPG()
{
}

void begin
{
    pinMode(ledPin, OUTPUT); 
}
void turnLEDON() const
{
    digitalWrite(ledPin, HIGH);
}

void turnLEDOff() const
{
    digitalWrite(ledPin, LOW);
}
    void setLEDCurrent();
    uint8_t getLEDCurrent() const;

    void setTIAGain();
    uint8_t getTIAGain() const;

    void setPPGGain();
    uint8_t getPBFGain() const;
