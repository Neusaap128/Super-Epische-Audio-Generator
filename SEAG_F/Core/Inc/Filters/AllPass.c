
#include "AllPass.h"

AllPass* initializeAllPass(uint32_t sampleRate, float delayS, float b0, float am){

    AllPass* allPass = malloc(sizeof(AllPass));

    CombFeedforward *combFeedforward = initializeCombFeedforward(sampleRate, delayS);
    CombFeedback *combFeedback = initializeCombFeedback(sampleRate, delayS, b0, am);

    allPass->combFeedforward = combFeedforward;
    allPass->combFeedback = combFeedback;

    return allPass;

}

SampleType  allPassAppendSample(AllPass* filter, SampleType  newSample){

	SampleType  feedForwardOutput = combFeedforwardAppendSample(filter->combFeedforward, newSample);

	SampleType  output = combFeedbackAppendSample(filter->combFeedback, feedForwardOutput);

    return output;

}


