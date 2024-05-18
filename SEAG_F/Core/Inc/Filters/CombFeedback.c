
#include "CombFeedback.h"

CombFeedback* initializeCombFeedback(uint32_t sampleRate, float delayS, float amplification, float attenuation){

    CombFeedback *filter = malloc(sizeof(CombFeedback));

    filter->offset = 0;
    filter->outputSamples = initializeCircularBuffer( delayS*sampleRate);

    filter->K = amplification;
    filter->a = attenuation;

    return filter;

}

SampleType combFeedbackAppendSample(CombFeedback *filter, SampleType newSample){

	SampleType output = (filter->K)*(newSample - (filter->a)*getValueInCircularBuffer(filter->outputSamples, filter->offset)); // M - 1 see struct def for explanation

	putValueInCircularBuffer(filter->outputSamples, output);

    return output;

}

