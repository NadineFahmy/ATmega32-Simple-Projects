/*
 * keypad.c
 *
 *  Created on: Nov 1, 2023
 *      Author: yoga
 */

#include <avr/io.h>
#include "util/delay.h"
#include "sbit.h"

#define R1 SBIT(PORTD, 0)
#define R2 SBIT(PORTD, 1)
#define R3 SBIT(PORTD, 2)
#define R4 SBIT(PORTD, 3)

#define c1 SBIT(PIND, 4)
#define c2 SBIT(PIND, 5)
#define c3 SBIT(PIND, 6)
#define c4 SBIT(PIND, 7)

unsigned char keypress(void)
  {

   DDRD=0b00001111;
   PORTD=0b11110000;

   while (1)
    {
     R1=0;     R2=1;     R3=1;     R4=1;
     _delay_us(50);
     if (c1==0){while (c1==0);return ('7');}
     if(c2==0){while (c2==0); return ('8');}
     if (c3==0){while (c3==0); return ('9');}
     if(c4==0){while (c4==0);return ('/');}

     R1=1;     R2=0;     R3=1;     R4=1;
     _delay_us(50);
     if (c1==0){while (c1==0); return ('4');}
     if(c2==0){while (c2==0); return ('5');}
     if(c3==0){while (c3==0); return ('6');}
     if(c4==0){while (c4==0); return ('x');}

     R1=1;     R2=1;     R3=0;     R4=1;
     _delay_us(50);
     if (c1==0){while (c1==0); return ('1');}
     if (c2==0){while (c2==0); return ('2');}
     if (c3==0){while (c3==0); return ('3');}
     if (c4==0){while (c4==0); return ('-');}

     R1=1;     R2=1;     R3=1;     R4=0;
     _delay_us(50);
     if (c1==0){while (c1==0); return ('C');}
     if (c2==0){while (c2==0); return ('0');}
     if (c3==0){while (c3==0); return ('=');}
     if (c4==0){while (c4==0); return ('+');}
     }

  }
