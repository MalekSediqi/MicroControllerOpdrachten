#include <asf.h>
#include <util/delay.h>
#define BIT(x) (1<<(x))

int pattern[8] = {};
int counter = 8;
int counter2 = 0;
/*
	setPatters zorgt er voor dat de Bits shiften.
	Je voegt aantal bits toe aan de parameters om het te laten shiften.
*/
void setPattern1(int toSaveTo[])
{
	for(int i = 0; i< 8; i++)
	{
		toSaveTo[i] = 0x01<<i;	
	}

}

void wait(int param1)
{
	for(int i = 0; i< param1;i++)
	{

		_delay_ms(1);
	}
}

int main (void)
{
	DDRD = 0b11111111;
	DDRC = 0b11111111;
	setPattern1(pattern);

	while(1)
	{
		PORTD = pattern[counter];
		counter--;

		if (counter < 0)
		{
			counter = 8;
		}
		wait(250);
		PORTD = pattern[counter2];
		counter2++;

		if (counter2 > 7)
		{
			counter2 = 0;
		}
		wait(500);
	}
	return 1;
}