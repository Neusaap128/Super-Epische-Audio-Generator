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

ShiftRegister_t shiftRegFilterSelect = {
	.clkPort 	 = ShiftRegFClk_GPIO_Port,
	.clkPin   	 = ShiftRegFClk_Pin,
	.dataPort 	 = ShiftRegFDat_GPIO_Port,
	.dataPin  	 = ShiftRegFDat_Pin,
	.enabledPort = ShiftRegFStoClk_GPIO_Port,
	.enabledPin  = ShiftRegFStoClk_Pin
};


ShiftRegister_t shiftRegLedbar = {
	.clkPort 	 = ShiftRegLBarClk_GPIO_Port,
	.clkPin   	 = ShiftRegLBarClk_Pin,
	.dataPort 	 = ShiftRegLBarDat_GPIO_Port,
	.dataPin  	 = ShiftRegLBarDat_Pin,
	.enabledPort = ShiftRegLBarStoClk_GPIO_Port,
	.enabledPin  = ShiftRegLBarStoClk_Pin
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
void HandleSelectingValue(uint16_t analoge_waarde /*, uint8_t *ledbar_array*/ );

uint16_t main_call();


#endif /* INC_IO_IO_H_ */





