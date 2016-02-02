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
	DDRD = 0b01111111;
	
	while(true)
	{
		PINC = 0b01000000;
		if(PINC == 0)
		{
			PORTD = 0b01000000;
			wait(500);
			PORTD = 0b00000000;
			wait(500);
		}
		else
		{

			PORTD = 0b00000000;
		}

	}
	return 1;

	/* Insert application code here, after the board has been initialized. */
}
