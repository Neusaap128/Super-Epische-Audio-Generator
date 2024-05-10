/*
 * ShiftRegister.c
 *
 *  Created on: Apr 24, 2024
 *      Author: Joran
 */


#include "ShiftRegister.h"

void ResetShiftRegister(ShiftRegister_t *reg){
	LoadValueIntoShiftRegister(reg, 0x00);
}

void LoadValueIntoShiftRegister(ShiftRegister_t *reg, uint8_t num){

	for (int8_t i = 7; i >= 0; i--) {
		GPIO_PinState bit_value = ((num >> i) & 1)  ? GPIO_PIN_SET : GPIO_PIN_RESET;
		HAL_GPIO_WritePin(reg->dataPort, reg->dataPin, bit_value);
		HAL_Delay(1);
		HAL_GPIO_WritePin(reg->clkPort, reg->clkPin, GPIO_PIN_SET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(reg->clkPort, reg->clkPin, GPIO_PIN_RESET);
	  }

	HAL_GPIO_WritePin(reg->enabledPort, reg->enabledPin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(reg->enabledPort, reg->enabledPin, GPIO_PIN_RESET);
}


