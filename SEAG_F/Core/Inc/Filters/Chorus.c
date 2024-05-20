#include "Chorus.h"


Chorus* initializeChorus(uint32_t sampleRate){

    Chorus* filter = malloc(sizeof(Chorus));

    filter->delayLowPass = initializeLowPass(sampleRate, 10);
    
    filter->amountOfFeedforwardFilters = 2;
    filter->previousDelays = calloc(filter->amountOfFeedforwardFilters, sizeof(float));

    filter->a = 0.9999f;

    filter->combFeedforwardFilters = malloc(filter->amountOfFeedforwardFilters*sizeof(CombFeedforward));

    float delayS[2] = {0.03f, 0.050f};

    for(uint8_t i = 0; i < filter->amountOfFeedforwardFilters; i++){
        filter->previousDelays[i] = sampleRate*delayS[i]/2;
        filter->combFeedforwardFilters[i] = initializeCombFeedforward(sampleRate, delayS[i], 1.0f, 0.99f);

    }

    return filter;

}

SampleType chorusAppendSample(Chorus *filter, SampleType input){

	SampleType output = 0;

    for(uint8_t i = 0; i < filter->amountOfFeedforwardFilters; i++){
        uint16_t rawDelay = rand() % filter->combFeedforwardFilters[i]->inputSamples->bufferSize; // max delay in sample amount

        filter->previousDelays[i] = filter->a*filter->previousDelays[i] + (1.0f-filter->a)*rawDelay;

        uint16_t delay = (uint16_t)filter->previousDelays[i];

        filter->combFeedforwardFilters[i]->offset = delay;

        
        output += combFeedforwardAppendSample(filter->combFeedforwardFilters[i], input)/filter->amountOfFeedforwardFilters;

    }

    return output;

}

void setChorusLevel(Chorus* filter, float a){

	for(uint8_t i = 0 ;i < filter->amountOfFeedforwardFilters; i++){

		setCombFeedforwardLevel(filter->combFeedforwardFilters[i], a);

	}

}

