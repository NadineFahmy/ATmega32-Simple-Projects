/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: yoga
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_interface.h"
#include <util/delay.h>

int main() {

	LED_Type LED1 = {LED_PORTC, LED_PIN0, ACTIVE_HIGH};
	LED_Type LED2 = {LED_PORTC, LED_PIN1, ACTIVE_HIGH};
	LED_Type LED3 = {LED_PORTC, LED_PIN2, ACTIVE_HIGH};


	LED_voidInit(LED1);
	LED_voidInit(LED2);
	LED_voidInit(LED3);

	s8 counter = 1;
	while(1) {

		if(counter % 1 == 0) { LED_voidToggle(LED1); }

		if(counter % 2 == 0) { LED_voidToggle(LED2); }

	    if(counter % 3 == 0) { LED_voidToggle(LED3); }

		counter++;
		_delay_ms(1000);
	}

}
