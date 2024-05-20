/*
 * IO.c
 *
 *  Created on: Mar 23, 2024
 *      Author: rode-
 */

#include "IO.h"
#include "RotaryEncoder.h"


ShiftRegister_t shiftRegFilterSelect = {
	.clkPort 	 = ShiftRegFClk_GPIO_Port,
	.clkPin   	 = ShiftRegFClk_Pin,
	.dataPort 	 = ShiftRegFDat_GPIO_Port,
	.dataPin  	 = ShiftRegFDat_Pin,
	.enabledPort = ShiftRegFStoClk_GPIO_Port,
	.enabledPin  = ShiftRegFStoClk_Pin
};


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

uint8_t selectedFilter;

// 0 no state transition
// 1, SelectingValue -> Disabled
// 2, Disabled -> SelectingFilter
// 3, SelectingFilter -> SelectingValue
uint8_t switchedStateFlag;

void InitIO(){
	LoadValueIntoShiftRegister(&shiftRegFilterSelect, GetEnabledFilters());
	ResetShiftRegister(&shiftRegLedbar);
}

void HandleSelectingFilter(){

	selectedFilter = (uint16_t)(rotaryEncoder.currentPos/4) % AMOUNT_OF_FILTERS;
	LoadValueIntoShiftRegister(&shiftRegFilterSelect, 1 << selectedFilter);

}

void HandleSelectingValue(){

	uint8_t led_bar = (rotaryEncoder.currentPos/4);
	uint8_t ledbar_array = (1 << led_bar) - 1;

	changeFilterLevel(getFilters()->filterInstances[selectedFilter], (float)led_bar/(8-1));

	LoadValueIntoShiftRegister(&shiftRegLedbar, ledbar_array);

}

void ButtonInterrupt(){

	IOState = (IOState + 1)%3;

	rotaryEncoder.currentPos = 0;

	switchedStateFlag = IOState + 1;


}

void RotaryEncoderInterrupt(){
	rot_intrupt(&rotaryEncoder);
}


void IOUpdate(){


	//uint8_t buttonPressed = HAL_GPIO_ReadPin(ToggleInput1_GPIO_Port, ToggleInput1_Pin);
	//SetFilterState(0, buttonPressed);


	//Handling Transistions
	if(switchedStateFlag > 0){

		switch(switchedStateFlag){
			case 1:
				LoadValueIntoShiftRegister(&shiftRegFilterSelect, GetEnabledFilters());
				ResetShiftRegister(&shiftRegLedbar);
				break;
			case 2:
				// Nothing needs to be reset
				break;
			case 3:
				// Nothing needs to be reset
				rotaryEncoder.currentPos = 4; // At least one led on, at start
				break;
		}

		switchedStateFlag = 0;

	}

	//Handling states
	switch (IOState) {
	    case Disabled:
	    	break;
	    case SelectingFilter:
	    	HandleSelectingFilter();
	    	break;
	    case SelectingValue:
	    	HandleSelectingValue();
	    	break;
	  }



}




