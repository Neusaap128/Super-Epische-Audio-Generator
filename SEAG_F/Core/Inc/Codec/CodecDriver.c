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


	//Connect Linput1 to inverting input of left input PGA, 0db gain, connecting Left input PGA to input booster
	//WriteCodecRegister(hi2c1, 0x20, 0b100001000);

	// L out Volume
	WriteCodecRegister(hi2c1, 0x02, 0b101111001);

	//un mute left channel, LINVOL = +0DB [5:0]
	WriteCodecRegister(hi2c1, 0x00, 0b100010111);

	//mute right channel
	WriteCodecRegister(hi2c1, 0x01, 0b100000000);

	//Enable LB2LO
	WriteCodecRegister(hi2c1, 0x2D, 0b001010000);


	// ----- Power Management -----

	// outdated R25 VMIDSEL: 01 = driver enable(playback/record), VREF enable, AINL enable, AINR disabled, ADCL enable, ADCR disable, MICB disable, MCLK enabled
	WriteCodecRegister(hi2c1, 0x19, 0b011111100);

	//left DAC, LOUT1 buffer SPKL PGA, PLL enabled
	WriteCodecRegister(hi2c1, 0x1A, 0b111010000);

	//left PGA enabled, Left output mixer
	WriteCodecRegister(hi2c1, 0x2F, 0b000111100);

	// L out Volume
	//WriteCodecRegister(hi2c1, 0x02, 0b100000000);

	//-----------------------

	// Disable master mode codec, I²S format
	WriteCodecRegister(hi2c1, 0x07, 0b000000010);

	WriteCodecRegister(hi2c1, 0x20, 0b100001000);

	WriteCodecRegister(hi2c1, 0x21, 0b000000000);

	WriteCodecRegister(hi2c1, 0x2E, 0b000000000);

	WriteCodecRegister(hi2c1, 0x22, 0b101010000);

	WriteCodecRegister(hi2c1, 0x25, 0b001010000);

	//Write speaker L volume
	WriteCodecRegister(hi2c1, 0x28, 0b101111001);
	//Write speaker R volume
	WriteCodecRegister(hi2c1, 0x29, 0b101111001);

	WriteCodecRegister(hi2c1, 0x34, 0b000000000);

	WriteCodecRegister(hi2c1, 0x04, 0b000000000);

	WriteCodecRegister(hi2c1, 0x08, 0b111000000);

	// Disabled high pass filter
	WriteCodecRegister(hi2c1, 0x05, 0b000000001);

	WriteCodecRegister(hi2c1, 0x09, 0b000000000);

	//Writing ADC and DAC volume
	WriteCodecRegister(hi2c1, 0x15, 0b111000011);
	WriteCodecRegister(hi2c1, 0x16, 0b111000011);

	//Writing ADC and DAC volume
	WriteCodecRegister(hi2c1, 0x0A, 0b111111111);
	WriteCodecRegister(hi2c1, 0x0B, 0b111111111);


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

void WriteCodecRegister(I2C_HandleTypeDef *hi2c1, uint8_t reg, uint16_t pData){
	uint8_t regAddrWDataBit = (uint8_t)(reg << 1) | (pData >> 8);
	uint8_t lowByte = (uint8_t)(pData & 0xFF);
	HAL_I2C_Mem_Write(hi2c1, codecAddr, regAddrWDataBit, I2C_MEMADD_SIZE_8BIT, &lowByte, 1, HAL_MAX_DELAY);
}











