
#include "CombFeedforward.h"
#include <math.h>

const float INT24_TO_FLOAT = 1.0/8388608.0;

CombFeedforward* initializeCombFeedforward(uint32_t sampleRate, float delayS){

    CombFeedforward *filter = malloc(sizeof(CombFeedforward));

    filter->offset = 0;

    filter->inputSamples = initializeCircularBuffer(delayS*sampleRate);

    return filter;

}

SampleType combFeedforwardAppendSample(CombFeedforward *filter, SampleType newSample){


    static const float b0 = 1.0;
    static const float bm = 0.9;

    SampleType output = b0*newSample + bm*getValueInCircularBuffer(filter->inputSamples, filter->offset); //+ bm*filter->inputSamples[filter->M-1]) ); // M - 1 see struct def for explanation

    return output;

}
