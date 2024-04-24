/*
 * IO.h
 *
 *  Created on: Mar 23, 2024
 *      Author: rode-
 */

#ifndef INC_IO_IO_H_
#define INC_IO_IO_H_

int pressed;
void reset_shift_register(uint8_t *num);
void array_in_shift(GPIO_TypeDef *port_Enable,GPIO_TypeDef *port_Input ,GPIO_TypeDef *port_Klok, uint16_t Pin_Enable, uint16_t Pin_input,uint16_t Pin_Klok, uint8_t num);
int filter_select(uint16_t waarde);
void filter_led(uint8_t *filter_led_array, int pressed,int filter);
void led_bar(uint16_t analoge_waarde, uint8_t *ledbar_array);
int main_call();
#endif /* INC_IO_IO_H_ */
