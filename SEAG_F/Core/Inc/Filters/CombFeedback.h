
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "FilterUtility.h"

#ifndef COMB_FEED_BACK_H
#define COMB_FEED_BACK_H

typedef struct{

    //y[n] = b_0x[n] - a_My[n-M]

    int M;
    int bufferSize;
    SampleType *outputSamples; // [0] is most recent output, [n-1] is n samples ago. so index is backwards
    float b0;
    float am;

    //no need to save input samples

}CombFeedback;

CombFeedback* initializeCombFeedback(uint32_t sampleRate, float delayS, float verzwakking, float am);
SampleType combFeedbackAppendSample(CombFeedback *filter, SampleType newSample);


#endif //COMB_FEED_BACK_H
