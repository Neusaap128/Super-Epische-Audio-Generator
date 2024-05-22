/*
 * ShiftRegister.c
 *
 *  Created on: Apr 24, 2024
 *      Author: Joran
 */


#include "ShiftRegister.h"

void ResetShiftRegister(ShiftRegister_t *reg){
	LoadValueIntoShiftRegister(reg, 0x00);		//steekt nullen in register dat alles uit staat
}

void LoadValueIntoShiftRegister(ShiftRegister_t *reg, uint8_t num){

	for (int8_t i = 0; i < 8; i++) {	//gaat 8 keer shifte zodat de juiste waarde er instaat
		GPIO_PinState bit_value = ((num >> i) & 1)  ? GPIO_PIN_SET : GPIO_PIN_RESET;  //gaat kijken of op die plaats 1 of 0 moet komen
		HAL_GPIO_WritePin(reg->dataPort, reg->dataPin, bit_value);
		HAL_Delay(1);
		HAL_GPIO_WritePin(reg->clkPort, reg->clkPin, GPIO_PIN_SET); //gaat de klok het laten doorschuiven
		HAL_Delay(1);
		HAL_GPIO_WritePin(reg->clkPort, reg->clkPin, GPIO_PIN_RESET);
	  }

	HAL_GPIO_WritePin(reg->enabledPort, reg->enabledPin, GPIO_PIN_SET);	//voor data te krijgen moet je de enabel op en af zetten zo krijg je de output buiten
	HAL_Delay(1);
	HAL_GPIO_WritePin(reg->enabledPort, reg->enabledPin, GPIO_PIN_RESET);
}


