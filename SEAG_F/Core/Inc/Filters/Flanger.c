
#include "Flanger.h"

Flanger* initializeFlanger(uint32_t sampleRate, float fer, float amp){

    Flanger *flanger= malloc(sizeof(flanger));

    flanger->oscillator = initializeOscillator(sampleRate, fer, amp);
    flanger->combFilter = initializeAllPass(sampleRate, amp, 1.0f, 0.9f);

    return flanger;
}

SampleType flangerAppendSample(Flanger* flanger, SampleType newSample){
    
    uint32_t delay = oscillateAppendSample(flanger->oscillator);
    setAllPassOffset(flanger->combFilter, delay);

    SampleType result = allPassAppendSample(flanger->combFilter, newSample);

    return result;
}
