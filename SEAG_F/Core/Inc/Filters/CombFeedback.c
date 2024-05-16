
#include "CombFeedback.h"

CombFeedback* initializeCombFeedback(uint32_t sampleRate, float delayS, float verzwakking, float am){

    CombFeedback *filter = malloc(sizeof(CombFeedback));

    filter->M = delayS*sampleRate;
    filter->bufferSize = filter->M;
    filter->b0 = verzwakking;
    filter->am = am;
    filter->outputSamples = calloc(filter->M, sizeof(SampleType));

    return filter;

}

SampleType combFeedbackAppendSample(CombFeedback *filter, SampleType newSample){

    //static const float b0 = 0.5;
    //static const float am = 0.8;

	SampleType output = (filter->b0)*newSample - (filter->am)*filter->outputSamples[filter->M-1]; // M - 1 see struct def for explanation

    shiftBuffer(filter->outputSamples, filter->bufferSize, output);

    return output;

}

