
#include "CombFeedforward.h"
#include <math.h>

CombFeedforward* initializeCombFeedforward(uint32_t sampleRate, float delayS){

    CombFeedforward *filter = malloc(sizeof(CombFeedforward));

    filter->M = delayS*sampleRate;
    filter->inputSamples = calloc(filter->M, sizeof(SampleType));

    return filter;

}

SampleType combFeedforwardAppendSample(CombFeedforward *filter, SampleType newSample){


    static const float b0 = 1.0f;
    static const float bm = 1-b0;


    SampleType output = 0;
    output = (SampleType)( (b0*newSample + bm*filter->inputSamples[filter->M-1]) ); // M - 1 see struct def for explanation


    //shiftBuffer(filter->inputSamples, filter->M, newSample);


    return output;

}
