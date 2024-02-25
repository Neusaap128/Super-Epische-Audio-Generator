/*
 * LowPassFilter.c
 *
 *  Created on: Feb 25, 2024
 *      Author: Joran
 */

#include <Filters/MovingAverage.h>


uint16_t MovingAverage(int N, uint16_t* samples){

	uint32_t sum = 0;
	for(uint32_t i = 0; i < N; i++){
		sum += samples[i];
	}

	return (uint16_t)(sum/N);

}
