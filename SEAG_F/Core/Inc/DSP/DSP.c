/*
 * DSP.c
 *
 *  Created on: Feb 25, 2024
 *      Author: Joran
 */


#include "DSP.h"
#include "../main.h"


const int N = 64;
const int samplingRate = 44E3; //44Khz

SampleType* previousSamples;
SampleType* previousOutputs;

void InitDSP(){
	previousSamples = (SampleType*)malloc(N*sizeof(SampleType));
	previousOutputs = (SampleType*)malloc(N*sizeof(SampleType));
}

void AppendSample(SampleType sample){

	for(int i = N-2; i >= 0; i--){
		previousSamples[i+1] = previousSamples[i];
	}

	previousSamples[0] = sample;

}

/*
void TimerCallback(ADC_HandleTypeDef* hadc1, UART_HandleTypeDef* hlpuart1, DAC_HandleTypeDef* hdac1){

	HAL_ADC_Start(hadc1);
	HAL_ADC_PollForConversion(hadc1, HAL_MAX_DELAY);
	SampleType audioSample = HAL_ADC_GetValue(hadc1);

	//char msg[50];
	//sprintf(msg, "%d\r\n", (int)audioSample);
	//HAL_UART_Transmit(hlpuart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	//AppendSample(audioSample);

	DAC1->DHR12R1 = audioSample;

	HAL_GPIO_TogglePin(SampleFreqOutClk_GPIO_Port, SampleFreqOutClk_Pin);

}
*/

void ApplyFilters(){


	//output = MovingAverage(previousSamples, previousOutputs);

	//previousOutputs[0] = output;

	//output += TweedeFilter(previousOutputs, previousOutputs); //dees is niet hoe ge filters combineert!!! moet ik nog uitvogelen



}







