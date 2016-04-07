/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** ledmatrix.c
**
** Beschrijving:	Simple HT16K33 Ledmatix demo.
** Target:			AVR mcu
** Build:			avr-gcc -std=c99 -Wall -O3 -mmcu=atmega128 -D F_CPU=8000000UL -c ledmatrix.c
**					avr-gcc -g -mmcu=atmega128 -o ledmatrix.elf ledmatrix.o
**					avr-objcopy -O ihex ledmatrix.elf ledmatrix.hex 
**					or type 'make'
** Author: 			dkroeske@gmail.com
** -------------------------------------------------------------------------*/


#include <avr/io.h>
#include <util/delay.h>

void setLedRow(int row,int data);
/******************************************************************/
void twi_init(void)
/* 
short:			Init AVR TWI interface and set bitrate
inputs:			
outputs:	
notes:			TWI clock is set to 100 kHz
Version :    	DMK, Initial code
*******************************************************************/
{
	TWSR = 0;
	TWBR = 32;	 // TWI clock set to 100kHz, prescaler = 0
}

/******************************************************************/
void twi_start(void)
/* 
short:			Generate TWI start condition
inputs:		
outputs:	
notes:			
Version :    	DMK, Initial code
*******************************************************************/
{
	TWCR = (0x80 | 0x20 | 0x04);
	while( 0x00 == (TWCR & 0x80) );
}

/******************************************************************/
void twi_stop(void)
/* 
short:			Generate TWI stop condition
inputs:		
outputs:	
notes:			
Version :    	DMK, Initial code
*******************************************************************/
{
	TWCR = (0x80 | 0x10 | 0x04);
}

/******************************************************************/
void twi_tx(unsigned char data)
/* 
short:			transmit 8 bits data
inputs:		
outputs:	
notes:			
Version :    	DMK, Initial code
*******************************************************************/
{
	TWDR = data;
	TWCR = (0x80 | 0x04);
	while( 0 == (TWCR & 0x80) );
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
/*this method wil set the requested row of leds to the requested data */
void setLedRow(int row,int data)
{
	switch(row)
	{
		case 1:
			twi_start();
			twi_tx(0xE0);	// Display I2C addres + R/W bit
			twi_tx(0x00);	// Address
			twi_tx(data);	// data
			twi_stop();
		break;
		case 2:
			twi_start();
			twi_tx(0xE0);	// Display I2C addres + R/W bit
			twi_tx(0x02);	// Address
			twi_tx(data);	// data
			twi_stop();
		break;
		case 3:
			twi_start();
			twi_tx(0xE0);	// Display I2C addres + R/W bit
			twi_tx(0x04);	// Address
			twi_tx(data);	// data
			twi_stop();
		break;
		case 4:
			twi_start();
			twi_tx(0xE0);	// Display I2C addres + R/W bit
			twi_tx(0x06);	// Address
			twi_tx(data);	// data
			twi_stop();
		break;
		case 5:
			twi_start();
			twi_tx(0xE0);	// Display I2C addres + R/W bit
			twi_tx(0x08);	// Address
			twi_tx(data);	// data
			twi_stop();
		break;
		case 6:
		    twi_start();
			twi_tx(0xE0);	// Display I2C addres + R/W bit
			twi_tx(0x0a);	// Address
			twi_tx(data);	// data
			twi_stop();
		break;
		case 7:
			twi_start();
			twi_tx(0xE0);	// Display I2C addres + R/W bit
			twi_tx(0x0c);	// Address
			twi_tx(data);	// data
			twi_stop();
		break;
		case 8:
			twi_start();
			twi_tx(0xE0);	// Display I2C addres + R/W bit
			twi_tx(0x0e);	// Address
			twi_tx(data);	// data
			twi_stop();
		break;
	}
	
}
/* displays the up arrow on the left site of the dot matrix display */
void arrowUp()
{
	setLedRow(8,1);
	setLedRow(7,143);
	setLedRow(6,143);
	setLedRow(5,1);
}
/* clears the dot matrix display */
void clearScreen()
{
		setLedRow(1,0);
		setLedRow(2,0);
		setLedRow(3,0);
		setLedRow(4,0);
		setLedRow(5,0);
		setLedRow(6,0);
		setLedRow(7,0);
		setLedRow(8,0);
}
/* displays the down arrow on the left site of the dot matrix display */
void arrowDown()
{
	setLedRow(8,32);
	setLedRow(7,124);
	setLedRow(6,124);
	setLedRow(5,32);
}
/* displays the requested nummer on the left side of the dot matrix display */
void displayNummer(int nummer)
{
	switch(nummer)
	{
		case 0:
		setLedRow(4,56);
		setLedRow(3,68);
		setLedRow(2,68);
		setLedRow(1,56);
		break;
		case 1:
		setLedRow(4,0);
		setLedRow(3,4);
		setLedRow(2,124);
		setLedRow(1,0);
		break;
		case 2:
		setLedRow(4,72);
		setLedRow(3,100);
		setLedRow(2,84);
		setLedRow(1,72);
		break;
		case 3:
		setLedRow(4,40);
		setLedRow(3,68);
		setLedRow(2,84);
		setLedRow(1,40);
		break;
		case 4:
		setLedRow(4,28);
		setLedRow(3,16);
		setLedRow(2,16);
		setLedRow(1,124);
		break;
		case 5:
		setLedRow(4,92);
		setLedRow(3,84);
		setLedRow(2,84);
		setLedRow(1,116);
		break;
		case 6:
		setLedRow(4,124);
		setLedRow(3,84);
		setLedRow(2,84);
		setLedRow(1,116);
		break;
		case 7:
		setLedRow(4,4);
		setLedRow(3,100);
		setLedRow(2,20);
		setLedRow(1,12);
		break;
		case 8:
		setLedRow(4,124);
		setLedRow(3,84);
		setLedRow(2,84);
		setLedRow(1,124);
		break;
		case 9:
		setLedRow(4,92);
		setLedRow(3,84);
		setLedRow(2,84);
		setLedRow(1,124);
		break;
	}
}
/* handels the display for request to travel from one floor to a other */
void toFloor(int currentFloor,int destination)
{
	if(currentFloor< destination)
	{
		arrowUp();
		for(;destination >= currentFloor; currentFloor++)
		{
			if(destination == currentFloor)
			{
				clearScreen();
			}
			displayNummer(currentFloor);
			wait(1000);
			
		}
	}
	else
	{
		arrowDown();
		for(;destination <= currentFloor; currentFloor--)
		{
			if(destination == currentFloor)
			{
				clearScreen();
			}
			displayNummer(currentFloor);
			wait(1000);
		}
	}
}

/******************************************************************/
int main( void )
/* 
short:			main() loop, entry point of executable
inputs:			
outputs:	
notes:			Looping forever, trashing the HT16K33
Version :    	DMK, Initial code
*******************************************************************/
{
	int i = 0;
	int CurrentFloor =0;
	int DestinationFloor =0;
	twi_init();		// Init TWI interface
	//dot matrix test
		setLedRow(1,255);
		setLedRow(2,255);
		setLedRow(3,255);
		setLedRow(4,255);
		setLedRow(5,255);
		setLedRow(6,255);
		setLedRow(7,255);
		setLedRow(8,255);
		
		wait(500);	
		
		clearScreen();
		wait(500);
		
		arrowUp();
		for(int i = 0; i<10;i++)
		{
			if(i == 9)
			{
				clearScreen();
			}
			displayNummer(i);
			wait(1000);
		}
		wait(500);
		arrowDown();
		for(int i = 9; i>=0;i--)
		{
			if(i == 0)
			{
				clearScreen();
			}
			displayNummer(i);
			wait(1000);
		}
		wait(500);
// main loop for the elevator demo		
	while(1)  
	{
		switch(PINA)
		{
			case 1:
			DestinationFloor =0;
			break;
			case 2:
			DestinationFloor =1;
			break;
			case 4:
			DestinationFloor =2;
			break;
			case 8:
			DestinationFloor =3;
			break;
			case 16:
			DestinationFloor =4;
			break;
			case 32:
			DestinationFloor =5;
			break;
			case 64:
			DestinationFloor =6;
			break;
			case 128:
			DestinationFloor =7;
			break;
			default:
			break;
		}
		if(CurrentFloor != DestinationFloor)
		{
			toFloor(CurrentFloor,DestinationFloor);
			CurrentFloor = DestinationFloor;
		}
	}
	

	return 1;
}
