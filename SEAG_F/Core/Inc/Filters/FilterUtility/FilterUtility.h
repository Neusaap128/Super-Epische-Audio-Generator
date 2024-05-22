
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "CircularBuffer.h"

#define _USE_MATH_DEFINES
#include <math.h>

#ifndef FILTER_UTLITY_H
#define FILTER_UTILITY_H

/*
 * berekend een sinus bij het initaliseren zodat dit niet meer moet gebeuren als deze eenmaal nodig is
 */
void initSin();

/*
 * gaat de gevraagde waarde van sinus op halen deze waarde retunt die als float
 * het gaat voor de waarde te benaderen interpoler tussen twee opeenvolgende waarden
 * de return waarde is tusssen 1 en -1
 */
float sinApproxLut(float x);


#endif //FILTER_UTILITY_H
