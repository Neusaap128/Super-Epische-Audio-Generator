
#include "AllPass.h"

AllPass* initializeAllPass(uint32_t sampleRate, float delayS){

    AllPass* allPass = malloc(sizeof(AllPass));

    CombFeedforward *combFeedforward = initializeCombFeedforward(sampleRate, delayS);
    CombFeedback *combFeedback = initializeCombFeedback(sampleRate, delayS);

    allPass->combFeedforward = combFeedforward;
    allPass->combFeedback = combFeedback;

    return allPass;

}

int32_t allPassAppendSample(AllPass* filter, int32_t newSample){

	int32_t feedForwardOutput = combFeedforwardAppendSample(filter->combFeedforward, newSample);

	int32_t output = combFeedbackAppendSample(filter->combFeedback, feedForwardOutput);

    return output;

}


