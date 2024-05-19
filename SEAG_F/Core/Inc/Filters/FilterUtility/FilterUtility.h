
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "CircularBuffer.h"

#define _USE_MATH_DEFINES
#include <math.h>

#ifndef FILTER_UTLITY_H
#define FILTER_UTILITY_H


void initSin();
float sinApproxLut(float x);


#endif //FILTER_UTILITY_H
