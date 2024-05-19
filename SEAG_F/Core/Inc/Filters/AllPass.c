
#include "AllPass.h"

AllPass* initializeAllPass(uint32_t sampleRate, float delayS, float amplification, float attenuation){

    AllPass* allPass = malloc(sizeof(AllPass));

    CombFeedforward *combFeedforward = initializeCombFeedforward(sampleRate, delayS, amplification, attenuation);
    CombFeedback *combFeedback = initializeCombFeedback(sampleRate, delayS, amplification, attenuation);

    allPass->combFeedforward = combFeedforward;
    allPass->combFeedback = combFeedback;

    return allPass;

}

SampleType  allPassAppendSample(AllPass* filter, SampleType  newSample){

	SampleType feedForwardOutput = combFeedforwardAppendSample(filter->combFeedforward, newSample);

	SampleType output = combFeedbackAppendSample(filter->combFeedback, feedForwardOutput);

    return output;

}

void setAllPassOffset(AllPass* allPass, uint32_t offset){

	allPass->combFeedback->offset = offset;
	allPass->combFeedforward->offset = offset;

}


