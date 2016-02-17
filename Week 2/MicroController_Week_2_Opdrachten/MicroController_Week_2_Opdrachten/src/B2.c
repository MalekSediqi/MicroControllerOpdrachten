//
//
//#define F_CPU 8000000UL
//
//#include <avr/io.h>
//#include <util/delay.h>
//#include <avr/interrupt.h>
//int ligt;
//
///******************************************************************/
//
//
///******************************************************************/
//ISR( INT0_vect )
///* 
//short:			ISR INT0
//inputs:			
//outputs:	
//notes:			Set PORTD.5
//Version :    	DMK, Initial code
//*******************************************************************/
//{
	//ligt = (ligt>>1);
    //PORTC = ligt;
	//if(ligt <= 0)
	//{
		//ligt = 256;
		//PORTC = ligt;
	//}
//}
//
///******************************************************************/
//ISR( INT1_vect )
///* 
//short:			ISR INT1
//inputs:			
//outputs:	
//notes:			Clear PORTD.5
//Version :    	DMK, Initial code
//*******************************************************************/
//{
	//ligt = (ligt<<1);	
     //PORTC = ligt;
	 //if(ligt >= 255)
	 //{
		//ligt = 1;
		//PORTC = ligt;
	 //}
     //
//}
//
///******************************************************************/
//int main( void )
///* 
//short:			main() loop, entry point of executable
//inputs:			
//outputs:	
//notes:			Slow background task after init ISR
//Version :    	DMK, Initial code
//*******************************************************************/
//{
	//
	//// Init I/O
	//DDRD = 0xF0;			// PORTD(7:4) output, PORTD(3:0) input	
	//DDRC = 0xFF;
	//// Init Interrupt hardware
	//EICRA |= 0x0B;			// INT1 falling edge, INT0 rising edge
	//EIMSK |= 0x03;			// Enable INT1 & INT0
	//
	//// Enable global interrupt system
	////SREG = 0x80;			// Of direct via SREG of via wrapper
	//sei();				
	//PORTC = 1;
	//ligt = 1;
	//while (1)
	//{
		//
	//}
//
	//return 1;
//}