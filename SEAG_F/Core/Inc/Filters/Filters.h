/*
 * Filters.h
 *
 *  Created on: May 13, 2024
 *      Author: Joran
 */

#ifndef INC_FILTERS_FILTERS_H_
#define INC_FILTERS_FILTERS_H_

#include <stdint.h>
#include "../Common.h"
#include "Reverb.h"
#include "CombFeedback.h"
#include "Flanger.h"
#include "Distortion.h"
#include "Chorus.h"

#include "Filter.h"

typedef struct{

	uint8_t enabledFilters;

	Filter* filterInstances[AMOUNT_OF_FILTERS];

}Filters;


Filters* initializeFilters(uint32_t sampleRate);
SampleType appendSample(Filters* filters, SampleType newSample);


#endif /* INC_FILTERS_FILTERS_H_ */
