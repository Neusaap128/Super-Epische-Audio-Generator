//gaat op een efficente manier er voor zorgen dat er data uitgehaald/ingestoken worden
#include <stdint.h>
#include <stdlib.h>

#include "../../Common.h"

#ifndef INC_CIRCULAR_BUFFER_H
#define INC_CIRCULAR_BUFFER_H
//basis zaken die we nodig hebben voor het maken van een buffer
typedef struct{

    SampleType *buffer;
    uint32_t writeIndex;
    uint32_t bufferSize;

}CircularBuffer;
/*
 * gaat de struct vullen met waarders en zorgen dat het kan gebruikt worden
 * zet ook van het begin nullen in de buffer
 */
CircularBuffer* initializeCircularBuffer(uint32_t bufferSize);
/*
 * gaat een waarde in de buffer steken op de plek van de schrijf index
 * verhoogt de schrijf buffer met 1 --> detecteerd dat het niet groter word dan max waarde
 */
void putValueInCircularBuffer(CircularBuffer* buffer, int16_t value);

/*
 * geeft een waarde terug afhankelijk van het aantal sampels dat je neemt
 * geeft plaats mee waar je data wilt uit halen
 */
SampleType getValueInCircularBuffer(CircularBuffer* buffer, uint32_t offset);


#endif //CIRCULAR_BUFFER_H
