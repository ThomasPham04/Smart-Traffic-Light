/*
 * fsm_manual.c
 *
 *  Created on: Oct 30, 2024
 *      Author: Admin
 */

#include "fsm_manual.h"
void fsm_manual_run(){
	switch (status){
	case MAN_RED:
		if (timer_led_flag == 1){
			setToggleRed();
			setTimerLed(500);
		}

		if (timer1_flag == 1){
			status = RED_GREEN;
			setTimer1(10000);
		}

		if (isButton1Pressed() == 1){
			status = MAN_AMBER;
			red_time_temp = red_time;
			setTimer1(10000);
		}

		if (isButton2Pressed() == 1){
			red_time_temp++;
			if (red_time_temp > 99) red_time_temp = 0;
			setTimer1(10000);
		}

		if (isButton3Pressed() == 1){
			status = SET_RED;
		}

		break;
	case MAN_GREEN:
		if (timer_led_flag == 1){
			setToggleGreen();
			setTimerLed(500);
		}

		if (timer1_flag == 1){
			green_time_temp = green_time;
			status = RED_GREEN;
			setTimer1(10000);
		}

		if (isButton1Pressed() == 1){
			status = RED_GREEN;;
			setTimer1(1000);
		}

		if (isButton2Pressed() == 1){
			green_time_temp++;
			if (green_time_temp > 99) green_time_temp = 0;
			setTimer1(10000);
		}

		if (isButton3Pressed()){
			status = SET_GREEN;
		}
		break;
	case MAN_AMBER:
		if (timer_led_flag == 1){
			setToggleYellow();
			setTimerLed(500);
		}

		if (timer1_flag == 1){
			status = RED_GREEN;
			setTimer1(10000);
		}

		if (isButton1Pressed() == 1){
			status = MAN_GREEN;
			amber_time_temp = amber_time;
			setTimer1(10000);
		}

		if (isButton2Pressed() == 1){
			amber_time_temp++;
			if (amber_time_temp > 99) amber_time_temp = 0;
			setTimer1(10000);
		}

		if(isButton3Pressed() == 1){
			status = SET_AMBER;
		}
		break;
	default:
		break;
	}
}
