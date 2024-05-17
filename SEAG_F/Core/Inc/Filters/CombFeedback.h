
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "FilterUtility/FilterUtility.h"

#ifndef COMB_FEED_BACK_H
#define COMB_FEED_BACK_H

typedef struct{

    //y[n] = b_0x[n] - a_My[n-M]

    uint32_t offset;
    CircularBuffer *outputSamples;

    //Filter properties
    float K, a;


}CombFeedback;

CombFeedback* initializeCombFeedback(uint32_t sampleRate, float delayS, float verzwakking, float am);
SampleType combFeedbackAppendSample(CombFeedback *filter, SampleType newSample);


#endif //COMB_FEED_BACK_H
