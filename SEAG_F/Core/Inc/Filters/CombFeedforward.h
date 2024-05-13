
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "../Common.h"
#include "FilterUtility.h"

#ifndef COMB_FEED_FORWARD_H
#define COMB_FEED_FORWARD_H

typedef struct{

    //y[n] = b_0x[n] + b_Mx[n-M]

    int M;
    SampleType *inputSamples; // [0] is most recent sample, [n-1] is n samples ago. so index is backwards

    // No need for saving output sample

}CombFeedforward;

CombFeedforward* initializeCombFeedforward(uint32_t sampleRate, float delayS);
SampleType combFeedforwardAppendSample(CombFeedforward *filter, SampleType newSample);


#endif // COMB_FEED_FORWARD_H
