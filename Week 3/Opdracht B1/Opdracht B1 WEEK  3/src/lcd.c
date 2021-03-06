#include <avr/io.h>
#include <string.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lcd.h"

static void LcdWriteNibble(int isCommand,unsigned char dat)
{
	if(isCommand == 1)
	{
		PORTC = dat & 0xF0;
		PORTC = PORTC | 0x08;
		_delay_ms( 1);
		PORTC = 0x04;
		PORTC=(dat & 0x0F) << 4;
		PORTC = PORTC | 0x08;
		_delay_ms( 1 );
		PORTC = 0x00;

	}
	else
	{
		PORTC = dat & 0xF0;
		PORTC = PORTC | 0x0C;
		_delay_ms( 1 );
		PORTC = 0x04;
		PORTC=(dat & 0x0F) << 4;
		PORTC = PORTC | 0x0C;
		_delay_ms( 1 );
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

void display_text(char* str, int length)
{
	int i, j;
	int rest;

		for (i = 0; i <length; i++)
		{
			LcdWriteNibble(0,str[i]);
		}
}




void set_cursor(int YPos)
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

	LcdWriteNibble(1,0x01);
}