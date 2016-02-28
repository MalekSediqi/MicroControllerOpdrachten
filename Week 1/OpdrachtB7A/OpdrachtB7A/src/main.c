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

void handleState(int state[])
{
	int i;
	//int k = strlen(state);
	for(i=0; i< 8; i++)
	{
		if(state[i] = PINA)
		{
			switch(i)
			{
				case 0:
				PORTD = 127;
				break;
				case 1:
				PORTD = 255;
				break;
				case 2:
				PORTC = 1;
				break;
				case 3:
				PORTD = 0;
				PORTC = 0;
				break;
				case 4:
				break;
				default:
				break;
			}
			wait(1000);
		}
	}

}


int main (void)
{
	DDRD = 0b11111111;
	DDRC = 0b11111111;
	DDRB = 0b11111111;
	int states[8] = {};
	/////////////////////////////////////////////////b7a
	while(true)
	{
	
		handleState(states);
	}
	return 1;

}