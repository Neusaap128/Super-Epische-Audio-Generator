/*
 * RotaryEncoder.h
 *
 *  Created on: may 6, 2024
 *      Author: Floran
 */

#ifndef INC_IO_ROTARYENCODER_H_
#define INC_IO_ROTARYENCODER_H_

#include <stdlib.h>
#include "main.h"

typedef struct{

	uint8_t currentPos;
	GPIO_TypeDef   *portA;
	uint16_t 		pinA;
	GPIO_TypeDef   *portB;
	uint16_t 	    pinB;
	GPIO_TypeDef   *portButton;
	uint16_t 		pinButton;

}RotaryEncoder_t;

uint8_t rot_get_state(RotaryEncoder_t* rotEncoder);
void rot_intrupt(RotaryEncoder_t* rotEncoder);


#endif /* INC_IO_ROTARYENCODER_H_ */





