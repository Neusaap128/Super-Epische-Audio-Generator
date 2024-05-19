#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "FilterUtility/FilterUtility.h"
#include "FilterUtility/Oscillator.h"
#include "CombFeedback.h"
#include "AllPass.h"

#ifndef FLANGER_H
#define FLANGER_H

typedef struct{

    uint32_t delayFerquentie; // [/]
    uint32_t amplification;   // [/]

    AllPass* combFilter;
    Oscillator* oscillator;

}Flanger;

Flanger* initializeFlanger(uint32_t sampleRate, float fer, float amp);
SampleType flangerAppendSample(Flanger* flanger, SampleType newSample);


#endif //FLANGER_H
