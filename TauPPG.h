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

        bool ledState; //true = on, false = off
    public:

        TauPPG();

        void begin();
        //Control LED
        void turnLEDON();
        void turnLEDOff();
        bool getLEDStatus() const;
        void setLEDCurrent(uint8_t val);
        uint8_t getLEDCurrent() const;


        //Amplifier gain control
        void setTIAGain(uint8_t gain);
        uint8_t getTIAGain() const;


        //Bandpass filter amplifier gain control
        void setPPGGain(uint8_t gain);
        uint8_t getPPGGain() const;


        //Read voltage of PPG circuit
        uint16_t getTIA() const;
        uint16_t getPPG() const;
};

#endif TauPPG_h