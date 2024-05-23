#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include "FilterUtility/Oscillator.h"
#define SampleType int16_t

typedef struct{
    float b1, b2; // Coefficients numerator
    float a1, a2;     // Coefficients denumerator
    CircularBuffer *inputSamples;
}BandPass;

BandPass* initializeBandPass(uint32_t sampleRate, uint32_t lowFrequencyCutoff, uint32_t highFrequencyCutoff);
int16_t BandPassAppendSample(BandPass* filter,  SampleType newSample);

