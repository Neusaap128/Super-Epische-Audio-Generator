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

/*
 * de pinnen van een rottery
 */
typedef struct{

	uint8_t currentPos;
	GPIO_TypeDef   *portA;
	uint16_t 		pinA;
	GPIO_TypeDef   *portB;
	uint16_t 	    pinB;
	GPIO_TypeDef   *portButton;
	uint16_t 		pinButton;

}RotaryEncoder_t;

/*
 * deze functie gaat kijken in welke van de 4 state dat een rot kan hebben hij zit
 * dit geeft de functie terug in een getal van 8 bits
 */
uint8_t rot_get_state(RotaryEncoder_t* rotEncoder);
/*
 * hiebij gaat het kijken welke stat het zat om te bepalen of het moet opgeteld of verminderd
 */
void rot_intrupt(RotaryEncoder_t* rotEncoder);


#endif /* INC_IO_ROTARYENCODER_H_ */





