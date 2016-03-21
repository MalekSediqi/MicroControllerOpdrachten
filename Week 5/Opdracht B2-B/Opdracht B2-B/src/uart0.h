/*
* Project name : uart0 : UART - send / receive characters with waiting
* Author : Avans-TI, JW
* Revision History : 20110227: - initial release;
* Description : This program receive a character, and sends it back
* Test configuration : MCU: ATmega128
 Dev.Board: BIGAVR6
 Oscillator: External Clock 08.0000 MHz
 Ext. Modules: -
 SW: AVR-GCC
* NOTES : Turn ON switch 12, PEO/PE1 tot RX/TX
*/
#ifndef _UART
#define _UART
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void usart0_init( void ) ; // initialize USART0 - receive/transmit
void usart0_start( void ) ; // UART0 receiver & transmitter enable
char uart0_receiveChar() ; // UART0: receive ch
int uart0_sendChar( char ch ) ; // UART0: send ch
int uart0_receiveString( char* string);
#endif