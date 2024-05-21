/*
 * Filters.c
 *
 *  Created on: May 13, 2024
 *      Author: Joran
 */
#include "Filters.h"

Filters* initializeFilters(uint32_t sampleRate){

	Filters* filters = malloc(sizeof(Filters));

	filters->outputLowPass = initializeLowPass(sampleRate, 5000);
	filters->inputLowPass = initializeLowPass(sampleRate, 5000);

    filters->enabledFilters = 0b00000000;

	Distortion* dist = initializeDistortion(1000);
	Filter* distFilter = createFilter(dist, distortionAppendSample, setDistortionLevel);

    CombFeedback* echo = initializeCombFeedback(sampleRate, 0.5, 1.0, 0.5);
    Filter* echoFilter = createFilter(echo, combFeedbackAppendSample, setCombFeedbackLevel);

    float delayCombS[4] = {0.0297, 0.0371, 0.0411, 0.0437};
    float delayAllS[2] = {0.005, 0.0017};
	Reverb* reverb = initializeReverb(sampleRate, 4, delayCombS, 2, delayAllS);
	Filter* reverbFilter = createFilter(reverb, reverbAppendSample, setReverbLevel);

	Flanger* flanger = initializeFlanger(sampleRate, 5.0f, 0.02f);
	Filter* flangerFilter = createFilter(flanger, flangerAppendSample, setFlangerLevel);

	Chorus* chorus = initializeChorus(sampleRate);
	Filter* chorusFilter = createFilter(chorus, chorusAppendSample, setChorusLevel);


    filters->filterInstances[0] = distFilter;
    filters->filterInstances[1] = echoFilter;
    filters->filterInstances[2] = reverbFilter;
    filters->filterInstances[3] = flangerFilter;
    filters->filterInstances[4] = chorusFilter;

    return filters;

}


SampleType appendSample(Filters* filters, SampleType newSample){

	SampleType previousOutput = lowPassAppendSample(filters->inputLowPass, newSample);

	for(uint8_t i = 0; i < AMOUNT_OF_FILTERS; i++){

		uint8_t filterEnabled = (filters->enabledFilters >> i) & 1;
		if(filterEnabled){
			previousOutput = filterAppendSample(filters->filterInstances[i], previousOutput);
		}

	}

	return lowPassAppendSample(filters->outputLowPass, previousOutput);

}


