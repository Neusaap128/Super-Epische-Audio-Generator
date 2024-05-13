/*
 * DSP.c
 *
 *  Created on: Feb 25, 2024
 *      Author: Joran
 */


#include "DSP.h"
#include "../main.h"

#define BUFFER_SIZE 128

SampleType inputData[BUFFER_SIZE];
SampleType outputData[BUFFER_SIZE];

static volatile SampleType* inputBufPtr = &inputData[0];
static volatile SampleType* outputBufPtr = &outputData[0];

uint8_t dataReadyFlag;

// --- Filters ---
Reverb* reverb;


//0 -> Reverb
//1 -> Low pass
//Etc
uint8_t selectedFilters = 0b00000101;

void InitDSP(uint32_t sampleFrequency, I2S_HandleTypeDef *hi2s1, I2S_HandleTypeDef *hi2s2){

	//Init I²S

	HAL_I2S_Receive_DMA(hi2s2, (uint16_t*)&inputData[0], BUFFER_SIZE/2);
	HAL_I2S_Transmit_DMA(hi2s1, (uint16_t*)&outputData[0], BUFFER_SIZE/2);

    float delayCombS[4] = {0.0297, 0.0371, 0.411, 0.437};
    float delayAllS[2] = {0.005, 0.0017};
	reverb = initializeReverb(sampleFrequency, 4, delayCombS, 2, delayAllS);

}


void DSPUpdate(){

	if(dataReadyFlag){

		for(uint8_t i = 0; i < BUFFER_SIZE/2; i++){
			*(outputBufPtr+i) = AppendSample( *(inputBufPtr+i) );
		}


		dataReadyFlag = 0;
	}

}

SampleType AppendSample(SampleType sample){

	//Filter everything

	return sample;

}

void SetFilterState(uint8_t filterIndex, uint8_t state){
	if(state){
		selectedFilters |= 1 << filterIndex;
	}else{
		selectedFilters &= 0 << filterIndex;
	}
}

uint8_t GetEnabledFilters(){
	return selectedFilters;
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





