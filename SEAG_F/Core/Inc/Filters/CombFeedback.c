
#include "CombFeedback.h"

CombFeedback* initializeCombFeedback(uint32_t sampleRate, float delayS){

    CombFeedback *filter = malloc(sizeof(CombFeedback));

    filter->M = delayS*sampleRate;

    filter->outputSamples = calloc(filter->M, sizeof(int16_t));

    return filter;

}

int16_t combFeedbackAppendSample(CombFeedback *filter, int16_t newSample){

    static const float b0 = 1;
    static const float am = 0.8;

    int16_t output = b0*newSample - am*filter->outputSamples[filter->M-1]; // M - 1 see struct def for explanation

    shiftBuffer(filter->outputSamples, filter->M, output);

    return output;

}

