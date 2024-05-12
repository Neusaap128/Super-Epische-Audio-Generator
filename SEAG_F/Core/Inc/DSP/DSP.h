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
#include "../Filters/Reverb.h"
#include "../main.h"

#define AMOUNT_OF_FILTERS 4

typedef int32_t SampleType;



void InitDSP(uint32_t sampleFrequency, I2S_HandleTypeDef *hi2s1, I2S_HandleTypeDef *hi2s2);
void DSPUpdate();

SampleType AppendSample(SampleType sample);

void SetFilterState(uint8_t filterIndex, uint8_t state);
uint8_t GetEnabledFilters();


#endif /* INC_DSP_DSP_H_ */
