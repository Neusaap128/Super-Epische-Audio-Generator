/*
 * Vector2.c
 *
 *  Created on: Feb 25, 2024
 *      Author: Joran
 */

#include "Vector2.h"

float Magnitude(Vector2* vec){
	return sqrt(SqrMagnitude(vec));
}

float SqrMagnitude(Vector2* vec){
	return vec->x*vec->x + vec->y*vec->y;
}


