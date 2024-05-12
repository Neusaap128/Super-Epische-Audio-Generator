
#include "FilterUtility.h"

void shiftBuffer(int32_t *buffer, uint32_t bufferSize, int32_t newValue){

    for(uint32_t i = bufferSize-1; i > 0; i--){
        buffer[i] = buffer[i-1];
    }

    buffer[0] = newValue;

}
