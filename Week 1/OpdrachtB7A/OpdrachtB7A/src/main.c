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
	
	switch(input)
	{
		case 64:
		state = S1;
		clearScreen();
		printString("S1",2);
		break;
		case 32: 
		state = S2;
		clearScreen();
		printString("S2",2);
		break;
		default:
		break;
	}

}
void S1(int input)
{

	switch(input)
	{
		case 128:
		state = start;
		clearScreen();
		printString("start",5);
		break;
		case 32:
		state = S2;
		clearScreen();
		printString("S2",2);
		break;
		default:
		break;
	}
}
void S2(int input)
{
	switch(input)
	{
		case 64:
		state = S1;
		clearScreen();
		printString("S1",2);
		break;
		case 32:
		state = S3;
		clearScreen();
		printString("S3",2);
		break;
		default:
		break;
	}
	
}
void S3(int input)
{
	if(input == 64 || input == 32)
	{
		state = End;
		clearScreen();
		printString("End",3);
	}
	else if (input ==128)
	{
		state = start;
		clearScreen();
		printString("start",5);
		
	}
}
void End(int input)
{	
	
	if(input == 128)
	{
		state = start;
		clearScreen();
		printString("start",5);
	}

}


int main (void)
{
	state = start;
	initLCD();
	//clearScreen();
	printString("start",5);
	DDRC = 0b11111111;
	DDRA = 0;
	/////////////////////////////////////////////////b7a

	while(true)
	{
		
		state(PIND);
		wait(1000);
	}
	return 1;

}