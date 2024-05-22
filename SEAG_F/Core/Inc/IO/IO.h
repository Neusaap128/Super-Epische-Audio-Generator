/*
 * IO.h
 *
 *  Created on: Mar 23, 2024
 *      Author: rode-
 */

#ifndef INC_IO_IO_H_
#define INC_IO_IO_H_

#include <stdlib.h>
#include "main.h"
#include "ShiftRegister.h"
#include "../Common.h"
#include "../DSP/DSP.h"

typedef enum{ //states in welke fase je zit, word bepaald door het aantal drukken op de rotetry encoderder
	Disabled,
	SelectingFilter,
	SelectingValue
}IOState_t;


void InitIO();

// Registers

/*
 * gaat bepalen welke filter je wilt aanpassen
 * gaat de ook de waarde in het shiftregister gaan laden zodat juiste led gaat branden (ledjes boven toggels)
*/
void HandleSelectingFilter();

/*
 * gaat kijken welke waarde gedraaid is met de rottery encoder
 * dit gaat die ook door geven voor de filters welke waarden dit moet zijn (ledbar)
 * laad het in het shift register
 */
void HandleSelectingValue();

/*
 * gaat de filters aan of af zetten
 * Dit ook door geven naar de ledjes (ledjes boven de toggels)
 */
void UpdateLedsActiveFilters();

// Rotary Encoder
/*
 * gaat kijken of de butten is in gedrukt en daar afhankelijk van state machine aan passen
 */
void ButtonInterrupt();

/*
 * gaat kijken welke 4 state door loopt is en daar afhnklijk van de algeme var aanpassen
 */
void RotaryEncoderInterrupt();

void IOUpdate();


#endif /* INC_IO_IO_H_ */





