
#include "FilterUtility.h"

#define SIN_LUT_SIZE 128

static float sin_lut[SIN_LUT_SIZE];

void initSin(){

    for(uint16_t i = 0; i < SIN_LUT_SIZE; i++){
        sin_lut[i] = sinf(M_TWOPI*(float)i/SIN_LUT_SIZE); //berekent de sinus voor verschillende waardens en slaagt het op in array
    }

}

//x should be between 0 and 2 pi
float sinApproxLut(float x){

    //x -= truncf(x/(M_TWOPI))*M_TWOPI;

    float _x = x * 0.159154943092f; //[0..2*pi] to [0..1]
    float findex = (_x * SIN_LUT_SIZE);
    uint16_t index = (uint16_t)(findex);

    float fract = findex - index;

    return (1.0f*fract)*sin_lut[index]+fract*sin_lut[index+1];  //geeft een geinterpoleerde sinus waarde terug
    
    //return sin_lut[3];

}
