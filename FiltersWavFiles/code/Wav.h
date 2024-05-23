
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    char chunkID[4];
    uint32_t chunkSize;
    char format[4];
    char subchunk1ID[4];
    uint32_t subchunk1Size;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    char subchunk2ID[4];
    uint32_t subchunk2Size;
}WavHeader;


int ReadWav(const char* fileName, WavHeader* header, uint64_t *numSamples, int16_t **audioSamples);

int WriteWav(const char* fileName, WavHeader* header, uint64_t numSamples, int16_t *audioSamples);

