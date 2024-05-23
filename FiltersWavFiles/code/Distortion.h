

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>


#ifndef DISTORTION_H
#define DISTORTION_H
typedef int16_t SampleType;	//datatype van 1 audio sample
typedef struct{

    uint16_t threshold;

}Distortion;

Distortion* initializeDistortion(int threshold);
SampleType distortionAppendSample(Distortion* distortion, SampleType newSample);
void setDistortionLevel(Distortion* dist, float a);


#endif //DISTORTION_H

