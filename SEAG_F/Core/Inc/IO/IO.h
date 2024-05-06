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


typedef enum{
	Disabled,
	SelectingFilter,
	SelectingValue
}IOState_t;


// Registers
uint8_t HandleSelectingFilter();
void HandleSelectingValue();

// Rotary Encoder
void ButtonInterrupt(uint32_t time);
void RotaryEncoderInterrupt();

uint16_t main_call();


#endif /* INC_IO_IO_H_ */





