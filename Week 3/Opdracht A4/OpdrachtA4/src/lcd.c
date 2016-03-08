#include <avr/io.h>
#include <string.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lcd.h"

static void LcdWriteNibble(int isCommand,unsigned char dat)
{
	if(isCommand)
	{
		PORTC = dat & 0xF0;
		PORTC = PORTC | 0x08;
		_delay_ms(10);
		PORTC = 0x04;
		PORTC=(dat & 0x0F) << 4;
		PORTC = PORTC | 0x08;
		_delay_ms(10);
		PORTC = 0x00;

	}
	else
	{
		PORTC = dat & 0xF0;
		PORTC = PORTC | 0x0C;
		_delay_ms(10);
		PORTC = 0x04;
		PORTC=(dat & 0x0F) << 4;
		PORTC = PORTC | 0x0C;
		_delay_ms(10);
		PORTC = 0x00;

	}

}


void initLCD(void)
{
 	DDRC = 0b11111111;

 	_delay_ms(100);

 	// return home
 	LcdWriteNibble(1, 0x02 );
 	// mode: 4 bits interface data, 2 lines, 5x8 dots
 	_delay_ms(50);
 	LcdWriteNibble(1, 0x28 );
 	// display: on, cursor off, blinking off
 	_delay_ms(50);
 	LcdWriteNibble(1, 0x0C );
 	// entry mode: cursor to right, no shift
 	_delay_ms(50);
 	LcdWriteNibble(1, 0x06 );
 	// RAM address: 0, first position, line 1
 	_delay_ms(50);
 	clearScreen();

 	_delay_ms(100);
}

void printString(char* str, int length)
{
	int i, j;
	int rest;

		for (i = 0; i <length; i++)
		{
			LcdWriteNibble(0,str[i]);
		}
}
/*
	leftRight kan je kiezen tussen 0 en 1, 0 is naar schijven en 
	1 is naar links schuiven. 
	count kan je kiezen hoever die naar rechts of naar links schuift.
*/
void setXCursorPos(int leftRight,int count)
{
	for (int i=0; i<count; i++) {
		switch(leftRight)
		{
			case 0: LcdWriteNibble(1,0x18);		// shift rechts
				_delay_ms(2);
			break;	
			case 1: LcdWriteNibble(1,0x1c);		// shift links
				_delay_ms(2);
			break;
		}
	}
}

void shiftLeftRight(int isCommand)
{
	switch(isCommand)
	{
		case 0: LcdWriteNibble(1,0x18);		// shift rechts
		break;
		case 1: LcdWriteNibble(1,0x1c);		// shift links
		break;
	}
}

void setYCursorPos(int YPos)
{

	switch (YPos)
	{
		case 0:	LcdWriteNibble(1, 0x80);
		break;
		case 1:	LcdWriteNibble(1, 0xC0);
		break;
	}

}

void clearScreen()
{

	LcdWriteNibble(1,0b00000001);
	LcdWriteNibble(1,0b10000000);
}