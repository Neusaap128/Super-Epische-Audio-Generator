
#include "FilterUtility.h"

void shiftBuffer(SampleType *buffer, uint32_t bufferSize, SampleType newValue){

    for(uint32_t i = bufferSize-1; i > 0; i--){
        buffer[i] = buffer[i-1];
    }

    buffer[0] = newValue;

}
