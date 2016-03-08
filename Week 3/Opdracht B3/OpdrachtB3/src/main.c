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
#include <stdio.h>
#include <util/delay.h>

#define  BIT(x) (1 <<(x));
volatile int isHigh;

ISR(TIMER2_OVF_vect)
{
	PORTD ^= 0x80;
	if (isHigh == 1)
	{
		TCNT2 = 255-195;
		isHigh = 0;
	}
	else
	{
		TCNT2 = 255-117;
		isHigh = 1;
	}
}

void Init()
{
	isHigh = 0;
	TCNT2 = 0;
	TIMSK |= BIT(6);
	TCCR2 = 0x05;
}

int main (void)
{
	DDRD = 0x80;
	DDRA = 0xFF;
	DDRB = 0xFF;
	Init();

	SREG |= BIT(7);
	while (1)
	{
		
	}
	return 1;
}


