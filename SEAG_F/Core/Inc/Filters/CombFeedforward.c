
#include "CombFeedforward.h"

CombFeedforward* initializeCombFeedforward(uint32_t sampleRate, float delayS){

    CombFeedforward *filter = malloc(sizeof(CombFeedforward));

    filter->M = delayS*sampleRate;

    filter->inputSamples = calloc(filter->M, sizeof(int16_t));

    return filter;

}

int16_t combFeedforwardAppendSample(CombFeedforward *filter, int16_t newSample){

    static const float b0 = 1;
    static const float bm = 0.8;

    int16_t output = b0*newSample + bm*filter->inputSamples[filter->M-1]; // M - 1 see struct def for explanation

    shiftBuffer(filter->inputSamples, filter->M, newSample);

    return output;

}
