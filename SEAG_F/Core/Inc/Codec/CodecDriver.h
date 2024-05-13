/*
 * CodecDriver.h
 *
 *  Created on: Mar 17, 2024
 *      Author: seppe
 */

#ifndef INC_CODEC_CODECDRIVER_H_
#define INC_CODEC_CODECDRIVER_H_

#include <stdlib.h>
#include <stdint.h>
#include "stm32f7xx_hal.h"

static const uint8_t codecAddr = 0x1A << 1; // Use 7-bit address

void CodecInit(I2C_HandleTypeDef *hi2c1);
void ResetCodec(I2C_HandleTypeDef *hi2c1);
void WriteCodecRegister(I2C_HandleTypeDef *hi2c1, uint8_t reg, uint16_t pData);

#endif /* INC_CODEC_CODECDRIVER_H_ */

