/*******************************************
 * Author: C2C Jennae Steinmiller
 * Created: 22 Oct 2013
 * Description: Main.c is used to handle the overall flow of information in Lab04_LCD.
 * It calls LCD.h and LCD.c in order to carry out functionality. As a whole, Lab04_LCD
 * asks the user to push button 1, 2, or 3. After pressing a button, a corresponding message
 * as well as a required message will scroll continuously across the LCD screen.
 * Documentation: I received help from C2C Ryan Hub regarding button pushing and scrolling.
 *******************************************/
#include <msp430.h>
#include "LCD.h"

/*
 * main.c
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer


	//Create strings of text to output to the user
	char * requiredMsg = "ECE382 is my favorite class! ";
	char * prompt = "Message?";
	char * promptKey = "Press123";

	char * message1 = "Learn from yesterday... ";

	char * message2 = "Live for today... ";

	char * message3 = "Hope for tomorrow. ";


	//SPI initialization function
	initSPI();

	// LCD initialization function
	LCDinit();

	//Clear the LCD screen
	LCDclr();

	//Position the cursor to write the prompt to the user.
	cursorToLineOne();
	writeString(prompt);

	cursorToLineTwo();
	writeString(promptKey);

	int buttonPushed = 0;
	//A different value is returned depending on which button is pushed.
	buttonPushed = pollButton();

	//Move the selected message to the screen
	if (buttonPushed == 1) {
		scrollString(requiredMsg, message1);
	}

	if (buttonPushed == 2) {
		scrollString(requiredMsg, message2);
	}

	if (buttonPushed == 3) {
		scrollString(requiredMsg, message3);
	}

	return 0;
}
