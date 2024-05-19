
#include "CombFeedforward.h"

CombFeedforward* initializeCombFeedforward(uint32_t sampleRate, float delayS, float amplification, float attenuation){

    CombFeedforward *filter = malloc(sizeof(CombFeedforward));

    filter->offset = 0;
    
    filter->K = amplification;
    filter->a = attenuation;

    filter->inputSamples = initializeCircularBuffer(delayS*sampleRate);
    
    return filter;

}

int16_t combFeedforwardAppendSample(CombFeedforward *filter, int16_t newSample){

    int16_t output = filter->K*newSample + filter->a*getValueInCircularBuffer(filter->inputSamples, filter->offset);

    putValueInCircularBuffer(filter->inputSamples, newSample);

    return output;

}
