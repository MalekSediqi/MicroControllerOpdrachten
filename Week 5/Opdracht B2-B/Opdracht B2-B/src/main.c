#include "uart0.h"
#include "lcd.h"
#define  BIT(x) (1 <<(x));

char character;

// wait(): busy waiting for 'ms' millisecond
// Used library: util/delay.h
void wait( int ms )
{
	for (int tms=0; tms<ms; tms++)
	{
		_delay_ms( 1 );						// library function (max 30 ms at 8MHz)
	}
}


// send/receive uart - dB-meter
int main( void )
{
	char buffer[16];						// declare string buffer 
	DDRB = 0xFF;							// set PORTB for output
	DDRD = 0xFF;
	initLCD();							// initialize LCD-display
	usart0_init();							// initialize USART0
	usart0_start();
	while (1)
	{
		wait(50);							// every 50 ms (busy waiting)
		PORTB ^= BIT(7);					// toggle bit 7 for testing
		PORTD ^= (1<<7);	
		uart0_receiveString( buffer );		// receive string from uart
		setYCursorPos(0);
		printString(buffer,10);
		// write string to LCD display
	}
}