#include <avr/io.h>
#include <util/delay.h>

typedef struct { 
	unsigned char data;
	unsigned int delay ;
} PATTERN_STRUCT; 

// 7 seg
// PORTD dp G F E D C B A
//        y y y y x x x x

PATTERN_STRUCT pattern[] = { 
	{6, 1500}, {12, 1500}, 
	{24, 1500}, {48, 1500},
	{33, 1500}, {3, 1500}, {66, 1500}, {80, 1500},
	{24, 1500},{12,1500}
};
void display(int digit)
{
	switch(digit)
	{
		case 0:
		PORTD = 0b00111111;
		break;
		case 1:
		PORTD = 0b00000110;
		break;
		case 2:
		PORTD = 0b01011011;
		break;
		case 3:
		PORTD = 0b01001111;
		break;
		case 4:
		PORTD = 0b01100110;
		break;
		case 5:
		PORTD = 0b01101101;
		break;
		case 6:
		PORTD = 0b01111101;
		break;
		case 7:
		PORTD = 0b00000111;
		break;
		case 8:
		PORTD = 0b01111111;
		break;
		case 9:
		PORTD = 0b01101111;
		break;
		default:
		PORTD = 0b01111001;
		break;
	}
}
/******************************************************************/
void wait( int ms )
/* 
short:			Busy wait number of millisecs
inputs:			int ms (Number of millisecs to busy wait)
outputs:	
notes:			Busy wait, not very accurate. Make sure (external)
				clock value is set. This is used by _delay_ms inside
				util/delay.h
Version :    	DMK, Initial code
*******************************************************************/
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}


/******************************************************************/
int main( void )
/* 
short:			main() loop, entry point of executable
inputs:			
outputs:	
notes:			
Version :    	DMK, Initial code
*******************************************************************/
{
	DDRD = 0b11111111;					// PORTD all output 
	
	
		// Set index to begin of pattern array
		int index = 0;
		// as long as delay has meaningful content
		while(1) {
			// Write data to PORTD	
			PORTD = pattern[index].data;
			// wait
			wait(pattern[index].delay);
			// increment for next round
			index++;
			if(index >=10)
			{
				index = 0;
			}
		}
	

	return 1;
}