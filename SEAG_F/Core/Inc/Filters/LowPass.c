#include "LowPass.h"
#include <math.h>

LowPassFilter* InitializeLPFilter(float cutoffFreq, uint32_t samplingFreq) {
    float time = 1.0 / samplingFreq;
    float RC = 1.0 / (2.0 * 3.14 * cutoffFreq); //2 * pi * f M_Pi ??
    float alpha = time / (RC + time);

    LowPassFilter *filter = malloc(sizeof(LowPassFilter));

    //coeficients
    filter->a1 = -alpha;
    filter->b0 = alpha;
    filter->b1 = alpha;

    filter->prevInput = 0.0;
    filter->prevOutput = 0.0;

    return filter;
}

float LPFilter(LowPassFilter *filter, float input) {

    float output = filter->b0 * input + filter->b1 * filter->prevInput + filter->a1 * filter->prevOutput;

    filter->prevInput = input;
    filter->prevOutput = output;

    return output;

}
