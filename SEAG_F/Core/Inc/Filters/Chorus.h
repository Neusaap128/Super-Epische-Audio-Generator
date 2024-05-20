#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "LowPass.h"
#include "AllPass.h"

#define _USE_MATH_DEFINES
#include <math.h>

#ifndef CHORUS_H
#define CHORUS_H

typedef struct {
    
    uint16_t maxDelay;
    LowPass* delayLowPass;
    
    float* previousDelays;
    float a;

    uint8_t amountOfFeedforwardFilters;
    CombFeedforward** combFeedforwardFilters;


} Chorus;

Chorus* initializeChorus(uint32_t sampleRate);
SampleType chorusAppendSample(Chorus *filter, SampleType input);
void setChorusLevel(Chorus* filter, float a);

#endif //CHORUS_H
