
#include "LowPass.h"

LowPass* initializeLowPass(uint32_t samplingFreq, uint32_t freq) {

    LowPass *filter =malloc(sizeof(LowPass));

    filter->a = exp(-2*M_PI*(float)freq/samplingFreq);
    printf("sampel: %d, feq %d, result %f\n", samplingFreq,freq,filter->a);

    filter->prevInput = 0;
    filter->prevOutput = 0;

    return filter;
}

SampleType lowPassAppendSample(LowPass *filter, SampleType input) {
    
	SampleType output = (1.0f-filter->a)*filter->prevInput + filter->a*filter->prevOutput;

    filter->prevInput = input;
    filter->prevOutput = output;

    return output;

}
