#include <avr/io.h>
#include <string.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lcd.h"



static LcdWriteNibble(int isCommand,unsigned char dat)
{
	if(isCommand)
	{
		PORTC = dat & 0xF0;
		PORTC = PORTC | 0x08;
		_delay_ms( 1 );
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

void initLCD()
{
	LcdWriteNibble(1,0x02);
	LcdWriteNibble(1,0x28);
	LcdWriteNibble(1,0x0C);
	LcdWriteNibble(1,0x06);
	LcdWriteNibble(1,0x80);
}

void printString(char* str)
{
	int i, j;
	int rest;

		for (i = 0; i < strlen(str); i++)
		{
			LcdWriteNibble(0,str[i]);
		}
}




void setCursorPos(int YPos)
{

	switch (YPos)
	{
		case 0:	LcdWriteNibble(1, 0x80);
		break;
		case 1:	LcdWriteNibble(1, 0xC0);
		break;
	}

}