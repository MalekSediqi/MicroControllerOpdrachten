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
#include "lcd.h"
#include <stdio.h>
#include <util/delay.h>


#define  BIT(x) (1 <<(x));
volatile int counter;
int Compervalue =1;
char lcdstr[4];
int TimerPreset = 0;

ISR(TIMER2_COMP_vect)
{
	counter++;
}

void Counter()
{
	OCR2 = Compervalue;
	SREG |=(1<<OCIE2);
	TIMSK |= BIT(7);
	TCCR2 |= TCCR2 |= (1 << CS22) | (1 << CS21) | (1 << CS20) | (1 << WGM21) | (1 << COM20);
}

int main (void)
{
	DDRD &= ~BIT(7);
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRC = 0xFF;
	initLCD();
	Counter();
	for (;;)
	{
			PORTA = TCNT2;
			PORTB = counter;
			sprintf(lcdstr,"%d",counter);
			printString(lcdstr,4);
			clearScreen();
			_delay_ms(1);
	}
}


