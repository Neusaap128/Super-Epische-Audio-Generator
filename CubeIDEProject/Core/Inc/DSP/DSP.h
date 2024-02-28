/*
 * DSP.h
 *
 *  Created on: Feb 25, 2024
 *      Author: Joran
 */

#ifndef INC_DSP_DSP_H_
#define INC_DSP_DSP_H_


#include "stm32g4xx_hal.h"
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "../Filters/MovingAverage.h"

extern const int N;
extern const int samplingRate;

void InitDSP();
void AppendSample(uint16_t sample);
void TimerCallback(ADC_HandleTypeDef* hadc1, UART_HandleTypeDef* hlpuart1);
void ApplyFilters();


#endif /* INC_DSP_DSP_H_ */
