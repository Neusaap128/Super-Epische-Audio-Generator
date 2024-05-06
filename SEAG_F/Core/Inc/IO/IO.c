/*
 * IO.c
 *
 *  Created on: Mar 23, 2024
 *      Author: rode-
 */

#include "IO.h"

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

uint16_t HandleSelectingFilter(){
	//aantal filter is een define
	if((int)(rot_cnt/4) > AANTALFILTER-1){
		rot_cnt = (AANTALFILTER-1)*4;
	}else if(rot_cnt<0){
		rot_cnt=0;
	}
	uint16_t filter = (uint_8)(rot_cnt/4);
	LoadValueIntoShiftRegister(&shiftRegFilterSelect,  1 << (7-filter));
	return filter;
}


void ButtonIntrupt(uint32_t time){
	  pressed += 1;
	  rot_cnt =0;
	  previousMillis = currentMillis; //moet globaal globaal zijn
}

void HandleSelectingValue(uint8_t *ledbar_array){ //rot_cnt gloable variable door intrupt
	  if(rot_cnt > 8*4){
		  rot_cnt = 8*4;
	  }
	  else if(rot_cnt < 0){
		  rot_cnt =0;
	  }

	  float led_bar = (rot_cnt/4)*12.5;
	  if(led_bar >= 100){
		  led_bar = 100;
	  }
	  for (int i = 0; i < 8 ; i++) {
	      if (led_bar>=12.5){
	    	  *ledbar_array |= (1 & 1) << (7 - i);
	    	  led_bar -= 12.5;
	      }
	      else{
	    	  *ledbar_array |= (0 & 1) << (7 - i);
	      }
	  }

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
	    	HandleSelectingValue(&ledbar_array);
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




