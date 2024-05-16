
#ifndef INC_FLANGER_H
#define INC_FLANGER_H

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
//#define USE_MATH_DEFINES
#include <math.h>

#include "FilterUtility.h"
#include "CombFeedback.h"

#define PI 3.141592654

typedef struct{

    int i;
    int delayFerquentie; // [/]
    int amplification;   // [/]

    CombFeedback* combFilter;


}Flanger;

Flanger* initializeFlanger(uint32_t sampleRate, float fer, float amp);
SampleType flangerAppendSample(Flanger* flanger, SampleType newSample);


#endif // INC_FLANGER_H

