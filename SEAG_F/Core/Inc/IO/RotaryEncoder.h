/*
 * RotaryEncoder.h
 *
 *  Created on: may 6, 2024
 *      Author: Floran
 */

#ifndef INC_IO_IO_H_
#define INC_IO_IO_H_

#include <stdlib.h>
#include "main.h"
#include "ShiftRegister.h"
#include "../DSP/DSP.h"
//maak globale varaible rot_cnt voor intrupt
uint8_t rot_get_state();
void rot_intrupt();


#endif /* INC_IO_IO_H_ */





