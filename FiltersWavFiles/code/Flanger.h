#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "FilterUtility/FilterUtility.h"
#include "FilterUtility/Oscillator.h"
#include "CombFeedforward.h"

#ifndef FLANGER_H
#define FLANGER_H

typedef struct{

    uint32_t delayFerquentie; // [/]
    uint32_t amplification;   // [/]

    CombFeedforward* combFilter;
    Oscillator* oscillator;

}Flanger;

Flanger* initializeFlanger(uint32_t sampleRate, float fer, float amp);
SampleType flangerAppendSample(Flanger* flanger, SampleType newSample);
void setFlangerLevel(Flanger* flanger, float a);


#endif //FLANGER_H
