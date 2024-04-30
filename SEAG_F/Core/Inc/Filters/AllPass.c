
#include "AllPass.h"

AllPass* initializeAllPass(uint32_t sampleRate, float delayS){

    AllPass* allPass = malloc(sizeof(AllPass));

    CombFeedforward *combFeedforward = initializeCombFeedforward(sampleRate, delayS);
    CombFeedback *combFeedback = initializeCombFeedback(sampleRate, delayS);

    allPass->combFeedforward = combFeedforward;
    allPass->combFeedback = combFeedback;

    return allPass;

}

uint16_t allPassAppendSample(AllPass* filter, uint16_t newSample){

	uint16_t feedForwardOutput = combFeedforwardAppendSample(filter->combFeedforward, newSample);

	uint16_t output = combFeedbackAppendSample(filter->combFeedback, feedForwardOutput);

    return output;

}


