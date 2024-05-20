
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

}AllPass;


AllPass* initializeAllPass(uint32_t sampleRate, float delayS, float b0, float am);
SampleType  allPassAppendSample(AllPass* filter, SampleType  newSample);
void setAllPassOffset(AllPass* allPass, uint32_t offset);
void setAllPassLevel(AllPass* allPass, float a);


#endif //ALL_PASS_H
