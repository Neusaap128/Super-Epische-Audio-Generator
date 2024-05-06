/*
 * IO.h
 *
 *  Created on: Mar 23, 2024
 *      Author: rode-
 */

#ifndef INC_IO_IO_H_
#define INC_IO_IO_H_
#define AANTALFILTER 3
#include <stdlib.h>
#include "main.h"
#include "ShiftRegister.h"
#include "../DSP/DSP.h"




typedef enum{
	Disabled,
	SelectingFilter,
	SelectingValue
}IOState_t;

IOState_t IOState;

uint16_t HandleSelectingFilter();
// I Think this functions isn't needed anymore
//void filter_led(uint8_t *filter_led_array, int pressed, int filter);

void HandleSelectingValue(uint8_t *ledbar_array);

void ButtonIntrupt(uint32_t time);

uint16_t main_call();


#endif /* INC_IO_IO_H_ */





