/*
 * Filters.c
 *
 *  Created on: May 13, 2024
 *      Author: Joran
 */
#include "Filters.h"

Filters* initializeFilters(uint32_t sampleRate){

	Filters* filters = malloc(sizeof(Filters));

    filters->enabledFilters = 0b010;


    CombFeedback* echo = initializeCombFeedback(sampleRate, 0.5, 1.0, 0.5);

    float delayCombS[4] = {0.0297, 0.0371, 0.411, 0.437};
    float delayAllS[2] = {0.005, 0.0017};
	Reverb* reverb = initializeReverb(sampleRate, 4, delayCombS, 2, delayAllS);


	Flanger* flanger = initializeFlanger(sampleRate, 1.5, 0.05);


    filters->filterStructs[0] = echo;
    filters->filterMethods[0] = combFeedbackAppendSample;

    filters->filterStructs[1] = reverb;
    filters->filterMethods[1] = reverbAppendSample;

    filters->filterStructs[2] = flanger;
    filters->filterMethods[2] = flangerAppendSample;

    return filters;

}


SampleType appendSample(Filters* filters, SampleType newSample){

	SampleType previousOutput = newSample;

	for(uint8_t i = 0; i < AMOUNT_OF_FILTERS; i++){

		uint8_t filterEnabled = (filters->enabledFilters >> i) & 1;
		if(filterEnabled){
			SampleType (*filterMethod)(void*, SampleType) = filters->filterMethods[i];
			void* filterStruct = filters->filterStructs[i];
			previousOutput = filterMethod(filterStruct, previousOutput);
		}

	}

	return previousOutput;

}


