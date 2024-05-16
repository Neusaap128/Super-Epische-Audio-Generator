
#include "CombFeedforward.h"

CombFeedforward* initializeCombFeedforward(uint32_t sampleRate, float delayS){

    CombFeedforward *filter = malloc(sizeof(CombFeedforward));

    filter->M = delayS*sampleRate;
    if(filter->M == 0){
        filter->inputSamples = calloc(sampleRate, sizeof(SampleType));
    }
    else{
        filter->inputSamples = calloc(filter->M, sizeof(SampleType));
    }
    return filter;

}

SampleType combFeedforwardAppendSample(CombFeedforward *filter, SampleType newSample){



    static const float b0 = 1;
    static const float bm = 1;

    SampleType delayedSample = filter->inputSamples[filter->M-1];

    SampleType output = b0*newSample + bm*delayedSample; // M - 1 see struct def for explanation

    //shiftBuffer(filter->inputSamples, filter->M, newSample);


    return output;

}
