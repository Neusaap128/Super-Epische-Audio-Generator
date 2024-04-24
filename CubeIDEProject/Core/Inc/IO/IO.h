/*
 * IO.h
 *
 *  Created on: Mar 23, 2024
 *      Author: rode-
 */

#ifndef INC_IO_IO_H_
#define INC_IO_IO_H_

#include <stdlib.h>
#include "main.h"
#include "ShiftRegister.h"
#include "../DSP/DSP.h"

ShiftRegister_t filterSelectShiftReg = {
	.clkPort 	 = ShiftRegClk_GPIO_Port,
	.clkPin   	 = ShiftRegClk_Pin,
	.dataPort 	 = ShiftRegData_GPIO_Port,
	.dataPin  	 = ShiftRegData_Pin,
	.enabledPort = ShiftRegEn_GPIO_Port,
	.enabledPin  = ShiftRegEn_Pin
};

// --- !!! Pins and Ports need to change !!! ---
ShiftRegister_t ledbarShiftReg = {
	.clkPort 	 = ShiftRegClk_GPIO_Port,
	.clkPin   	 = ShiftRegClk_Pin,
	.dataPort 	 = ShiftRegData_GPIO_Port,
	.dataPin  	 = ShiftRegData_Pin,
	.enabledPort = ShiftRegEn_GPIO_Port,
	.enabledPin  = ShiftRegEn_Pin
};


enum IOState{
	Disabled,
	SelectingFilter,
	SelectingValue
}typedef IOState_t;

IOState_t IOState;
uint8_t selectedFilter;

void HandleSelectingFilter(uint16_t potValue);
// I Think this functions isn't needed anymore
//void filter_led(uint8_t *filter_led_array, int pressed, int filter);
void HandleSelectingValue(uint16_t analoge_waarde, uint8_t *ledbar_array);

uint16_t main_call();


#endif /* INC_IO_IO_H_ */





