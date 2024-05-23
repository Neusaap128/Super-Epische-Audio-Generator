#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


#define _USE_MATH_DEFINES
#include <math.h>
typedef int16_t SampleType;	//datatype van 1 audio sample
typedef struct{
	//y[n] = x[n] - x[n-1] + e^(-omega*T)*y[n-1]

    float exp;

    SampleType prevInput;  // previous input
    SampleType prevOutput;  // previous output


} HighPass;

HighPass* initializeHighPass(uint32_t sampleRate,float cutoff_frequency);
SampleType highPassAppendSample(HighPass* highpass, SampleType audioSamples);
