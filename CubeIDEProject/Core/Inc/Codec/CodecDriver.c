/*
 * CodecDriver.c
 *
 *  Created on: Mar 17, 2024
 *      Author: seppe
 */
#include "CodecDriver.h"

void CodecInit(I2C_HandleTypeDef *hi2c1){


	ResetCodec(hi2c1);

	HAL_Delay(25);

	// ----- Power Management -----

	// R25 VMIDSEL: 01 = driver enable(playback/record), VREF enable, AINL enable, AINR disabled, ADCL enable, ADCR disable, MICB disable, MCLK enabled
	//WriteCodecRegister(hi2c1, 0x19, 0b111101000);

	//left DAC, LOUT1 buffer SPKL PGA, PLL enabled
	//WriteCodecRegister(hi2c1, 0x1A, 0b101010001);

	//left PGA enabled, Left output mixer
	//WriteCodecRegister(hi2c1, 0x2F, 0b000101000);


	// -----------

	//Connect Linput1 to inverting input of left input PGA, 0db gain, connecting Left input PGA to input booster
	WriteCodecRegister(hi2c1, 0x20, 0b100001000);

	// L out Volume
	WriteCodecRegister(hi2c1, 0x02, 0b101111001);

	//un mute left channel
	WriteCodecRegister(hi2c1, 0x00, 0b100000000);

	//mute right channel
	WriteCodecRegister(hi2c1, 0x01, 0b100000000);

	//Enable LB2LO
	WriteCodecRegister(hi2c1, 0x2D, 0b101010000);


	// ----- Power Management -----

	// outdated R25 VMIDSEL: 01 = driver enable(playback/record), VREF enable, AINL enable, AINR disabled, ADCL enable, ADCR disable, MICB disable, MCLK enabled
	WriteCodecRegister(hi2c1, 0x19, 0b111111100);

	//left DAC, LOUT1 buffer SPKL PGA, PLL enabled
	WriteCodecRegister(hi2c1, 0x1A, 0b111010000);

	//left PGA enabled, Left output mixer
	WriteCodecRegister(hi2c1, 0x2F, 0b000111100);

	// L out Volume
	WriteCodecRegister(hi2c1, 0x02, 0b100000000);



	// Disable master mode codec
	WriteCodecRegister(hi2c1, 0x07, 0b000001010);

	WriteCodecRegister(hi2c1, 0x20, 0b100001000);

	WriteCodecRegister(hi2c1, 0x21, 0b100001000);

	WriteCodecRegister(hi2c1, 0x2D, 0b000000000);

	WriteCodecRegister(hi2c1, 0x2E, 0b000000000);

	WriteCodecRegister(hi2c1, 0x22, 0b101010000);

	WriteCodecRegister(hi2c1, 0x25, 0b101010000);

	WriteCodecRegister(hi2c1, 0x34, 0b000000000);

	WriteCodecRegister(hi2c1, 0x04, 0b000000000);

	WriteCodecRegister(hi2c1, 0x08, 0b111000000);

	WriteCodecRegister(hi2c1, 0x05, 0b000000000);

	WriteCodecRegister(hi2c1, 0x09, 0b000000001);


	/*
	uint8_t buf[12];
	buf[0]=0x55;
	HAL_I2C_Master_Transmit(hi2c1, codecAddr, buf, 1 , HAL_MAX_DELAY);

	HAL_I2C_Mem_Write(hi2c1, codecAddr, reg , I2C_MEMADD_SIZE_8BIT, data)
	*/

}


void ResetCodec(I2C_HandleTypeDef *hi2c1){
	WriteCodecRegister(hi2c1, 0x0F, 0xFF);
}

void WriteCodecRegister(I2C_HandleTypeDef *hi2c1, uint16_t reg, uint16_t pData){
	uint8_t lowByte  = (uint8_t)(pData & 0xFF);
	uint8_t highByte = (uint8_t)(pData >> 8);
	HAL_I2C_Mem_Write(hi2c1, codecAddr, reg, I2C_MEMADD_SIZE_8BIT, &highByte, 1, HAL_MAX_DELAY);
	HAL_I2C_Mem_Write(hi2c1, codecAddr, reg, I2C_MEMADD_SIZE_8BIT, &lowByte, 1, HAL_MAX_DELAY);

}











