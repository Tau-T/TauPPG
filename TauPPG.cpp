//
//TauPPG.hpp
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
/* Abbreviations
PPG
BPF
*/


const uint8_t ledPin = 30;
const uint8_t ppgPin = A4; 
const uint8_t tiaPin = A5;
const uint8_t ad5171_address = 0x2D;
const uint8_t ad5242_address = 0x2C;
//complete
TauPPG::TauPPG()
{
}
//Should be called before setup 

//Initializes functions, member variables, and member objects of the PPG class
//Must be called before setup in .ino code
void TauPPG::begin()
{
    pinMode(ledPin, OUTPUT); 
    turnLEDOff();
    analogReadResolution(12); //0 and 4095 = 12 bits

    setLEDCurrent(63); //smallest LED current by default

    //AD5242 digital potentiometer
    //Controls the gain of the photometric front-end
    ad5242 = AD524X(0x2c);
}

//Turns on LED by writing LOW to pin LED is drivin using NPN bipolar 
// junction transistor (BFT)
void TauPPG::turnLEDON()
{
    digitalWrite(ledPin, HIGH);
    ledState = true;
}
//Turns off LED by writing LOW to pin LED is drivin using NPN bipolar 
// junction transistor (BFT)
void TauPPG::turnLEDOff()
{
    digitalWrite(ledPin, LOW);
    ledState = false;
}
//Returns if LED is on or off
bool TauPPG::getLEDStatus() const
{
    return ledState;
}
//void TauPPG::setLEDCurrent(uin8_t val)
//val- value to write to AD5171. Must be between 0 and 63.

//Writes to digital potentiometer (AD5171 in this version)
//Code from arduino potentiometer digial 
//"val" has an inerse relationship with LED current
// As val goes up, resistance goes up, LED current goes down
void TauPPG::setLEDCurrent(uint8_t val)
{
    if(val > 63) val = 63;
    Wire.beginTransmission(ad5171_address); //address in datasheet
    Wire.write(byte(0x00)); //sends instruction byte
    Wire.write(val); //sends potentiometer value byte
    Wire.endTransmission(); //stops transmitting

    R_ledCurrent = val;
}


//Returns LED current
uint8_t TauPPG::getLEDCurrent() const
{
    return R_ledCurrent;
}



//void TauPPG::setTIAGain(uint8_t gain)
//gain      value between 0-255 to set resistance of digital potentiometer
// 
//Sets gain of digital potentiometer connected to transimpedance amplifer. 
//As gain increases, resistance of potentiometer increases, gain of TIA
//increases, output voltage increases
void TauPPG::setTIAGain(uint8_t gain)
{
    //
    ad5242.write(0,gain);
    R_tiaGain = gain;
}
//Returns TIA gain setting of digital potentiometer
uint8_t TauPPG::getTIAGain() const
{
    return(R_tiaGain);
}
//finished
//Reads voltage of TIA
uint16_t TauPPG::getTIA() const
{ 
    return analogRead(tiaPin);
}
//Returns gain setting of PPG bandpass filter
uint8_t TauPPG::getPPGGain() const
{
    return(R_bpfGain);
}

//void TauPPG::setPPGGain(uint8_t gain)
//gain      value between 0-255 to set resistance of digital potentiometer
// 
//Sets gain of digital potentiometer connected to transimpedance amplifer. 
//As gain increases, resistance of potentiometer increases, gain of bandpass
//increases, output voltage increases
void TauPPG::setPPGGain(uint8_t gain)
{
    ad5242.write(1,gain);
    R_bpfGain = gain;
}
//finished 
//Reads voltage of transimpedance amplifier
uint16_t TauPPG::getPPG() const
{
    return analogRead(ppgPin);
}
