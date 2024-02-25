/*
 * Vector2.h
 *
 *  Created on: Feb 25, 2024
 *      Author: Joran
 */

#ifndef INC_VECTOR2_H_
#define INC_VECTOR2_H_

#include <math.h>

typedef struct{
	float x, y;
}Vector2;

float Magnitude(Vector2* vec);
float SqrMagnitude(Vector2* vec);

#endif /* INC_VECTOR2_H_ */
