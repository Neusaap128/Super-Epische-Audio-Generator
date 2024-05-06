/*
 * RotaryEncoder.c
 *
 *  Created on: may 6, 2024
 *      Author: Floran
 */


#include "RotaryEncoder.h"

uint8_t rot_old_state =0;
uint8_t rot_new_state=0;

uint8_t rot_get_state() {
	return (uint8_t)((HAL_GPIO_ReadPin(RotEncoderInB_GPIO_Port, RotEncoderInB_Pin) << 1)
                | (HAL_GPIO_ReadPin(RotEncoderInA_GPIO_Port, RotEncoderInA_Pin)));
}

void rot_intrupt(){
	  rot_new_state = rot_get_state();
	  		// Check transition
	  if (rot_old_state == 3 && rot_new_state == 2) {        // 3 -> 2 transition
	  	rot_cnt++;
	  } else if (rot_old_state == 2 && rot_new_state == 0) { // 2 -> 0 transition
	  	rot_cnt++;
	  } else if (rot_old_state == 0 && rot_new_state == 1) { // 0 -> 1 transition
	  	rot_cnt++;
	  } else if (rot_old_state == 1 && rot_new_state == 3) { // 1 -> 3 transition
	  	rot_cnt++;
	  } else if (rot_old_state == 3 && rot_new_state == 1) { // 3 -> 1 transition
	  	rot_cnt--;
	  } else if (rot_old_state == 1 && rot_new_state == 0) { // 1 -> 0 transition
	  	rot_cnt--;
	  } else if (rot_old_state == 0 && rot_new_state == 2) { // 0 -> 2 transition
	  	rot_cnt--;
	  } else if (rot_old_state == 2 && rot_new_state == 3) { // 2 -> 3 transition
	  	rot_cnt--;
	  }
	  rot_old_state = rot_new_state;
}




