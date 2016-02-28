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

void setPattern1(int toSaveTo[])
{
	for(int i = 0; i< 8; i++)
	{
		toSaveTo[i] = 0x01<<i;
	}

}
void setStates(int state[])
{
	int i;
	for(i = 0; i<8 ;i++)
	{
		state[i] = 0x01<<i;
	}
}


int main (void)
{
	DDRD = 0b11111111;
	DDRC = 0b11111111;

	int states[8] = {};
	setStates(states);
	bool toggled = false;

	while(true)
	{
	 		if(PINC >= 1)
	 		{
	 			toggled = !toggled;
	 			wait(1000);
	
	 		}
	
	 		if(toggled)
	 		{
	 			PORTD = 64;
	 			wait(250);
	 			PORTD = 0;
	 			wait(250);
	
	 		}
	 		else
	 		{
	 			PORTD = 64;
	 			wait(1000);
	 			PORTD = 0;
	 			wait(1000);
	 		}
	}
}
