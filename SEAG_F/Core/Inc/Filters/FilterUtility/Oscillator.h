#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

#include "FilterUtility.h"

#ifndef OSCIL_H
#define OSCIL_H

//gaat aan de hand van een freq en amp gaat het maximale vertraging weer geven
typedef struct{

   uint32_t freq;
   uint32_t amp;

   uint32_t i;

}Oscillator;
/*
 * gaat de struct op vullen met de gekozen ferqentie en amplitude en zet de start i op nul
 */
Oscillator* initializeOscillator(uint32_t sampleRate, float frequency, float amplitude);

/*
 * gaat berekren hoeveel vertraging er gaat zijn deze waarde is tussen 0 en de amplituden
 * het zorgt ook voor dat er geen overflow kan zijn van de i
 */
uint32_t oscillateAppendSample(Oscillator* osc);

#endif
