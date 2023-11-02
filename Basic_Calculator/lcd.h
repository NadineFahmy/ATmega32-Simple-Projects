/*
 * lcd.h
 *
 *  Created on: Nov 1, 2023
 *      Author: yoga
 */

#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>

void lcdinit();
void lcdcmd(unsigned char);
void lcdchar(unsigned char);
void lcdstr(char *);
void latch(void);
void lcdgoto(uint8_t , uint8_t );
void lcdclear();

#endif /* LCD_H_ */
