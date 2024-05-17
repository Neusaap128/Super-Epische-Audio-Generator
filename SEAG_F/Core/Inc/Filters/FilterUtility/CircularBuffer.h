
#include <stdint.h>
#include <stdlib.h>

#include "../../Common.h"

#ifndef INC_CIRCULAR_BUFFER_H
#define INC_CIRCULAR_BUFFER_H

typedef struct{

    SampleType *buffer;
    uint32_t writeIndex;
    uint32_t bufferSize;

}CircularBuffer;

CircularBuffer* initializeCircularBuffer(uint32_t bufferSize);

void putValueInCircularBuffer(CircularBuffer* buffer, int16_t value);
SampleType getValueInCircularBuffer(CircularBuffer* buffer, uint32_t offset);


#endif //CIRCULAR_BUFFER_H
