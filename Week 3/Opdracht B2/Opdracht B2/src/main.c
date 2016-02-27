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

int counter =0;
char lcdstr[8];

ISR(TIMER2_COMP_vect)
{
	TCNT2 = TimerPreset;
	counter++;
	sprintf(lcdstr, "%d", counter);
}

void Counter()
{
	/*SREG |=(1<<OCIE2);
	TCCR2 |= (1 << CS22) | (1 << CS21) | (1 << CS20) | (1 << WGM21) | (1 << COM20);
	TIMSK |= (1 << OCIE2);
*/
	TCNT2 = TimerPreset; // Preset value of counter 2
	TIMSK |= BIT(6); // T2 overflow interrupt enable
	SREG |= BIT(7); // turn_on intr all
	TCCR2 = 0x07; // Initialize T2: ext.counting, rising edge, run 
}

int main (void)
{
	//EICRA |= 0x0B;
	//EIMSK |= 0x03;
	DDRD &= ~BIT(7);
	DDRA = 0xFF;
	DDRB = 0xFF;

	sei();
	Counter();
	initLCD();
	while(1)
	{
		PORTA = TCNT2;
		printString(lcdstr,8);
		_delay_ms(3000);
	}
	
}


