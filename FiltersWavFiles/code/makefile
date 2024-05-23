

all: main.c
	mkdir -p builds 
	gcc -g -c FilterUtility/Oscillator.c -o builds/Oscillator.o
	gcc -g -c FilterUtility/CircularBuffer.c -o builds/CircularBuffer.o
	gcc -g -c FilterUtility/FilterUtility.c -o builds/FilterUtility.o
	gcc -g -c Bandpass.c -o builds/Bandpass.o
	gcc -g -c CombFeedforward.c -o builds/CombFeedforward.o
	gcc -g -c CombFeedback.c -o builds/CombFeedback.o
	gcc -g -c AllPass.c -o builds/AllPass.o
	gcc -g -c Reverb.c -o builds/Reverb.o
	gcc -g -c Wav.c -o builds/Wav.o
	gcc -g -c Flanger.c -o builds/Flanger.o
	gcc -g -c Distortion.c -o builds/Distortion.o
	gcc -g -c LowPass.c -o builds/LowPass.o
	gcc -g -c HighPass.c -o builds/HighPass.o
	gcc -g -c Chorus.c -o builds/Chorus.o
	gcc -g -c main.c -o builds/main.o
	gcc builds/Bandpass.o builds/CircularBuffer.o builds/Chorus.o builds/CombFeedback.o builds/Oscillator.o builds/FilterUtility.o builds/HighPass.o builds/AllPass.o builds/Reverb.o builds/CombFeedforward.o builds/Wav.o builds/Flanger.o builds/Distortion.o builds/LowPass.o builds/main.o -o  main -lm 

clean:
	-rm -f all;