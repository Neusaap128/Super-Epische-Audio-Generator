/*
 * ShiftRegister.h
 *
 *  Created on: Apr 24, 2024
 *      Author: Joran
 */

#ifndef INC_IO_SHIFTREGISTER_H_
#define INC_IO_SHIFTREGISTER_H_

#include "main.h"
//elke pin dat we nodig hebben voor het aansturen van een shift register (struct voor algemene benadering)
typedef struct{

	GPIO_TypeDef *clkPort;
	uint16_t 	  clkPin;
	GPIO_TypeDef *dataPort;
	uint16_t 	  dataPin;
	GPIO_TypeDef *enabledPort;
	uint16_t 	  enabledPin;


}ShiftRegister_t;

/*
 * gaat het shift register terug op nul zetten dat het leeg is voor we beginnen
 */
void ResetShiftRegister(ShiftRegister_t *reg);

/*
 * gaat asychroon shift register gaan in laden
 * geeft een 8bit getal en gaat kijken of deze op 0 of 1 staat bij 1 gaat led aan op 0 uit
 * voor de juiste pinnen geeft struct mee
 */
void LoadValueIntoShiftRegister(ShiftRegister_t *reg, uint8_t num);

#endif /* INC_IO_SHIFTREGISTER_H_ */


