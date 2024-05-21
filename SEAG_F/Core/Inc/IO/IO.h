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
#include "../Common.h"
#include "../DSP/DSP.h"

typedef enum{
	Disabled,
	SelectingFilter,
	SelectingValue
}IOState_t;


void InitIO();

// Registers
void HandleSelectingFilter();
void HandleSelectingValue();
void UpdateLedsActiveFilters();

// Rotary Encoder
void ButtonInterrupt();
void RotaryEncoderInterrupt();

void IOUpdate();


#endif /* INC_IO_IO_H_ */





