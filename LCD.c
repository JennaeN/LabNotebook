/*
 * LCD.c
 *
 *  Created on: Oct 22, 2013
 *      Author: C15Jennae.Steinmiller
 */

#include <msp430.h>
#include "LCD.h"
#define RS_MASK 0x40

char LCDcon = 0; 	//LCDcon controls bits upper byte (E = 80, RS = 40, WR = 20)

void initSPI() {

	UCB0CTL1 |= UCSWRST;
	UCB0CTL0 |= UCCKPH | UCMSB | UCMST | UCSYNC;
	UCB0CTL1 |= UCSSEL1;                       //selects clock to use
	//UCB0STAT |= UCLISTEN;                      //enables internal loopback

	P1DIR |= BIT0;							//For my SS

	P1SEL |= BIT5;                            // make UCB0CLK available on P1.5
	P1SEL2 |= BIT5;

	P1SEL |= BIT7;                           // make UCB0SSIMO available on P1.7
	P1SEL2 |= BIT7;

	P1SEL |= BIT6;                           // make UCB0SSOMI available on P1.6
	P1SEL2 |= BIT6;

	UCB0CTL1 &= ~UCSWRST;                       //enable subsystem
}

void writeCommandNibble(char commandNibble);
void writeCommandByte(char commandByte);
void SPI_send(char byteToSend);
void delayMicro();

void LCDinit() {
	writeCommandNibble(0x03);
	writeCommandNibble(0x03);
	writeCommandNibble(0x03);
	writeCommandNibble(0x02);

	writeCommandByte(0x28);
	writeCommandByte(0x0C);
	writeCommandByte(0x01);
	writeCommandByte(0x06);
	writeCommandByte(0x01);
	writeCommandByte(0x02);

	SPI_send(0);
	delayMicro();
}

void LCDclr() {
	writeCommandByte(1);
}

void LCD_write_8(char byteToSend);
void delayMilli();

void writeDataByte(char dataByte) {
	LCDcon |= RS_MASK;
	LCD_write_8(dataByte);
	delayMilli();
}

void writeString(char * string) {
	int i = 0;
	LCDcon |= RS_MASK;
	for (i = 0; i < 8; i++) {
		LCD_write_8(string[i]);	//send data in the string to be written
		delayMilli();
	}
}

void scrollString(char * string1, char * string2) {
	unsigned int i = 0, count = 0;

	while (1) {
		cursorToLineOne();
		for (i = 0; i < 8; i++) {
			writeDataByte(string1[(i+count)]);	//send data in the string to be written
			if (count + i >= 28){
						count = 0;
			}
		}

		cursorToLineTwo();
		for(i = 0; i < 8; i++){
			writeDataByte(string2[(i+count)]);	//send data in the string to be written
			if (count + i >= string2.length()){
						count = 0;
			}
		}
		count++;
		__delay_cycles(0xFFFF);
		__delay_cycles(0xFFFF);
		__delay_cycles(0xFFFF);
		__delay_cycles(0xFFFF);
		__delay_cycles(0xFFFF);
		__delay_cycles(0xFFFF);


		LCDclr();
		//cursorToLineOne();

	}
}

char set_SS_hi() {

	P1OUT |= BIT0;
	return BIT0;
}

char set_SS_lo() {

	P1OUT &= ~BIT0;
	return BIT0;
}

void delayMicro() {
//delay for 9 cycles
	__delay_cycles(0x09);
}

void delayMilli() {

//delay for 0x025f cycles
	__delay_cycles(0x025F);
}

void LCD_write_4(char sendByte);

void writeCommandNibble(char commandNibble) {
	LCDcon &= ~RS_MASK;
	LCD_write_4(commandNibble);
	delayMilli();
}

void writeCommandByte(char commandByte) {
	LCDcon &= ~RS_MASK;
	LCD_write_8(commandByte);
	delayMilli();
}

void LCD_write_4(char sendByte) {

	sendByte &= 0x0F;                      // ensure upper half of byte is clear
	sendByte |= LCDcon;                                // set LCD control nibble
	sendByte &= 0x7F;                                              // set E low
	SPI_send(sendByte);		//call    #SPI_send
	delayMicro();
	sendByte |= 0x80;                                              // set E high
	SPI_send(sendByte);		//call    #SPI_send
	delayMicro();
	sendByte &= 0x7F;                                               // set E low
	SPI_send(sendByte);		//call    #SPI_send
	delayMicro();
}

void cursorToLineTwo() {
	writeCommandByte(0xC0);
}

void cursorToLineOne() {
	writeCommandByte(0x80);
}

void LCD_write_8(char byteToSend) {
	unsigned char sendByte = byteToSend;

	sendByte &= 0xF0;

	sendByte = sendByte >> 4;               // rotate to the right 4 times

	LCD_write_4(sendByte);

	sendByte = byteToSend;

	sendByte &= 0x0F;

	LCD_write_4(sendByte);
}

void SPI_send(char byteToSend) {
	volatile char readByte;

	set_SS_lo();

	UCB0TXBUF = byteToSend;

	while (!(UCB0RXIFG && IFG2)) {
		// wait until you've received a byte
	}

	readByte = UCB0RXBUF;

	set_SS_hi();
}
