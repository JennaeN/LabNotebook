/*
 * ClockCalibration.c
 *
 *  Created on: Oct 24, 2013
 *      Author: C15Jennae.Steinmiller
 */

#include <msp430.h>
#include "LCD.h"

void changeClockSpeed1(){
	//DCOCTL = 0;		//Select lowest DCOx and MODx settings

	BCSCTL1 = CALBC1_1MHZ;		//Set range
	DCOCTL = CALDCO_1MHZ;		//Set DCO step and modulation
}

void changeClockSpeed8(){
	//DCOCTL = 0;		//Select lowest DCOx and MODx settings

	BCSCTL1 = CALBC1_8MHZ;		//Set range
	DCOCTL = CALDCO_8MHZ;		//Set DCO step and modulation
}

void changeClockSpeed12(){
	//DCOCTL = 0;		//Select lowest DCOx and MODx settings

	BCSCTL1 = CALBC1_12MHZ;		//Set range
	DCOCTL = CALDCO_12MHZ;		//Set DCO step and modulation
}

void changeClockSpeed16(){
	DCOCTL = 0;		//Select lowest DCOx and MODx settings

	BCSCTL1 = CALBC1_16MHZ;		//Set range
	DCOCTL = CALDCO_16MHZ;		//Set DCO step and modulation
}
