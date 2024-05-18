#include "Distortion.h"

Distortion* initializeDistortion(uint32_t threshold){
    Distortion *distortion= malloc(sizeof(Distortion));
    distortion->threshold = threshold;
    return distortion;
}

SampleType distortionAppendSample(Distortion* distortion, SampleType newSample){


	float in, out;


    // Normalize input to threshold level = 1.0
    in = (float)newSample/distortion->threshold;
    if (in < 0) {
        out = -1.0 + pow(2, in);
    } else if (in > 0) {
        out = 1.0 - pow(2, -in);
    } else {
        out = 0;
    }

	// Undo Normalization
	out = out * distortion->threshold*3;

	return out;


	/*
	float clipIn = 1*newSample/65356;
	float absClipIn = fabs(clipIn);
	float signClipIn = (clipIn >= 0.0f) ? 1.0f : -1.0f;

	float clipOut = 0;

	if(absClipIn < distortion->threshold){
		clipOut = 2.0f*clipIn;
	}else if(absClipIn >= distortion->threshold && absClipIn < (2.0f * distortion->threshold )){
		clipOut = signClipIn * (3.0f - (2.0f-3.0f*absClipIn)*(2.0f-3.0f*absClipIn))/3.0f;
	}else{
		clipOut = signClipIn;
	}


	return (SampleType)round(clipOut*65356);
    */

}
