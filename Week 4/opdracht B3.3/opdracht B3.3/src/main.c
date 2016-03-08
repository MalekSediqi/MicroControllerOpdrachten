/*
 * Project name:
     Demo4_2 : D conversion on channel 1, PORTF.1, single mode
 * Author: Avans-TI, JW
 * Revision History: 
     20101229: - initial release;
 * Description:
     This program gives an interrupt on each ms
 * Test configuration:
     MCU:             ATmega128
     Dev.Board:       BIGAVR6
     Oscillator:      External Clock 08.0000 MHz
     Ext. Modules:    -
     SW:              AVR-GCC
 * NOTES:
     - Turn ON the PORT LEDs at SW12.1 - SW12.8
*/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "lcd.h"
#define BIT(x)	(1 << (x))

// wait(): busy waiting for 'ms' millisecond
// Used library: util/delay.h
void wait( int ms )
{
	for (int tms=0; tms<ms; tms++)
	{
		_delay_ms( 1 );			// library function (max 30 ms at 8MHz)
	}
}


// Initialize ADC: 
void adcInit( void )
{
			//0b00111010
	ADMUX = 58;			// AREF=2,56 V, result left adjusted, channel1 at pin PF1
	ADCSRA = 0b10000110;		// ADC-enable, no interrupt, no free running, division by 64
}


// Main program: Counting on T1
int main( void )
{
	char* temp = "hoiod";
	DDRF = 0x00;					// set PORTF for input (ADC)
	DDRA = 0xFF;					// set PORTA for output 
	adcInit();	
	initLCD();					// initialize ADC

	while (1)
	{
		
		ADCSRA |= BIT(6);				// Start ADC
		while ( ADCSRA & BIT(6) ) ;
		sprintf(temp,"Graden:%d",(int)(ADCL/10));		// omdat elke bit 0.
		printString(temp,9);
		PORTA = ADCL;					// Show MSB (bit 9:2) of ADC
		wait(500);						// every 50 ms (busy waiting)
	}
}