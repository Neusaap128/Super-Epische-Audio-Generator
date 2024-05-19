
#include "FilterUtility.h"

#define SIN_LUT_SIZE 128

static float sin_lut[SIN_LUT_SIZE];

void initSin(){

    for(uint16_t i = 0; i < SIN_LUT_SIZE; i++){
        sin_lut[i] = sinf(2*M_PI*(float)i/SIN_LUT_SIZE);
    }

}

//x should be between 0 and 2 pi
//Output is between -32767 and 32767
float sinApproxLut(float x){

    x -= truncf(x/(2*M_PI))*2*M_PI;

    float _x = x * 0.159154943092f; //[0..2*pi] to [0..1]
    uint16_t index = (_x * SIN_LUT_SIZE);
    //printf("x: %f, _x: %f, index: %d\n", x, _x, index);

    return sin_lut[index];
    
}
