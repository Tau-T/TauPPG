//
// TauPPG.hpp
//
//
//Created by Matt Tao on 7.16.2020
//

#ifndef TauPPG_h
#define TauPPG_h

//Custon external libraries
#include "AD524X.h"

//Arduino Libraries
#include <Arduino.h>

/*Functions we need
turn LED on and off
control brightness of LED
control gain of transimpedance amplifier (TIA)
control gain of bandpass
*/



class TauPPG
{
    private:
        AD524X ad5242; //potentiometer to control gain of TIA and Bandpass

        uint8_t R_ledCurrent;
        uint8_t R_tiaGain;
        uint8_t R_bpfGain;

    public:

        TauPPG();
    void turnLEDON();
    void turnLEDOff();
    void setLEDCurrent();
    uint8_t getLEDCurrent() const;

    void setTIAGain();
    uint8_t getTIAGain() const;

    void setPPGGain();
    uint8_t getPBFGain() const;

    uint16_T GETtia();
    uint16_T GETbpf();
};

#endif TauPPG_h