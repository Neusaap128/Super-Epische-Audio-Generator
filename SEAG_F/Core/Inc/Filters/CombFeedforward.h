
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "FilterUtility/FilterUtility.h"

#ifndef COMB_FEED_FORWARD_H
#define COMB_FEED_FORWARD_H

typedef struct{

    //y[n] = b_0x[n] + b_Mx[n-M]

    uint32_t offset;
    CircularBuffer *inputSamples; // [0] is most recent sample, [n-1] is n samples ago. so index is backwards

    float K;
    float a;

    // No need for saving output sample

}CombFeedforward;

CombFeedforward* initializeCombFeedforward(uint32_t sampleRate, float delayS, float b0, float am);
int16_t combFeedforwardAppendSample(CombFeedforward *filter, int16_t newSample);


#endif // COMB_FEED_FORWARD_H
