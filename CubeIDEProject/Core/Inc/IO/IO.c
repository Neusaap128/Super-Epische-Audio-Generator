/*
 * IO.c
 *
 *  Created on: Mar 23, 2024
 *      Author: rode-
 */

void reset_shift_register(uint8_t *num){
	*num = 0;
}

void array_in_shift(GPIO_TypeDef *port_Enable,GPIO_TypeDef *port_Input ,GPIO_TypeDef *port_Klok, uint16_t Pin_Enable, uint16_t Pin_input,uint16_t Pin_Klok, uint8_t num){
	HAL_GPIO_WritePin(port_Enable, Pin_Enable,0);
	for (int i = 7; i >= 0; i--) {
		uint8_t bit_value = (num >> i) & 1;
		HAL_GPIO_WritePin(port_Input, Pin_input,bit_value);
		HAL_Delay(1);
		HAL_GPIO_WritePin(port_Klok, Pin_Klok,1);
		HAL_Delay(1);
		HAL_GPIO_WritePin(port_Klok, Pin_Klok,0);
	  }
	  HAL_GPIO_WritePin(port_Enable, Pin_Enable,1);
}

int filter_select(uint16_t waarde){
	  if(waarde < 1000){
		  return 0;
	  }
	  else if(waarde < 2500){
		  return 1;
	  }
	  else{
		  return 2;
	  }
}

void filter_led(uint8_t *filter_led_array, int pressed,int filter){
	  for(int i = 0; i<8; i++){
		  if(i == filter && (pressed == 1 || pressed == 2)){
			  *filter_led_array |= (1 & 1) << (7 - i);
		  }
		  else{
			  *filter_led_array |= (0 & 1) << (7 - i);
		  }
	  }
}

void led_bar(uint16_t analoge_waarde, uint8_t *ledbar_array){
	  if(analoge_waarde < 250){
		  analoge_waarde = 0;
	  }
	  else{
		  analoge_waarde -= 250;
	  }

	   float led_bar = ((float)analoge_waarde/3200)*100;
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
}

uint16_t main_call(){
	uint16_t raw;
	uint16_t filter = 0;
	uint8_t ledbar_array;
	uint8_t filter_led_array;
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	raw = HAL_ADC_GetValue(&hadc1);
	//case voor de druk knoppen
	switch (pressed) {
	    case 1:
	    	filter = filter_select(raw);
	    	break;
	    case 2:
	    	led_bar(raw ,&ledbar_array);
	    	break;
	    case 3:
	    	pressed = 0;
	    default:
		reset_shift_register(&filter_led_array);
		reset_shift_register(&ledbar_array);
	  }
	filter_led(&filter_led_array, pressed, filter);
	array_in_shift(Shift_Enable_GPIO_Port,Shift_input_GPIO_Port,Shift_klok_GPIO_Port, Shift_Enable_Pin,Shift_input_Pin,Shift_klok_Pin,ledbar_array);
	array_in_shift(Shift2_Enable_GPIO_Port,Shift2_input_GPIO_Port,Shift2_klok_GPIO_Port, Shift2_Enable_Pin,Shift2_input_Pin,Shift2_klok_Pin,filter_led_array);
	reset_shift_register(&filter_led_array);
	reset_shift_register(&ledbar_array);
	return filter;
}

