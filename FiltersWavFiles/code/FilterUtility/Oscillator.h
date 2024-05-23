#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

#include "FilterUtility.h"

#ifndef OSCIL_H
#define OSCIL_H

//gaat aan de hand van een frequentie en amplitude een oscillator weergeven
typedef struct{

   uint32_t freq;
   uint32_t amp;

   uint32_t i;

}Oscillator;

/*
 * gaat de struct op vullen met de gekozen frequentie en amplitude en zet de start i op nul
 */
Oscillator* initializeOscillator(uint32_t sampleRate, float frequency, float amplitude);

/*
 * geeft de huidige waarde van de oscilatie terug. i wordt geïcrementeerd, zodat de oscillatie opschuift
 * het zorgt ook voor dat er geen overflow kan zijn van de i
 */
uint32_t oscillateAppendSample(Oscillator* osc);

#endif
