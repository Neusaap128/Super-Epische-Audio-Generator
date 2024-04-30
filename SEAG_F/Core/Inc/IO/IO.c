/*
 * IO.c
 *
 *  Created on: Mar 23, 2024
 *      Author: rode-
 */

#include "IO.h"


void HandleSelectingFilter(uint16_t potValue){


	//This code only works for Pot-meter, when using rotary encoder, this code should be revisited.
	//Of the top of my head something around selectedFilter = dir ? ( selectedFilter + 1 ) % 8 : (selectedFilter - 1) ma check als da < 0 is
	selectedFilter = (uint8_t)( ((float)potValue)/4096 * AMOUNT_OF_FILTERS );

	//Turning on correct LED
	LoadValueIntoShiftRegister(&shiftRegFilterSelect,  1 << (7-selectedFilter) );

	/*
	  if(waarde < 1000){
		  pressed = Disabled;
	  }else if(waarde < 2500){
		  pressed = SelectingFilter;
	  }else{
		  pressed = SelectingValue;
	  }
	*/
}

/*
void filter_led(uint8_t *filter_led_array, int pressed,int filter){

	*filter_led_array = 1 << ( 7-filter);

}
*/


void HandleSelectingValue(uint16_t analoge_waarde /*, uint8_t *ledbar_array*/){


	if(analoge_waarde < 250){
	  analoge_waarde = 0;
	}
	else{
	  analoge_waarde -= 250;
	}

	uint8_t led_bar = (uint8_t)((float)analoge_waarde/3200)*8;
	if(led_bar > 8){
	  led_bar = 8;
	}


	uint8_t ledbar_array = (1<<led_bar)-1;

	//for (int i = 0; i < 8 ; i++) {


	  /*
	  if (led_bar>=12.5){
		  *ledbar_array |= (1 & 1) << (7 - i);
		  led_bar -= 12.5;
	  }
	  else{
		  *ledbar_array |= (0 & 1) << (7 - i);
	  }
	  */

	//}


	LoadValueIntoShiftRegister(&shiftRegLedbar, ledbar_array);

}

uint16_t main_call(){
	uint16_t raw = 0;
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
	    	HandleSelectingFilter(raw);
	    	break;
	    case SelectingValue:
	    	HandleSelectingValue(raw /*,&ledbar_array*/ );
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




