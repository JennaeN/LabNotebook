/*
 * ClockCalibration.c
 *
 *  Created on: Oct 24, 2013
 *      Author: C15Jennae.Steinmiller
 *      Description: Used to set the clock to 4 different clock speeds.
 */

#include <msp430.h>
#include "LCD.h"

void changeClockSpeed1(){

	BCSCTL1 = CALBC1_1MHZ;		//Set range
	DCOCTL = CALDCO_1MHZ;		//Set DCO step and modulation
}

void changeClockSpeed8(){

	BCSCTL1 = CALBC1_8MHZ;		//Set range
	DCOCTL = CALDCO_8MHZ;		//Set DCO step and modulation
}

void changeClockSpeed12(){

	BCSCTL1 = CALBC1_12MHZ;		//Set range
	DCOCTL = CALDCO_12MHZ;		//Set DCO step and modulation
}

void changeClockSpeed16(){

	BCSCTL1 = CALBC1_16MHZ;		//Set range
	DCOCTL = CALDCO_16MHZ;		//Set DCO step and modulation
}
