
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "../Common.h"
#include "CombFeedforward.h"
#include "AllPass.h"


#ifndef REVERB_H
#define REVERB_H

typedef struct{

    int amountOfCombFilters;

    CombFeedforward** combFilters; //parallel comb filters

    int amountOfAllPassFilters;
    AllPass** allPassFilters;    

    //int16_t *inputSamples;


}Reverb;

Reverb* initializeReverb(uint32_t sampleRate, uint8_t amountOfCombFilters, float *delayCombS, uint8_t amountOfAllPassFilters, float *delayAllS);
SampleType reverbAppendSample(Reverb* reverb, SampleType newSample);


#endif //REVERB_H
