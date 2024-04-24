/*
 * ShiftRegister.h
 *
 *  Created on: Apr 24, 2024
 *      Author: Joran
 */

#ifndef INC_IO_SHIFTREGISTER_H_
#define INC_IO_SHIFTREGISTER_H_

#include "main.h"

struct ShiftRegister{

	GPIO_TypeDef *clkPort;
	uint16_t 	  clkPin;
	GPIO_TypeDef *dataPort;
	uint16_t 	  dataPin;
	GPIO_TypeDef *enabledPort;
	uint16_t 	  enabledPin;


}typedef ShiftRegister_t;

void ResetShiftRegister(ShiftRegister_t *reg);
void LoadValueIntoShiftRegister(ShiftRegister_t *reg, uint8_t num);

#endif /* INC_IO_SHIFTREGISTER_H_ */


