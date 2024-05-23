
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "LowPass.h"

#include "FilterUtility/FilterUtility.h"

#ifndef COMB_FEED_BACK_H
#define COMB_FEED_BACK_H

typedef struct{

    //y[n] = b_0x[n] - a_My[n-M]

    uint32_t offset;
    CircularBuffer *outputSamples;

    LowPass* lowPass;

    //Filter properties
    float K, a;


}CombFeedback;
/*
 * zet alle waardens in de struct en sturen de struct terug naar buiten zodat die met de filter mee gegeven kan worden
 */
CombFeedback* initializeCombFeedback(uint32_t sampleRate, float delayS, float verzwakking, float am);

/*
 * gaat in het intestelde bit gaan uitreken wat de volgende waarde moet zijn en dit naar buiten sturen
 * y[n] = b_0x[n] - a_My[n-M] -> de functie dat die uitrekend

 */
SampleType combFeedbackAppendSample(CombFeedback *filter, SampleType newSample);
void setCombFeedbackLevel(CombFeedback *combfeedback, float a);


#endif //COMB_FEED_BACK_H
