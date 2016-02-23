

#include "lcd.h"

int main (void)
{
	DDRC = 0xFF;
	initLCD();
	printString("hoi");
	setCursorPos(1);
	printString("hoi");
}
