
#include "Oscillator.h"

Oscillator* initializeOscillator(uint32_t sampleRate, float frequency, float amplitude){

    Oscillator* oscillator = malloc(sizeof(Oscillator));

    oscillator->freq = sampleRate/frequency; // [(1/s)/(1/s)]
    oscillator->amp = amplitude*sampleRate;  // [s*1/s]

    oscillator->i =0;

    return oscillator;
}

uint32_t oscillateAppendSample(Oscillator* osc){

    float sinuscall = 2*M_PI*osc->i/osc->freq;	//gaat de value dat naar sins gaat bereken
    float output = osc->amp/2*(1.0f-(float)sinApproxLut(sinuscall)); //delen omdat het tussen de max waarden komt te zitte
    osc->i++;
    // zorgt er voor dat er geen overflow kan zijn
    if(osc->i >= osc->freq){
    	osc->i = 0;
    }

    return output;
}
