
#include "CombFeedback.h"

CombFeedback* initializeCombFeedback(uint32_t sampleRate, float delayS, float amplification, float attenuation){

    CombFeedback *filter = malloc(sizeof(CombFeedback));

    filter->offset = 0;
    filter->outputSamples = initializeCircularBuffer( delayS*sampleRate);

    filter->K = amplification;
    setCombFeedbackLevel(filter, attenuation);

    filter->lowPass = initializeLowPass(sampleRate, 1760);

    return filter;

}

SampleType combFeedbackAppendSample(CombFeedback *filter, SampleType newSample){

	SampleType lowPassedDelayedOutput = lowPassAppendSample( filter->lowPass, getValueInCircularBuffer(filter->outputSamples, filter->offset) ); //voor de ruis te bepreken voegen we een lowpas filter toe

	SampleType output = (filter->K)*(newSample - (filter->a)*lowPassedDelayedOutput);

	putValueInCircularBuffer(filter->outputSamples, output);

    return output;

}

void setCombFeedbackLevel(CombFeedback *combfeedback, float a){

	if(a > 1.0f) a = 1.0f;
	if(a < 0.0f) a = 0.0f;

	float value = pow(a, 1.0f/5.0f); //More resolution the higher a gets

    combfeedback->a = value;

}
