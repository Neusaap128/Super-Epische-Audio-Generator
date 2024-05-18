
#include "FilterUtility.h"


float sinApprox(float x, uint8_t n) {

	float _x = x;

    float result = 0;
    float term = _x;
    float x_squared = _x * _x;
    uint8_t sign = 1;
    float fact = 1;

    for (uint8_t i = 1; i <= n; i++) {
        result += sign * term / fact;
        sign *= -1;
        term *= x_squared;
        fact *= (2 * i) * (2 * i + 1);
    }

    return result;

}

