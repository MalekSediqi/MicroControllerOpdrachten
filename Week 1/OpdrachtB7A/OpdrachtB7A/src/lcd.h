/**
 * \file
 *
 * \brief ATmega128 on STK600 board configuration template
 *
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#ifndef _Lcd_H
#define _Lcd_H


extern void initLCD(void);
extern void printString(char* str,int length);
extern void setCursorPos(int YPos);
extern void clearScreen();

#endif // CONF_BOARD_H
