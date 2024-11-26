/*
 * fsm_button.c
 *
 *  Created on: Nov 26, 2024
 *      Author: Admin
 */

#include "fsm_button.h"

void fsm_button_run(){
	switch (status){
	case INIT:
		status = NO_TOGGLE;
		break;
	case TOGGLE:
		HAL_GPIO_TogglePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin);
		if (isButton1Pressed() == 1){
			status = NO_TOGGLE;
		}
		break;
	case NO_TOGGLE:
		HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, RESET);
		if (isButton1Pressed() == 1){
			status = TOGGLE;
		}
		break;
	default:
		break;
	}
}
