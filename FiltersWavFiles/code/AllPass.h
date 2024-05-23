
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "CombFeedforward.h"
#include "CombFeedback.h"

#ifndef ALL_PASS_H
#define ALL_PASS_H

typedef struct{

    CombFeedforward* combFeedforward;
    CombFeedback* combFeedback;

}AllPass;

/*
 * gaat alles wat nodig is voor de allpas filter gaan opslagen in de struct
 */
AllPass* initializeAllPass(uint32_t sampleRate, float delayS, float b0, float am);

/*
 * deze gaat uit reken voor 1 sampel wat de output moet zijn en dit in format terugsturen dat codec werkt
 */
SampleType  allPassAppendSample(AllPass* filter, SampleType  newSample);

/*
 * gaat op offset zetten van waar moet werken
 */
void setAllPassOffset(AllPass* allPass, uint32_t offset);

/*
 * gaat de parameters die hij gebruikt gaan in stellen, bij comback en comforwaard
 */
void setAllPassLevel(AllPass* allPass, float a);


#endif //ALL_PASS_H
