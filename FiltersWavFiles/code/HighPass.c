
#include "HighPass.h"

HighPass* initializeHighPass(uint32_t sampleRate,float cutoff_frequency){

    HighPass* highpass = malloc(sizeof(HighPass));

    highpass->prevInput = 0;
    highpass->prevOutput = 0;

    highpass->exp = exp(-2*M_PI*cutoff_frequency/sampleRate );

    return highpass;
}

SampleType highPassAppendSample(HighPass* highpass, SampleType audioSample) {

	SampleType output = audioSample-highpass->prevInput + highpass->exp*highpass->prevOutput;

    highpass->prevOutput = output;
    highpass->prevInput = audioSample;

    return output;
}


