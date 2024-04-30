
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "FilterUtility.h"

#ifndef COMB_FEED_FORWARD_H
#define COMB_FEED_FORWARD_H

typedef struct{

    //y[n] = b_0x[n] + b_Mx[n-M]

    int M;
    int16_t *inputSamples; // [0] is most recent sample, [n-1] is n samples ago. so index is backwards

    // No need for saving output sample

}CombFeedforward;

CombFeedforward* initializeCombFeedforward(uint32_t sampleRate, float delayS);
int16_t combFeedforwardAppendSample(CombFeedforward *filter, int16_t newSample);


#endif // COMB_FEED_FORWARD_H
