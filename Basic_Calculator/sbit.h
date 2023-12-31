/*
 * sbit.h
 *
 *  Created on: Nov 1, 2023
 *      Author: yoga
 */

#ifndef SBIT_H_
#define SBIT_H_

struct bits {
  uint8_t b0:1;
  uint8_t b1:1;
  uint8_t b2:1;
  uint8_t b3:1;
  uint8_t b4:1;
  uint8_t b5:1;
  uint8_t b6:1;
  uint8_t b7:1;
} __attribute__((__packed__));


#define SBIT(port,pin) ((*(volatile struct bits*)&port).b##pin)

#endif /* SBIT_H_ */
