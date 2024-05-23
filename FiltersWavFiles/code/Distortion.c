
#include "Distortion.h"

Distortion* initializeDistortion(int threshold){
    Distortion *distortion= malloc(sizeof(Distortion));
    distortion->threshold = threshold;
    return distortion;
}

SampleType distortionAppendSample(Distortion* distortion, SampleType newSample){
    float in, out, in_fabs;
    uint8_t negatief =1;

    // Normalize input to threshold level = 1.0
    in = (float)newSample/distortion->threshold;
    in_fabs = fabs(in);
    if (in_fabs == in){
        negatief = 0;
    }
    if (in_fabs<1.0f/3) {
        out = 1.5*in_fabs;
    } else if (in_fabs >= 1.0f/3 && in_fabs < 2.0f/3) {
        out = (float)(3- (2-(3*in_fabs))*(2-(3*in_fabs)))/3;
    } 
    else{
        out = 1;
    }
    if(negatief){
        out *= -1;
    }

    out = out * distortion->threshold;
    return (SampleType)out;

}

void setDistortionLevel(Distortion* dist, float a){

	if(a > 1.0f) a = 1.0f;
	if(a < 0.0f) a = 0.0f;

	dist->threshold = 300 + a*(3000-300);

}
