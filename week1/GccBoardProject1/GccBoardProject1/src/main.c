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
#include "avr/iom128a.h"

void wait(int param1)
{
	for(int i = 0; i< param1;i++)
	{

	_delay_ms(1);
	}
}

int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */

	board_init();
	DDRD = 0b11111111;
	DDRA = 0b00000000;
	DDRB = 0b11111111;
	DDRC = 0b11111111;
	

	while(true)
	{
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
		if(PORTA >0)
		{
			PORTD = 0b01000000;
			wait(40000);
			PORTD = 0b00000000;
			wait(40000);

		}
		else
		{

		PORTD = 0b00000000;
		}

	}
	return 1;

	/* Insert application code here, after the board has been initialized. */
}
