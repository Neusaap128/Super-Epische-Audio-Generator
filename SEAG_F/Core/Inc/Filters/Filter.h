/*
 * Filter.h
 *
 *  Created on: May 20, 2024
 *      Author: Joran
 */

#ifndef INC_FILTERS_FILTER_H_
#define INC_FILTERS_FILTER_H_

#include <stdlib.h>
#include "../Common.h"

typedef struct{

	void* filterStruct;
	SampleType (*filterMethod)(void*, SampleType);
	void (*changeLevelMethod)(void*, float a);

}Filter;

Filter* createFilter(void* filterStruct, SampleType (*filterMethod)(void*, SampleType), void (*changeLevelMethod)(void*, float) );
SampleType filterAppendSample(Filter* filter, SampleType newSample);
void changeFilterLevel(Filter* filter, float a);

#endif /* INC_FILTERS_FILTER_H_ */
