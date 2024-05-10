/*
 * IO.c
 *
 *  Created on: Mar 23, 2024
 *      Author: rode-
 */

#include "IO.h"
#include "RotaryEncoder.h"

/*
ShiftRegister_t shiftRegFilterSelect = {
	.clkPort 	 = ShiftRegFClk_GPIO_Port,
	.clkPin   	 = ShiftRegFClk_Pin,
	.dataPort 	 = ShiftRegFDat_GPIO_Port,
	.dataPin  	 = ShiftRegFDat_Pin,
	.enabledPort = ShiftRegFStoClk_GPIO_Port,
	.enabledPin  = ShiftRegFStoClk_Pin
};
*/


ShiftRegister_t shiftRegLedbar = {
	.clkPort 	 = ShiftRegLBarClk_GPIO_Port,
	.clkPin   	 = ShiftRegLBarClk_Pin,
	.dataPort 	 = ShiftRegLBarDat_GPIO_Port,
	.dataPin  	 = ShiftRegLBarDat_Pin,
	.enabledPort = ShiftRegLBarStoClk_GPIO_Port,
	.enabledPin  = ShiftRegLBarStoClk_Pin
};

RotaryEncoder_t rotaryEncoder = {
	.currentPos	= 0,
	.portA   	= RotEncoderInA_GPIO_Port,
	.pinA 	 	= RotEncoderInA_Pin,
	.portB  	= RotEncoderInB_GPIO_Port,
	.pinB 		= RotEncoderInB_Pin,
	.portButton = RotEncoderButton_GPIO_Port,
	.pinButton  = RotEncoderButton_Pin
};

IOState_t IOState;

uint8_t HandleSelectingFilter(){

	uint8_t filter = (uint16_t)(rotaryEncoder.currentPos/4) & AMOUNT_OF_FILTERS;
	//LoadValueIntoShiftRegister(&shiftRegFilterSelect,  1 << (7-filter));
	return filter;

}


void ButtonInterrupt(uint32_t time){

	IOState = (IOState + 1)%3;

	rotaryEncoder.currentPos = 0;


}

void RotaryEncoderInterrupt(){
	rot_intrupt(&rotaryEncoder);
}

void HandleSelectingValue(){


	uint8_t led_bar = (rotaryEncoder.currentPos/4)/8;
	uint8_t ledbar_array = (1 << led_bar) - 1;

	LoadValueIntoShiftRegister(&shiftRegLedbar, ledbar_array);

}

uint16_t main_call(){
	uint16_t filter = 0;
	//uint8_t ledbar_array = 0;
	//uint8_t filter_led_array = 0;

	//HAL_ADC_Start(&hadc1);
	//HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	//raw = HAL_ADC_GetValue(&hadc1);
	//case voor de druk knoppen

	switch (IOState) {
	    case Disabled:
	    	break;
	    case SelectingFilter:
	    	break;
	    case SelectingValue:
	    	HandleSelectingValue();
	    	break;
	  }

	//ResetShiftRegister(&filterSelectShiftReg);

	//ResetShiftRegister(&filter_led_array);
	//ResetShiftRegister(&ledbar_array);

	//filter_led(&filter_led_array, pressed, filter);
	//array_in_shift(Shift_Enable_GPIO_Port,Shift_input_GPIO_Port,Shift_klok_GPIO_Port, Shift_Enable_Pin,Shift_input_Pin,Shift_klok_Pin,ledbar_array);
	//array_in_shift(Shift2_Enable_GPIO_Port,Shift2_input_GPIO_Port,Shift2_klok_GPIO_Port, Shift2_Enable_Pin,Shift2_input_Pin,Shift2_klok_Pin,filter_led_array);
	//ResetShiftRegister(&filter_led_array);
	//ResetShiftRegister(&ledbar_array);
	return filter;
}




