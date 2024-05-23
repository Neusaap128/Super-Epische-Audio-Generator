#include "main.h"

#define OUTPUT_FILE_NAME "Allpass.wav"

int main() {
    initSin();
    WavHeader header;
    int16_t* audioSamples;
    uint64_t numSamples;

    if(ReadWav("piano.wav", &header, &numSamples, &audioSamples) ==-1){
        return 1;
    }
    //-------------------- Converting Audio -------------------------

    int16_t* newAudioSamples = malloc(numSamples*sizeof(int16_t));

    float delayCombS[4] = {0.0297, 0.0371, 0.0411, 0.0437};
    float delayAllS[2] = {0.005, 0.0017};
	//Reverb* reverb = initializeReverb(header.sampleRate, 4, delayCombS, 2, delayAllS);
    //Flanger* flanger = initializeFlanger(header.sampleRate,  10.0f, 0.015f);
    //Distortion* distortion = initializeDistortion(1500);
    //CombFeedback* combFeedback = initializeCombFeedback(header.sampleRate, 0.5, 0.5, 0.8);
    //LowPass* lowpass = initializeLowPass(header.sampleRate, 2000);
    //HighPass* highpass = initializeHighPass(header.sampleRate, 500);
    //CombFeedforward* combfeedforward = initializeCombFeedforward(header.sampleRate, 0.2, 1,0.8);
    //Chorus* chorus= initializeChorus(header.sampleRate);
    //Oscillator* oscillator = initializeOscillator(header.sampleRate, 440, 5000);
    AllPass* allpass = initializeAllPass(header.sampleRate, delayAllS[1], 1, 0.8f);

    for (int i = 0; i < numSamples; i++){
        //newAudioSamples[i] =  reverbAppendSample(reverb, audioSamples[i]);             //reverb
        //newAudioSamples[i] =  flangerAppendSample(flanger, audioSamples[i]);           //flanger
        //newAudioSamples[i] =  distortionAppendSample(distortion, audioSamples[i]);     //distortion
        //newAudioSamples[i] =  combFeedbackAppendSample(combFeedback, audioSamples[i]); //combFeedback
        //newAudioSamples[i] =  lowPassAppendSample(lowpass, audioSamples[i]);           //lowpass
        //newAudioSamples[i] =  lowPassAppendSample(highpass, audioSamples[i]);          //highpass
        //newAudioSamples[i] =  combFeedforwardAppendSample(filter, audioSamples[i]);    //comfeedforward
        //newAudioSamples[i] =  chorusAppendSample(chorus, audioSamples[i]);             //chorus    
        //newAudioSamples[i] = oscillateAppendSample(oscillator);                        //oscillator
        newAudioSamples[i] = allPassAppendSample(allpass, audioSamples[i]);             //allpass
      
    }

    //--------------------- Writing output --------------------------

    if(WriteWav(OUTPUT_FILE_NAME, &header, numSamples, newAudioSamples) == -1){
        return 1;
    }
    return 0;
}

