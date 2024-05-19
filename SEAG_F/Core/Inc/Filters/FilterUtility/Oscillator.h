#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

#include "FilterUtility.h"

#ifndef OSCIL_H
#define OSCIL_H

typedef struct{

   uint32_t freq;
   uint32_t amp;

   uint32_t i;

}Oscillator;

Oscillator* initializeOscillator(uint32_t sampleRate, float frequency, float amplitude);
uint32_t oscillateAppendSample(Oscillator* osc);

#endif
