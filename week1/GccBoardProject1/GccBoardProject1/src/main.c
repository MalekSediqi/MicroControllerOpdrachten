/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>
#include <util/delay.h>


void wait(int param1)
{
	for(int i = 0; i< param1;i++)
	{

		_delay_ms(1);
	}
}
void setPattern1(int toSaveTo[])
{
	for(int i = 0; i< 8; i++)
	{
		toSaveTo[i] = 0x01<<i;
	}

}
void setStates(int state[])
{
	int i;
	for(i = 0; i<8 ;i++)
	{
		state[i] = 0x01<<i;
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
	/* Insert system clock initialization code here (sysclk_init()). */

	board_init();
// OPDRACHT b3 
// 	DDRD = 0b01111111;
// 	
// 	while(true)
// 	{
// 		PINC = 0b01000000;
// 		if(PINC == 0)
// 		{
// 			PORTD = 0b01000000;
// 			wait(500);
// 			PORTD = 0b00000000;
// 			wait(500);
// 		}
// 		else
// 		{
// 
// 			PORTD = 0b00000000;
// 		}
// 
// 	}
// 	return 1;

	DDRD = 0b11111111;
	DDRC = 0b11111111;
	DDRB = 0b11111111;
	int states[8] = {};
	int pattern[8] = {};
	setPattern1(pattern);
	setStates(states);
	int counter = 0;
	bool toggled = false;
// 	while(true)
// 	{
	//OPDRACHT B2
		//PORTA = 0b11111111;
		//wait(5000);
		//PORTB = 0b11111111;
		//wait(5000);
		//PORTC = 0b11111111;
		//wait(5000);
		//PORTD = 0b11111111;
		//wait(5000);
		//PORTA = 0x00;
		//PORTB = 0x00;
		//PORTC = 0x00;
		//PORTD = 0x00;
		//wait(5000);
		//OPDRACHT b5
		//PORTD = pattern[counter];
		//counter++;
		//if(counter >7)
		//{
			//counter = 0;
//
		//}
		//wait(500);

		// OPDRAcht B6
		//if(PINC >= 1)
		//{
			//toggled = !toggled;
			//wait(1000);
			//
		//}
//
		//if(toggled)
		//{
			//PORTD = 64;
			//wait(250);
			//PORTD = 0;
			//wait(250);
//
		//}
		//else
		//{
			//PORTD = 64;
			//wait(1000);
			//PORTD = 0;
			//wait(1000);
		//}
	//}

	while(true)
	{

		handleState(states);
	}
	return 1;

	/* Insert application code here, after the board has been initialized. */
}
