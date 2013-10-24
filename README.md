ClockCalibration
================

Allows the user to change between four different clock speeds when using the MSP430. The clock 
speeds are 1MHz, 8MHz, 12MHz, and 16MHz. There is a different function for each clock length.

API - ClockCalibration.h

ClockCalibration.h calls 4 different functions - one for each different clock speed. They are:

void changeClockSpeed1();
void changeClockSpeed8();
void changeClockSpeed12();
void changeClockSpeed16();

After calling one of these functions, the clock speed will change. No input or output is necessary.

USAGE - ClockCalibration is used to changed the speed of the clock in the MSP430.
This can be helpful when writing code used on many different machines. It is useful because 
the delays will not need to be calculated for each chip in order to work properly - the delay (based
on universal clock times) will be the same across the board. 
