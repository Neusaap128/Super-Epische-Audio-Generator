/*
 * DSP.c
 *
 *  Created on: Feb 25, 2024
 *      Author: Joran
 */


#include "DSP.h"

const int N = 1024;
const int samplingRate = 44E3; //44Khz

uint16_t* previousSamples;
uint16_t* previousOutputs;

void InitDSP(){
	previousSamples = (uint16_t*)malloc(N*sizeof(uint16_t));
	previousOutputs = (uint16_t*)malloc(N*sizeof(uint16_t));
}

void AppendSample(uint16_t sample){

	for(int i = N-2; i >= 0; i--){
		previousSamples[i+1] = previousSamples[i];
	}

	previousSamples[0] = sample;

}


void TimerCallback(ADC_HandleTypeDef* hadc1){

	HAL_ADC_Start(hadc1);
	HAL_ADC_PollForConversion(hadc1, HAL_MAX_DELAY);
	uint16_t audioSample = HAL_ADC_GetValue(hadc1);

	AppendSample(audioSample);

}


uint16_t ApplyFilters(){

	uint16_t output = 0;

	output = MovingAverage(previousSamples, previousOutputs);

	previousOutputs[0] = output;

	output += TweedeFilter(previousOutputs, previousOutputs); //dees is niet hoe ge filters combineert!!! moet ik nog uitvogelen

	return output;

}







