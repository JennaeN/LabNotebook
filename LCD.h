/*
 * LCD.h
 *
 *  Created on: Oct 21, 2013
 *      Author: C15Jennae.Steinmiller
 *      Description: This library will interact with the LCD on the Geek Box.
 */

#ifndef LCD_H_
#define LCD_H_

void initSPI();	//Initializes the SPI

void LCDdelay();	//Will use __delay_cycles(num_of_cycles)

void LCDinit();	//Initialized the LCD on the Geek Box.

void cursorToLineOne();	//Direct cursor to the first line for writing

void cursorToLineTwo(); //Direct cursor to second line for writing

void poll_button();	//B functionality - used to test button pushing

void writeChar(char asciiChar);	//Obtain a character

void writeString(char string);	//Write the string of characters

void scrollString(char string1, char string2);	//Implement scrolling function

#endif /* LCD_H_ */
