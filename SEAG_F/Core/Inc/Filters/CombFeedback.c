
#include "CombFeedback.h"

CombFeedback* initializeCombFeedback(uint32_t sampleRate, float delayS){

    CombFeedback *filter = malloc(sizeof(CombFeedback));

    filter->M = delayS*sampleRate;

    filter->outputSamples = calloc(filter->M, sizeof(SampleType));

    return filter;

}

SampleType combFeedbackAppendSample(CombFeedback *filter, SampleType newSample){

    static const float b0 = 1;
    static const float am = 0.8;

    SampleType output = b0*newSample - am*filter->outputSamples[filter->M-1]; // M - 1 see struct def for explanation

    shiftBuffer(filter->outputSamples, filter->M, output);

    return output;

}

