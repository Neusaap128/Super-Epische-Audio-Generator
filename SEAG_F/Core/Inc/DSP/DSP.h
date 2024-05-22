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

/*
 * Initialize the filters and start the DMA streams
 */
void InitDSP(uint32_t sampleFrequency, I2S_HandleTypeDef *hi2s1, I2S_HandleTypeDef *hi2s2);

/*
 * When dataReadyFlag is set, this method will calculate the output buffer
 */
void DSPUpdate();

/*
 * Set the enabled filters
 */
void SetFilterStates(uint8_t states);

/*
 * Get the enabled filters
 */
uint8_t GetEnabledFilters();

/*
 * Get the Filters struct instance
 */
Filters* getFilters();

#endif /* INC_DSP_DSP_H_ */
