//gaat op een efficente manier er voor zorgen dat er data uitgehaald/ingestoken worden
#include <stdint.h>
#include <stdlib.h>

#ifndef INC_CIRCULAR_BUFFER_H
#define INC_CIRCULAR_BUFFER_H
typedef int16_t SampleType;
//basis zaken die we nodig hebben voor het maken van een buffer
typedef struct{

    SampleType *buffer;
    uint32_t writeIndex;
    uint32_t bufferSize;

}CircularBuffer;

/*
 * gaat de struct vullen met waarden en zorgen dat het kan gebruikt worden
 * zet ook van het begin nullen in de buffer
 */
CircularBuffer* initializeCircularBuffer(uint32_t bufferSize);
/*
 * gaat een waarde in de buffer steken op de plek van de schrijf index
 * verhoogt de schrijf buffer met 1 --> detecteerd dat het niet groter word dan max waarde
 */
void putValueInCircularBuffer(CircularBuffer* buffer, int16_t value);

/*
 * geeft waarde terug op de plek van de schrijf index, dit is de langst geleden sample
 * als een meer recentere waarde nodig is, kan offset gebruikt worden.
 */
SampleType getValueInCircularBuffer(CircularBuffer* buffer, uint32_t offset);


#endif //CIRCULAR_BUFFER_H
