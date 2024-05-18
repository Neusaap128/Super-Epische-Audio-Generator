#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "../Common.h"

#ifndef LOW_PASS
#define LOW_PASS

typedef struct {
    float a1;  
    float b0;  
    float b1;  
    float prevInput;  
    float prevOutput;
} LowPassFilter;

LowPassFilter* InitializeLPFilter(float cutoffFreq, uint32_t samplingFreq);
float LPFilter(LowPassFilter *filter, float input);

#endif
