/*
 * DSP.c
 *
 *  Created on: Feb 25, 2024
 *      Author: Joran
 */


#include "DSP.h"
#include "../main.h"
#include "../Filters/FilterUtility/FilterUtility.h"

// --- I²S ---

#define BUFFER_SIZE 128

SampleType inputData[BUFFER_SIZE];
SampleType outputData[BUFFER_SIZE];

static volatile SampleType* inputBufPtr = &inputData[0];
static volatile SampleType* outputBufPtr = &outputData[0];

uint8_t dataReadyFlag;

// --- filters ---
Filters* filters;

void InitDSP(uint32_t sampleFrequency, I2S_HandleTypeDef *hi2s1, I2S_HandleTypeDef *hi2s2){

	//Init filters
	filters = initializeFilters(sampleFrequency);

	//Init I²S
	HAL_I2S_Transmit_DMA(hi2s1, (uint16_t*)&outputData[0], BUFFER_SIZE);
	HAL_I2S_Receive_DMA(hi2s2, (uint16_t*)&inputData[0], BUFFER_SIZE);

}


void DSPUpdate(){


	if(dataReadyFlag){

		for(uint8_t i = 0; i < BUFFER_SIZE/2; i++){

			// Process left channel
			if(i % 2 == 0){
				*(outputBufPtr+i) = appendSample(filters, *(inputBufPtr+i));

			}else{
				*(outputBufPtr+i) = (int16_t)(0);
			}

		}
		dataReadyFlag = 0;
	}


}


void SetFilterStates(uint8_t states){

	filters->enabledFilters = states;

}

uint8_t GetEnabledFilters(){
	return filters->enabledFilters;
}

Filters* getFilters(){
	return filters;
}

void HAL_I2S_RxHalfCpltCallback(I2S_HandleTypeDef *hi2s){

	inputBufPtr = &inputData[0];
	outputBufPtr = &outputData[0];

	dataReadyFlag = 1;

}

void HAL_I2S_RxCpltCallback(I2S_HandleTypeDef *hi2s){

	inputBufPtr = &inputData[BUFFER_SIZE/2];
	outputBufPtr = &outputData[BUFFER_SIZE/2];

	dataReadyFlag = 1;

}





