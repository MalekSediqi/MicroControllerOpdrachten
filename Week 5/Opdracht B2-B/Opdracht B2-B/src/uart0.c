/*
 * uart0.c
 *
 * Created: 15-3-2016 11:53:37
 *  Author: malek
 */ 
 #include <avr/io.h>
 #include <util/delay.h>
 #include <avr/interrupt.h>
 #include "lcd.h"
 #define LF			0x0a					// ascii code for Line Feed
 #define CR			0x0d					// ascii code for Carriage Return
 #define BIT(x)		(1 << (x))
 #define UART0_BAUD	2400					// Baud rate USART0
 #define MYUBRR		F_CPU/16/UART0_BAUD - 1	// My USART Baud Rate Register
 #define F_CPU		8000000		

 void usart0_init( void )						// initialize USART0 - receive/transmit
 {
	 int	ubrr = MYUBRR;
	 UBRR0H = ubrr>>8;						// baudrate register, hoge byte
	 UBRR0L = ubrr;							// baudrate register, lage byte
	 UCSR0C = 0b00000110;					// asynchroon, 8 data - 1 stop - no parity
	 UCSR0B = 0b00000000;					// receiver & transmitter enable
 }

 void usart0_start( void )					// receiver & transmitter enable
 {
	 UCSR0B |= BIT(RXEN)|BIT(TXEN);			// set bit RXEN = Receiver enable and TXEN = Transmitter enable
 }

 int uart0_sendChar( char ch )
 {
	 while (!(UCSR0A & BIT(UDRE0))) ;		// wait until UDRE0 is set: transmit buffer is ready
	 UDR0 = ch;								// send ch
	 return 0;								// OK
 }

 char uart0_receiveChar( void )
 {
	 while (!(UCSR0A & BIT(RXC0))) ;			// if RX0 is set: unread data present in buffer
	 return UDR0;							// read ch
 }

 int uart0_receiveString( char* string)
 {
	 int stop = 0; // boolean for stop value
	 char ch;
	 while (!stop) // while contunie
	 {
		 ch = uart0_receiveChar(); // read ch
		 if ( ch == LF ) // stop at LF
		 stop = 1;
		 else
		 *string++ = ch; // else fill buffer
	 }
	 *string = '\0'; // string terminator
	 return 0;
 }