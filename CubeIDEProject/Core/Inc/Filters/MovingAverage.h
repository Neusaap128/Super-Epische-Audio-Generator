/*
 * LowPassFilter.h
 *
 *  Created on: Feb 25, 2024
 *      Author: Joran
 */

#ifndef INC_FILTERS_MOVINGAVERAGE_H_
#define INC_FILTERS_MOVINGAVERAGE_H_

#include <stdint.h>

typedef struct{

	uint16_t x;
	uint16_t* y;

}Filter;

uint16_t MovingAverage(int N, uint16_t* samples);


#endif /* INC_FILTERS_MOVINGAVERAGE_H_ */
