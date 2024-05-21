/*
 * DSP.h
 *
 *  Created on: Feb 25, 2024
 *      Author: Joran
 */

#ifndef INC_DSP_DSP_H_
#define INC_DSP_DSP_H_


#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "../Common.h"
#include "../Filters/Filters.h"
#include "../main.h"
#include "../Filters/Flanger.h"

void InitDSP(uint32_t sampleFrequency, I2S_HandleTypeDef *hi2s1, I2S_HandleTypeDef *hi2s2);
void DSPUpdate();

void SetFilterStates(uint8_t states);
uint8_t GetEnabledFilters();

Filters* getFilters();

#endif /* INC_DSP_DSP_H_ */
