#include <asf.h>
#include <util/delay.h>
#include "lcd.h"
#define BIT(x) (1<<(x))
void (*state)(int);
void start(int input);
void S1(int input);
void S2(int input);
void S3(int input);
void End(int input);
void wait(int param1)
{
	for(int i = 0; i< param1;i++)
	{

		_delay_ms(1);
	}
}
void start(int input)
{
	printString("start",5);
	switch(input)
	{
		case 32:
		state = S1;
		break;
		case 16: 
		state = S2;
		break;
		default:
		break;
	}

}
void S1(int input)
{
	printString("S1",2);
	switch(input)
	{
		case 64:
		state = start;
		break;
		case 16:
		state = S2;
		break;
		default:
		break;
	}
}
void S2(int input)
{
	printString("S2",2);
	switch(input)
	{
		case 32:
		state = S1;
		break;
		case 16:
		state = S3;
		break;
		default:
		break;
	}
	
}
void S3(int input)
{
	printString("S3",2);
	if(input == 16 || input == 32)
	{
		state = End;
	}
	else if (input ==64)
	{
		state = start;
	}
}
void End(int input)
{	
	printString("End",3);
	if(input == 64)
	{
		state == start;
	}

}
void handleState(int state[])
{
	int i;
	//int k = strlen(state);
	for(i=0; i< 8; i++)
	{
		if(state[i] = PINA)
		{
			switch(i)
			{
				case 0:
				PORTD = 127;
				break;
				case 1:
				PORTD = 255;
				break;
				case 2:
				PORTC = 1;
				break;
				case 3:
				PORTD = 0;
				PORTC = 0;
				break;
				case 4:
				break;
				default:
				break;
			}
			wait(1000);
		}
	}

}


int main (void)
{
	state == start;
	initLCD();
	DDRD = 0b11111111;
	DDRC = 0b11111111;
	DDRB = 0b11111111;
	/////////////////////////////////////////////////b7a
	while(true)
	{
		clearScreen();
		state(PORTA);
		wait(500);
	}
	return 1;

}