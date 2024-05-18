#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

#include "../Common.h"

typedef struct{

	uint32_t threshold;

}Distortion;

Distortion* initializeDistortion(uint32_t threshold);
SampleType distortionAppendSample(Distortion* distortion, SampleType newSample);


