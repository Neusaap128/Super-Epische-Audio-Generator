#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include "Wav.h"
#include "Reverb.h"
#include "Bandpass.h"
#include "Flanger.h"
#include "Distortion.h"
#include "LowPass.h"
#include "HighPass.h"
#include "FilterUtility/Oscillator.h"
#include "Chorus.h"
#include "FilterUtility/CircularBuffer.h"
#include "FilterUtility/FilterUtility.h"

typedef int16_t SampleType;	//datatype van 1 audio sample