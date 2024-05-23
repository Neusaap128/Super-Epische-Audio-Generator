
#include "Flanger.h"

Flanger* initializeFlanger(uint32_t sampleRate, float fer, float amp){

    Flanger *flanger= malloc(sizeof(flanger));

    flanger->oscillator = initializeOscillator(sampleRate, fer, amp);
    flanger->combFilter = initializeCombFeedforward(sampleRate, amp, 1.0f, 0.90f);

    return flanger;
}

SampleType flangerAppendSample(Flanger* flanger, SampleType newSample){
    
    uint32_t delay = oscillateAppendSample(flanger->oscillator);

    flanger->combFilter->offset = delay;

    SampleType result = combFeedforwardAppendSample(flanger->combFilter, newSample);

    return result;

}

void setFlangerLevel(Flanger* flanger, float a){

	setCombFeedforwardLevel(flanger->combFilter, a);

}
