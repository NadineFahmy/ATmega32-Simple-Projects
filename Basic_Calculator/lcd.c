/*
 * lcd.c
 *
 *  Created on: Nov 1, 2023
 *      Author: yoga
 */


#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

#define E (1<<PA3)
#define RW (1<<PA2)
#define RS (1<<PA1)

void lcdinit(){

   DDRA |= (1<<PA1) | (1<<PA2) | (1<<PA3) | (1<<PA4) | (1<<PA5) | (1<<PA6) | (1<<PA7);


   latch();
   _delay_ms(2);

   lcdcmd(0x33);
   _delay_us(100);
  lcdcmd(0x32);
  _delay_us(100);
   lcdcmd(0x28);
   _delay_us(100);

    lcdcmd(0x0C);
  _delay_us(100);
   lcdcmd(0x01);
   _delay_ms(20);
   lcdcmd(0x06);
   _delay_ms(100);

   }

 void latch(void){
      PORTA |= E;
      _delay_us(500);
      PORTA &= ~E;
      _delay_us(500);
    }

   void lcdcmd(unsigned char cmd){

      PORTA = (PORTA & 0x0F) | (cmd & 0xF0);
      PORTA &= ~RW;
      PORTA &= ~RS;
      latch();

      PORTA = (PORTA & 0x0F) | (cmd<<4);
      latch();

      }

  void lcdchar(unsigned char data){

      PORTA = (PORTA & 0x0F) | (data & 0xF0);
      PORTA &= ~RW;
      PORTA |= RS;
      latch();

      PORTA = (PORTA & 0x0F) | (data<<4);
      latch();

      }

 void lcdstr(char *str){
    unsigned char k=0;
    while(str[k] != 0){
	 lcdchar(str[k]);
       k++;
       }
    }

 void lcdgoto(unsigned char x, unsigned char y){
      unsigned char firstcharadr[] = {0x80, 0xC0, 0x94, 0xD4};
      lcdcmd(firstcharadr[y-1] + x-1);
      _delay_us(1000);
    }

void lcdclear(){
	lcdcmd(0x01);
	_delay_ms(10);
}
