
#include "CircularBuffer.h"

CircularBuffer* initializeCircularBuffer(uint32_t bufferSize){

    CircularBuffer *buffer = malloc(sizeof(CircularBuffer));

    buffer->bufferSize = bufferSize;
    buffer->buffer = calloc(bufferSize, sizeof(int16_t));
    buffer->writeIndex = 0;

    return buffer;

}

void putValueInCircularBuffer(CircularBuffer* buffer, int16_t value){

    buffer->buffer[buffer->writeIndex] = value;
    buffer->writeIndex = (buffer->writeIndex+1) % buffer->bufferSize;

}

SampleType getValueInCircularBuffer(CircularBuffer* buffer, uint32_t offset){

    SampleType output = buffer->buffer[ (buffer->writeIndex + offset ) % buffer->bufferSize ];
    return output;

}



