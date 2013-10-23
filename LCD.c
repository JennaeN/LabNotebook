/*
 * LCD.c
 *
 *  Created on: Oct 22, 2013
 *      Author: C15Jennae.Steinmille
 */

int LCDdata, LCDsend, LCDcon; //LCDdata holds four bits to send to LCD, LCDsend holds 8 bits to send, LCDcon controls bits upper byte (E = 80, RS = 40, WR = 20)

char requiredMsg = "ECE382 is my favorite class!";
char message1 = "Does it work?";
char message2 = "I'm not sure yet...";
char message3 = "Eureka!";
char message = "Message?                                Press123#";



clr.b &DCOCTL;Select lowest DCOx and MODx settings

mov.b &CALBC1_1MHZ, &BCSCTL1;Set range
mov.b &CALDCO_1MHZ, &DCOCTL;Set DCO step and modulation

//Initialize variables
int pushBtn1 = 0, pushBtn2 = 0, counter = 0, message = 0;

// call SPI initialization subroutine
initSPI();

// LCD Initialization - you'll know it works when your LCD goes blank
LCDinit();

//Clear the LCD screen
LCDclr();

//Move a message to the screen
prompt( string);

//---------------------------------------------------
// Subroutine Name: prompt
// Author: C2C Jennae Steinmiller, USAFA Exchange
// Function: code used for writing to the LCD
// Inputs: r7
// Outputs: r7
// Subroutines used: LCDWRT8, LCDDELAY1, LCDSEND
//---------------------------------------------------

void prompt(string){
int checkEnd = 0;
while (checkEnd != 0x23){
LCDsend = string; //send data in r7 to be written
LCD_write_8(LCDsend);
delayMicro();
string ++;  //increment for repeat(Can I increment like this?)
checkEnd = string;
}
}
//---------------------------------------------------
// Function Name: initSPI
// Author: C2C Jennae Steinmiller, USAFA Exchange
// Function: Initializes the SPI subsytem.
// Inputs: none
// Outputs: BIT0, BIT5, BIT6, BIT7
//---------------------------------------------------
void initSPI(){

UCB0CTL1 |= UCSWRST;

UCB0CTL0 |= UCCKPH|UCMSB|UCMST|UCSYNC;

UCB0CTL1 |= UCSSEL1;                       //selects clock to use

UCB0STAT |= UCLISTEN;                      //enables internal loopback

P1DIR |= BIT0;							//For my SS

P1SEL |= BIT5;                            // make UCB0CLK available on P1.5
P1SEL2 |= BIT5;

P1SEL |= BIT7;                             // make UCB0SSIMO available on P1.7
P1SEL2 |= BIT7;

P1SEL |= BIT6;                             // make UCB0SSOMI available on P1.6
P1SEL2 |= BIT6;

UCB0CTL1 |= UCSWRST;                       //enable subsystem
}

//---------------------------------------------------
// Function Name: Set_SS_hi
// Author: C2C Jennae Steinmiller, USAFA Exchange
// Function:  Sets your slave select to high (disabled).
// Inputs: none
// Outputs: BIT0
//---------------------------------------------------
char set_SS_hi() {

	P1OUT |= BIT0;
	return BIT0;
}
//---------------------------------------------------
// Function Name: Set_SS_lo
// Author: C2C Jennae Steinmiller, USAFA Exchange
// Function:  Sets your slave select to low (enabled)
// Inputs: none
// Outputs: BIT0
//---------------------------------------------------
char set_SS_lo() {

	P1OUT &=~ BIT0;
	return BIT0;
}
//---------------------------------------------------
// Function Name: delayMicro()
// Author: C2C Jennae Steinmiller, USAFA Exchange
// Function: Implements a .45 microsecond delay
// Inputs: none
// Outputs: none
//---------------------------------------------------

void delayMicro() {

//delay for 9 cycles
	__delay_cycles(9);
}

//---------------------------------------------------
// Function Name: delayMacro()
// Author: C2C Jennae Steinmiller, USAFA Exchange
// Function: Implements a 1.65 millisecond delay
// Inputs: none
// Outputs: none
//---------------------------------------------------

void delayMacro() {

//delay for 0x025f cycles
	__delay_cycles(607);
}

//---------------------------------------------------
// Function Name: LCDCLR
// Author: Capt Todd Branchflower, USAF
// Function: Clears LCD, sets cursor to home
// Inputs: none
// Outputs: none
// Subroutines used: LCDWRT8, LCDDELAY1, LCDDELAY2
//---------------------------------------------------
void LCDclr(){
LCDcon = 0;                                             //clear RS
LCDsend = 1;                                           //send clear
LCD_write_8(LCDsend);
delayMicro();
LCDcon = 0x40;                                          //set RS
delayMacro();
}

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
//---------------------------------------------------
// Subroutine Name: LCDWRT4
// Author: Capt Todd Branchflower, USAF
// Function: Send 4 bits of data to LCD via SPI.
// sets upper four bits to match LCDCON.
// Inputs: LCDCON, LCDDATA
// Outputs: none
// Subroutines used: LCDDELAY1
//---------------------------------------------------
void LCD_write_4( sendByte) {

	sendByte = LCDdata;		//load data to send
	sendByte &= 0x0F;                                               // ensure upper half of byte is clear
	sendByte	|= LCDcon;                                         // set LCD control nibble
	sendByte &= 0x7F;                                              // set E low
	SPI_send( sendByte);		//call    #SPI_send
	delayMicro();
	sendByte |= 0x80;                                               // set E high
	SPI_send(sendByte);		//call    #SPI_send
	delayMicro();
	sendByte &= 0x7F;                                               // set E low
	SPI_send( sendByte);		//call    #SPI_send
	delayMicro();
}

void LCD_write_8(char byteToSend)
{
    unsigned char sendByte = byteToSend;

    sendByte &= 0xF0;

    sendByte = sendByte >> 4;               // rotate to the right 4 times

    LCD_write_4(sendByte);

    sendByte = byteToSend;

    sendByte &= 0x0F;

    LCD_write_4(sendByte);
}

void SPI_send(char byteToSend) {
	char readByte;

	set_SS_lo();

	UCB0TXBUF = byteToSend;

	while (!(UCB0RXIFG & IFG2)) {
		// wait until you've received a byte
	}

	readByte = UCB0RXBUF;

	set_SS_hi();
}
