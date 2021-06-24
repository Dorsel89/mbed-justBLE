#include "mbed.h"
#include "phyphoxBle.h"
#include <chrono>
#include <cstdint>


//PinName LED = P0_17; //DISTANZ
//PinName LED = P0_4; //ELEHRE 
PinName LED = P0_23; //elehre version 2
DigitalOut myLED(LED); 

LowPowerTicker blinkTicker;

void powerOn() {
    myLED=!myLED;
    //ThisThread::sleep_for(100ms);
    //myLED=1;
}



int main() {

    myLED=1; //turn led off

    PhyphoxBLE::start("phyphox");              // start BLE

    blinkTicker.attach(&powerOn,1s);

    while (true) {                            // start loop.
        ThisThread::sleep_for(100ms);
    }
}
