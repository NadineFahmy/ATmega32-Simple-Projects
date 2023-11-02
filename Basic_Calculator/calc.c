/*
 * calc.c
 *
 *  Created on: Nov 1, 2023
 *      Author: yoga
 */


#include <avr/io.h>
#include <util/delay.h>
#include "calc.h"
#include "lcd.h"

int get_num(unsigned char ch)
{
    int num = 0;
    switch(ch)
    {
    case '0':
        num = 0;
        break;
    case '1':
        num = 1;
        break;
    case '2':
        num = 2;
        break;
    case '3':
        num = 3;
        break;
    case '4':
        num = 4;
        break;
    case '5':
        num = 5;
        break;
    case '6':
        num = 6;
        break;
    case '7':
        num = 7;
        break;
    case '8':
        num = 8;
        break;
    case '9':
        num = 9;
        break;
    case 'C':
        lcdcmd(0x01);
        num = Error;
        break;
    default:
        DispError(0);
        num = Error;
        break;
    }
    return num;
}

unsigned char get_func(unsigned char chf)
{
    if(chf=='C')
    {
        lcdcmd(0x01);
        return 'e';
    }
    if( chf != '+' && chf != '-' && chf != 'x' && chf != '/' )
    {
        DispError(1);
        return 'e';
    }
    return chf;
}


void DispError(int numb)
{
	unsigned char msg1[] = {"Wrong Input"};
	unsigned char msg2[] = {"Wrong Function"};

    lcdcmd(0x01);
    switch(numb)
    {
    case 0:
        lcdstr(msg1);
        break;
    case 1:
        lcdstr(msg2);
        break;
    default:
        lcdstr(msg1);
        break;
    }
}

void disp_num(int numb)
{
    unsigned char UnitDigit  = 0;
    unsigned char TenthDigit = 0;

    if(numb<0)    {
        numb = -1*numb;
        lcdchar('-');
    }
    TenthDigit = (numb/10);

    if( TenthDigit != 0)
        lcdchar(TenthDigit+0x30);
		UnitDigit = numb - TenthDigit*10;
		lcdchar(UnitDigit+0x30);
}
