/*
 * DSP.c
 *
 *  Created on: Feb 25, 2024
 *      Author: Joran
 */


#include "DSP.h"
#include "../main.h"


// --- I²S ---

#define BUFFER_SIZE 128

SampleType inputData[BUFFER_SIZE];
SampleType outputData[BUFFER_SIZE];

static volatile SampleType* inputBufPtr = &inputData[0];
static volatile SampleType* outputBufPtr = &outputData[0];

uint8_t dataReadyFlag;


// --- Filters ---

Filters* filters;
CombFeedforward* echo;

void InitDSP(uint32_t sampleFrequency, I2S_HandleTypeDef *hi2s1, I2S_HandleTypeDef *hi2s2){


	//Init filters
	filters = initializeFilters(sampleFrequency);

	float delayCombS[4] = {0.0297, 0.0371, 0.411, 0.437};
	float delayAllS[2] = {0.005, 0.0017};
	echo = initializeCombFeedforward(sampleFrequency, 0.2);

	//Init I²S
	HAL_I2S_Receive_DMA(hi2s2, (uint16_t*)&inputData[0], BUFFER_SIZE/2);
	HAL_I2S_Transmit_DMA(hi2s1, (uint16_t*)&outputData[0], BUFFER_SIZE/2);

}


void DSPUpdate(){

	if(dataReadyFlag){

		for(uint8_t i = 0; i < BUFFER_SIZE/2; i++){

			// Process left channel
			if(i % 2 == 0){
				*(outputBufPtr+i) = combFeedforwardAppendSample(echo, *(inputBufPtr+i));
			}else{
				*(outputBufPtr+i) = 0;
			}

		}


		dataReadyFlag = 0;
	}

}


void SetFilterState(uint8_t filterIndex, uint8_t state){

	if(filterIndex >= AMOUNT_OF_FILTERS)
		return;

	if(state){
		filters->enabledFilters |= 1 << filterIndex;
	}else{
		filters->enabledFilters &= 0 << filterIndex;
	}
}

uint8_t GetEnabledFilters(){
	return filters->enabledFilters;
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





