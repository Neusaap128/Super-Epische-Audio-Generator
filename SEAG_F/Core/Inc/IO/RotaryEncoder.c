/*
 * RotaryEncoder.c
 *
 *  Created on: may 6, 2024
 *      Author: Floran
 */


#include "RotaryEncoder.h"

uint8_t rot_old_state =0;
uint8_t rot_new_state=0;


uint8_t rot_get_state(RotaryEncoder_t* rotEncoder) {
	return (uint8_t)( (HAL_GPIO_ReadPin(rotEncoder->portB, rotEncoder->pinB) << 1)
                	| (HAL_GPIO_ReadPin(rotEncoder->portA, rotEncoder->pinA)) );
}

//deze functie overloopt 4 fase van een rotery encoder, eerst stijgen de klokflank 1 van de 2 fase beide hoog
//3de fase de eerste die hoog was terug laag word en 4de fase allebei laag
void rot_intrupt(RotaryEncoder_t* rotEncoder){

	  rot_new_state = rot_get_state(rotEncoder);
	  		// Check transition
	  if (rot_old_state == 3 && rot_new_state == 2) {        // 3 -> 2 transition
		  rotEncoder->currentPos++;
	  } else if (rot_old_state == 2 && rot_new_state == 0) { // 2 -> 0 transition
		  rotEncoder->currentPos++;
	  } else if (rot_old_state == 0 && rot_new_state == 1) { // 0 -> 1 transition
		  rotEncoder->currentPos++;
	  } else if (rot_old_state == 1 && rot_new_state == 3) { // 1 -> 3 transition
		  rotEncoder->currentPos++;
	  } else if (rot_old_state == 3 && rot_new_state == 1) { // 3 -> 1 transition
		  rotEncoder->currentPos--;
	  } else if (rot_old_state == 1 && rot_new_state == 0) { // 1 -> 0 transition
		  rotEncoder->currentPos--;
	  } else if (rot_old_state == 0 && rot_new_state == 2) { // 0 -> 2 transition
		  rotEncoder->currentPos--;
	  } else if (rot_old_state == 2 && rot_new_state == 3) { // 2 -> 3 transition
		  rotEncoder->currentPos--;
	  }
	  rot_old_state = rot_new_state;
}




