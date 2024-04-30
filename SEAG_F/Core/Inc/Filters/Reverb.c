
#include "Reverb.h"

//Order delayS smallest to largest
Reverb* initializeReverb(uint32_t sampleRate, uint8_t amountOfCombFilters, float *delayCombS, uint8_t amountOfAllPassFilters, float *delayAllS){

	Reverb *reverb = malloc(sizeof(Reverb));


    //Comb
    reverb->amountOfCombFilters = amountOfCombFilters;

    reverb->combFilters = malloc(reverb->amountOfCombFilters*sizeof(CombFeedforward));

    for(int i = 0; i < reverb->amountOfCombFilters; i++){
        reverb->combFilters[i] = initializeCombFeedforward(sampleRate, delayCombS[i]);
    }
    
    
    //AllPass
    reverb->amountOfAllPassFilters = amountOfAllPassFilters;
    reverb->allPassFilters = malloc(reverb->amountOfAllPassFilters*sizeof(AllPass));

    for(int i = 0; i < reverb->amountOfAllPassFilters; i++){
        reverb->allPassFilters[i] = initializeAllPass(sampleRate, delayAllS[i]);
    }

    return reverb;

}

int16_t reverbAppendSample(Reverb* reverb, int16_t newSample){

    int16_t combSumOutput = 0;

    for(int i = 0; i < reverb->amountOfCombFilters; i++){
        combSumOutput += combFeedforwardAppendSample(reverb->combFilters[i], newSample);
    }


    int16_t previousAllPassOutput = combSumOutput;

    for (int i = 0; i < reverb->amountOfAllPassFilters; i++){
        previousAllPassOutput = allPassAppendSample(reverb->allPassFilters[i], previousAllPassOutput);
    }
    
    return previousAllPassOutput;

}


