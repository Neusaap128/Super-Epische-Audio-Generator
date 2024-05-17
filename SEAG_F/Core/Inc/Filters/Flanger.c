
#include "Flanger.h"

Flanger* initializeFlanger(uint32_t sampleRate, float fer, float amp){
    Flanger *flanger= malloc(sizeof(flanger));
    flanger->delayFerquentie = sampleRate/fer; // [(1/s)/(1/s)]
    flanger->amplification = amp*sampleRate; // [s*1/s]

    flanger->i = 0;
    
    flanger->combFilter = initializeCombFeedback(sampleRate, amp, 1, 0.8);
    return flanger;
}

SampleType flangerAppendSample(Flanger* flanger, SampleType newSample){
    
    int delay = (flanger->amplification/2)*(1.0-cos(2*PI*flanger->delayFerquentie*flanger->i) ) + 1;

    flanger->combFilter->offset = delay;

    flanger->i++;
    SampleType result = combFeedbackAppendSample(flanger->combFilter, newSample);

    return result;
}

