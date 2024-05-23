
#ifndef INC_REVERB_H
#define INC_REVERB_H

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "CombFeedforward.h"
#include "AllPass.h"

typedef struct{

    int amountOfCombFilters;
    CombFeedback** combFilters; //parallel comb filters

    int amountOfAllPassFilters;
    AllPass** allPassFilters; // Serial all pass filters

}Reverb;

Reverb* initializeReverb(uint32_t sampleRate, uint8_t amountOfCombFilters, float *delayCombS, uint8_t amountOfAllPassFilters, float *delayAllS);
SampleType reverbAppendSample(Reverb* reverb, SampleType newSample);
void setReverbLevel(Reverb* reverb, float a);

#endif //INC_REVERB_H

