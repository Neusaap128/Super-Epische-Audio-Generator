#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "../Common.h"

#define _USE_MATH_DEFINES
#include <math.h>

typedef struct{
	//y[n] = x[n] - x[n-1] + e^(-omega*T)*y[n-1]

    float exp;

    SampleType prevInput;  // previous input
    SampleType prevOutput;  // previous output


} HighPass;

HighPass* initializeHighPass(uint32_t sampleRate,float cutoff_frequency);
SampleType highPassAppendSample(HighPass* highpass, SampleType audioSamples);
