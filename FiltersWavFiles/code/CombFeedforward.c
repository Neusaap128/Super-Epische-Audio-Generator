
#include "CombFeedforward.h"

CombFeedforward* initializeCombFeedforward(uint32_t sampleRate, float delayS, float amplification, float attenuation){

    CombFeedforward *filter = malloc(sizeof(CombFeedforward));

    filter->offset = 0;
    
    filter->K = amplification;
    setCombFeedforwardLevel(filter, attenuation);

    filter->inputSamples = initializeCircularBuffer(delayS*sampleRate);
    
    return filter;

}

int16_t combFeedforwardAppendSample(CombFeedforward *filter, int16_t newSample){

    int16_t output = filter->K*newSample + filter->a*getValueInCircularBuffer(filter->inputSamples, filter->offset);

    putValueInCircularBuffer(filter->inputSamples, newSample);

    return output;

}

void setCombFeedforwardLevel(CombFeedforward *combfeedback, float a){

	if(a > 1.0f) a = 1.0f;
	if(a < 0.0f) a = 0.0f;

	float value = pow(a, 1.0f/5.0f); //More resolution the higher a gets

	combfeedback->a = value;

}

