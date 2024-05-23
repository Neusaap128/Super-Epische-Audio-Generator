
#include "Wav.h"


int ReadWav(const char* fileName, WavHeader* header, uint64_t *numSamples, int16_t **audioSamples){

    FILE* fileIn;

    // Open input wave file for reading
    fileIn = fopen(fileName, "rb");
    if (fileIn == NULL) {
        fprintf(stderr, "Error: Unable to open input file.\n");
        return -1;
    }

    // Read the WAV header
    fread(header, sizeof(WavHeader), 1, fileIn);

    // Calculate the number of audio samples
    *numSamples = header->subchunk2Size / (header->numChannels * (header->bitsPerSample / 8));
    
    // Allocate memory for audio data
    (*audioSamples) = (int16_t*)malloc((*numSamples)*sizeof(int16_t));
    if ((*audioSamples) == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for audio data.\n");
        fclose(fileIn);
        return -1;
    }

    // Read audio data
    fread((*audioSamples), sizeof(int16_t), (*numSamples), fileIn);

    // Close input file
    fclose(fileIn);

    return 1;

}

int WriteWav(const char* fileName, WavHeader* header, uint64_t numSamples, int16_t *audioSamples){


    // Open output wave file for writing
    FILE *fileOut = fopen(fileName, "wb");
    if (fileOut == NULL) {
        fprintf(stderr, "Error: Unable to open output file.\n");
        free(audioSamples);
        return 1;
    }


    // Write the WAV header to the output file
    fwrite(header, sizeof(WavHeader), 1, fileOut);


    // Write audio data to the output file
    fwrite(audioSamples, sizeof(int16_t), numSamples, fileOut);

    printf("Wrote output file\n");

    // Close output file
    fclose(fileOut);


    return 1;

}



