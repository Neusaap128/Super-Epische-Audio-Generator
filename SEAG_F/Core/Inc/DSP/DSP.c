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


// --- Filters ---

Filters* filters;

uint32_t sampleFrequency;

void InitDSP(uint32_t _sampleFrequency, I2S_HandleTypeDef *hi2s1, I2S_HandleTypeDef *hi2s2){

	sampleFrequency =_sampleFrequency;
	//Init filters
	filters = initializeFilters(_sampleFrequency);

	//Init I²S
	HAL_I2S_Transmit_DMA(hi2s1, (uint16_t*)&outputData[0], BUFFER_SIZE);
	HAL_I2S_Receive_DMA(hi2s2, (uint16_t*)&inputData[0], BUFFER_SIZE);

}


void DSPUpdate(){


	if(dataReadyFlag){
		float freq = 10;
		for(uint8_t i = 0; i < BUFFER_SIZE/2; i++){
			// Process left channel
			if(i % 2 == 0){

				//int16_t sinValue = sinApproxLut(2*M_PI*(float)j/(BUFFER_SIZE));
				*(outputBufPtr+i) = appendSample(filters, *(inputBufPtr+i));

			}else{
				*(outputBufPtr+i) = (int16_t)(0);
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





