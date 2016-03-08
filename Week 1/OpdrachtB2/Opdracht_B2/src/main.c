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
		PORTD ^= (BIT(7) | BIT(6));
		wait(500);
	}
	return 1;
}
