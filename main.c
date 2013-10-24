#include <msp430.h>
#include "LCD.h"


/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    char * requiredMsg = "ECE382 is my favorite class!";
    char * message1 = "Does it work?";
    //char * message2 = "I'm not sure yet...";
    //char * message3 = "Eureka!";
    //char * prompt = "Message?                                Press123";

    //SPI initialization function
    initSPI();

    // LCD initialization function
    LCDinit();

    //Clear the LCD screen
    LCDclr();

    //writeDataByte();
    cursorToLineOne();

    //writeString(prompt);
    //Move a message to the screen
    scrollString(requiredMsg, message1);

    //scrollString(message1);
	return 0;
}
