/*
 * calc.h
 *
 *  Created on: Nov 1, 2023
 *      Author: yoga
 */

#ifndef CALC_H_
#define CALC_H_

#include <avr/io.h>
#include <util/delay.h>

#define Error   13

int get_num(unsigned char);
unsigned char get_func(unsigned char);
void DispError(int);
void disp_num(int);

#endif /* CALC_H_ */
