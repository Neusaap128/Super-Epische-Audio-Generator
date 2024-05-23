#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

#ifndef LOW_PASS_H
#define LOW_PASS_H
typedef int16_t SampleType;	//datatype van 1 audio sample
typedef struct {

    float a;

    SampleType prevOutput;
    SampleType prevInput;

} LowPass;

LowPass* initializeLowPass(uint32_t samplingFreq, uint32_t freq);
SampleType lowPassAppendSample(LowPass *filter, SampleType input);

#endif //LOW_PASS_H
