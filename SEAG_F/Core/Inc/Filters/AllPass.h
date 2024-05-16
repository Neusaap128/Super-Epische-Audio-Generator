
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "CombFeedforward.h"
#include "CombFeedback.h"

#ifndef ALL_PASS_H
#define ALL_PASS_H

typedef struct{


    CombFeedforward* combFeedforward;
    CombFeedback* combFeedback;

    //All relevant information gets stored in the comb's

}AllPass;


AllPass* initializeAllPass(uint32_t sampleRate, float delayS, float b0, float am);
SampleType  allPassAppendSample(AllPass* filter, SampleType  newSample);

#endif //ALL_PASS_H
