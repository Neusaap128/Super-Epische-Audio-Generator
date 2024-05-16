/*
 * Filters.c
 *
 *  Created on: May 13, 2024
 *      Author: Joran
 */
#include "Filters.h"

Filters* initializeFilters(uint32_t sampleRate){

	Filters* filters = malloc(sizeof(Filters));

    filters->enabledFilters = 0x01;

    float delayCombS[4] = {0.0297, 0.0371, 0.411, 0.437};
    float delayAllS[2] = {0.005, 0.0017};
	Reverb* reverb = initializeReverb(sampleRate, 4, delayCombS, 2, delayAllS);

    filters->filterStructs[0] = reverb;
    filters->filterMethods[0] = reverbAppendSample;

    return filters;

}


SampleType appendSample(Filters* filters, SampleType newSample){

	SampleType previousOutput = newSample;

	for(uint8_t i = 0; i < AMOUNT_OF_FILTERS; i++){

		uint8_t filterEnabled = (filters->enabledFilters >> i) & 1;
		if(filterEnabled){
			previousOutput = filters->filterMethods[i](filters->filterStructs[0], previousOutput);
		}

	}

	return previousOutput;

}


