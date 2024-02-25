/*
 * DFT.c
 *
 *  Created on: Feb 25, 2024
 *      Author: Joran
 */

#include "DFT.h"

Vector2* DFT(int N, float* x){

	Vector2* freqDomain = (Vector2*)malloc(N*sizeof(Vector2));

	for (int j = 0; j < N; j++){

		freqDomain[j].x = 0.0f;
		freqDomain[j].y = 0.0f;

		for (int i = 0; i < N; i++){

			freqDomain[j].x += x[i]*cos(2*M_PI/N*j*i);
			freqDomain[j].y -= x[i]*sin(2*M_PI/N*j*i);

		}

	}

	return freqDomain;
}
