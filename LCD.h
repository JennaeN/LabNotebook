/*
 * LCD.h
 *
 *  Created on: Oct 21, 2013
 *      Author: C15Jennae.Steinmiller
 *      Description: This library will act as a link between main.c and LCD.c.
 *      Each of these functions are used to interact with the LCD on the Geek Box
 *      to get the proper message scrolling across the LCD screen before and after button push.
 */

#ifndef LCD_H_
#define LCD_H_

void initSPI();	//Initializes the SPI

void LCDinit();	//Initialized the LCD on the Geek Box.

void LCDclr(); //Create a blank screen

void cursorToLineOne();	//Direct cursor to the first line for writing

void cursorToLineTwo(); //Direct cursor to second line for writing

int pollButton();	//B functionality - used to test button pushing

void writeDatatByte(char dataByte);

void writeString(char * string);	//Write the string of characters

void scrollString(char * string1, char * string2);	//Implement scrolling function

#endif /* LCD_H_ */
