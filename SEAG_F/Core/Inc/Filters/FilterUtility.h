
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "../Common.h"

#ifndef FILTER_UTLITY_H
#define FILTER_UTILITY_H

void shiftBuffer(SampleType *buffer, uint32_t bufferSize, SampleType newValue);

#endif //FILTER_UTILITY_H
