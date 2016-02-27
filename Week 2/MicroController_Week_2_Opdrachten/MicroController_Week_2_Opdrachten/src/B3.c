///* ---------------------------------------------------------------------------
//** This software is in the public domain, furnished "as is", without technical
//** support, and with no warranty, express or implied, as to its usefulness for
//** any purpose.
//**
//** lookup.c
//**
//** Beschrijving:	Ledpatroon op PORTD dmv table lookup (scheiding logica en data)    
//** Target:			AVR mcu
//** Build:			avr-gcc -std=c99 -Wall -O3 -mmcu=atmega128 -D F_CPU=8000000UL -c switch.c
//**					avr-gcc -g -mmcu=atmega128 -o lookup.elf lookup.o
//**					avr-objcopy -O ihex lookup.elf lookup.hex 
//**					or type 'make'
//** Author: 			dkroeske@gmail.com
//** -------------------------------------------------------------------------*/
//
//#include <avr/io.h>
//#include <util/delay.h>
//
//typedef struct { 
	//unsigned char data;
	//unsigned int delay ;
//} PATTERN_STRUCT; 
//
//// 7 seg
//// PORTD dp G F E D C B A
////        y y y y x x x x
//
//PATTERN_STRUCT pattern[] = { 
	//{0x80, 150}, {0x00, 150}, 
	//{0x80, 150}, {0x00, 150},
	//{0x01, 150}, {0x02, 150}, {0x40, 150}, {0x20, 150},
	//{0x01, 150}, {0x02, 150}, {0x40, 150}, {0x20, 150},
	//{0x00, 150},
	//{0x01, 150}, {0x03, 150}, {0x43, 150}, {0x63, 150},	
	//{0x01, 150}, {0x03, 150}, {0x43, 150}, {0x63, 150},
	//{0x00, 150},
	//{0xFF, 0}
//};
//void display(int digit)
//{
	//switch(digit)
	//{
		//case 0:
		//PORTD = 0b00111111;
		//break;
		//case 1:
		//PORTD = 0b00000110;
		//break;
		//case 2:
		//PORTD = 0b01011011;
		//break;
		//case 3:
		//PORTD = 0b01001111;
		//break;
		//case 4:
		//PORTD = 0b01100110;
		//break;
		//case 5:
		//PORTD = 0b01101101;
		//break;
		//case 6:
		//PORTD = 0b01111101;
		//break;
		//case 7:
		//PORTD = 0b00000111;
		//break;
		//case 8:
		//PORTD = 0b01111111;
		//break;
		//case 9:
		//PORTD = 0b01101111;
		//break;
		//default:
		//PORTD = 0b01111001;
		//break;
	//}
//}
///******************************************************************/
//void wait( int ms )
///* 
//short:			Busy wait number of millisecs
//inputs:			int ms (Number of millisecs to busy wait)
//outputs:	
//notes:			Busy wait, not very accurate. Make sure (external)
				//clock value is set. This is used by _delay_ms inside
				//util/delay.h
//Version :    	DMK, Initial code
//*******************************************************************/
//{
	//for (int i=0; i<ms; i++)
	//{
		//_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	//}
//}
//
//
///******************************************************************/
//int main( void )
///* 
//short:			main() loop, entry point of executable
//inputs:			
//outputs:	
//notes:			
//Version :    	DMK, Initial code
//*******************************************************************/
//{
	//DDRD = 0b11111111;					// PORTD all output 
	//
	//
		//// Set index to begin of pattern array
		//int index = 0;
		//// as long as delay has meaningful content
		//while(1) {
			//// Write data to PORTD	
			//display(index);
			//index++;
			//wait(10000);
			//if(index >=11)
			//{
				//index = 0;
			//}
		//}
	//
//
	//return 1;
//}