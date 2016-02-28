#include <asf.h>
#include <util/delay.h>
#define BIT(x) (1<<(x))


void wait(int param1)
{
	for(int i = 0; i< param1;i++)
	{

		_delay_ms(1);
	}
}

int main (void)
{
 	DDRD = 0xFF;
 	
 	while(1)
 	{
	 	PINC &= ~BIT(0);		// Bit 0 van PINC is laag "0";
	 	if (PINC == 0)
	 	{
		 	PORTD ^= BIT(7);	// Bit 7 van PortD.7 is hoog "1";
		 	wait(500);
	 	}
	 	else
	 	{
		 	PORTD &= ~BIT(7);	// Bit 7 van PortD.7 is laag "0";
	 	}
 	}
 	return 1;
}