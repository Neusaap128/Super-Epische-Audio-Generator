
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "../DSP/DSP.h"
#include "CombFeedforward.h"
#include "CombFeedback.h"

#ifndef ALL_PASS_H
#define ALL_PASS_H

typedef struct{

    CombFeedforward* combFeedforward;
    CombFeedback* combFeedback;

    //All relevant information gets stored in the comb's

}AllPass;


AllPass* initializeAllPass(uint32_t sampleRate, float delayS);
int32_t allPassAppendSample(AllPass* filter, int32_t newSample);

#endif //ALL_PASS_H
