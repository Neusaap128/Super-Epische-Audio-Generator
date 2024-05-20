
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "FilterUtility/FilterUtility.h"

#ifndef COMB_FEED_FORWARD_H
#define COMB_FEED_FORWARD_H

typedef struct{

    //y[n] = b_0x[n] + b_Mx[n-M]

    uint32_t offset;
    CircularBuffer *inputSamples;

    //filter properties
    float K, a;


}CombFeedforward;

CombFeedforward* initializeCombFeedforward(uint32_t sampleRate, float delayS, float b0, float am);
int16_t combFeedforwardAppendSample(CombFeedforward *filter, int16_t newSample);
void setCombFeedforwardLevel(CombFeedforward *combfeedback, float a);

#endif // COMB_FEED_FORWARD_H
