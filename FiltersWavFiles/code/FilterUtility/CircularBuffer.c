
#include "CircularBuffer.h"

CircularBuffer* initializeCircularBuffer(uint32_t bufferSize){

    CircularBuffer *buffer = malloc(sizeof(CircularBuffer));

    buffer->bufferSize = bufferSize;
    buffer->buffer = calloc(bufferSize, sizeof(int16_t)); 	//zet alle waardens op 0 voor je buffer gebruikt
    buffer->writeIndex = 0;

    return buffer;

}

void putValueInCircularBuffer(CircularBuffer* buffer, int16_t value){

    buffer->buffer[buffer->writeIndex] = value;
    buffer->writeIndex = (buffer->writeIndex+1) % buffer->bufferSize;

}

SampleType getValueInCircularBuffer(CircularBuffer* buffer, uint32_t offset){

    SampleType output = buffer->buffer[ (buffer->writeIndex + offset ) % buffer->bufferSize ]; //gaat op gevraagde index waarde halen als het groter is dan de buffer grote delen door het vorige
    return output;

}



