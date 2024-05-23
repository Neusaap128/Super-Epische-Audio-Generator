#include "Bandpass.h"

BandPass* initializeBandPass(uint32_t sampleRate, uint32_t lowFrequencyCutoff, uint32_t highFrequencyCutoff){

    BandPass* filter = (BandPass*)malloc(sizeof(BandPass));

    // Calculate omega's
    float omega_low = 2.0f * M_PI * lowFrequencyCutoff / sampleRate;
    float omega_high = 2.0f * M_PI * highFrequencyCutoff / sampleRate;

    // Calculate coefficients
    filter -> b1 = omega_high * omega_high;
    filter -> b2 = -(omega_high * omega_high);
    filter -> a1 = 2.0f * 0.7f * omega_high;
    filter -> a2 = omega_high * omega_high;

    filter->inputSamples = initializeCircularBuffer(2);

    return filter;
}

int16_t BandPassAppendSample(BandPass* filter,  SampleType newSample) {
        int16_t output = (filter->b1 * newSample + filter->b2 * getValueInCircularBuffer(filter->inputSamples, 0)
                     - filter->a1 * getValueInCircularBuffer(filter->inputSamples, 1) - filter->a2 * getValueInCircularBuffer(filter->inputSamples, 0));
        putValueInCircularBuffer(filter->inputSamples, newSample);

        return output;
}