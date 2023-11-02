/*
 * main.c
 *
 *  Created on: Nov 1, 2023
 *      Author: yoga
 */


#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "lcd.h"
#include "sbit.h"
#include "keypad.h"
#include "calc.h"

int main(void){

    lcdinit();

	unsigned char key;
    int num1, num2;
    char func;

	lcdgoto(5,1);
	lcdstr("ATmega32 ");
	lcdgoto(4,2);
	lcdstr("Calculator");
	_delay_ms(100);
	lcdclear();


    while(1)
    {
		key = keypress();
        lcdcmd(0x01);
        lcdchar(key);
        num1 = get_num(key);

        if(num1 != Error)
        {
            key = keypress();
            lcdchar(key);
            func = get_func(key);
            if(func!='e')
            {
                key = keypress();
                lcdchar(key);
                num2 = get_num(key);
                if(num2!=Error)
                {
                    key = keypress();
                    lcdchar(key);
                    if(key == '=')
                    {
                        switch(func)
                        {
                        case '+':
                            disp_num(num1+num2);
                            break;
                        case '-':
                            disp_num(num1-num2);
                            break;
                        case 'x':
                            disp_num(num1*num2);
                            break;
                        case '/':
                        	if(num2 == 0)
                        		DispError(0);
                        	else
                        		disp_num(num1/num2);
                                break;
                        }
                    }
                    else
                    {
                        if(key == 'C')
                            lcdcmd(0x01);
                        else
                            DispError(0);
                    }
                }
            }
        }

     }
return 0;
}
