/*
 * Filter.c
 *
 *  Created on: May 20, 2024
 *      Author: Joran
 */

#include "Filter.h"

Filter* createFilter(void* filterStruct, SampleType (*filterMethod)(void*, SampleType), void (*changeLevelMethod)(void*, float) ){

	Filter* filter = malloc(sizeof(Filter));

	filter->filterStruct = filterStruct;
	filter->filterMethod = filterMethod;
	filter->changeLevelMethod = changeLevelMethod;

	return filter;
}


void changeFilterLevel(Filter* filter, float a){
	filter->changeLevelMethod(filter->filterStruct, a);
}

SampleType filterAppendSample(Filter* filter, SampleType newSample){
	return filter->filterMethod(filter->filterStruct, newSample);
}

