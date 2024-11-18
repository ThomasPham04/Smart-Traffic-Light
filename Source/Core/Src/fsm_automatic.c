/*
 * fsm_auto.c
 *
 *  Created on: Oct 27, 2024
 *      Author: Admin
 */


#include "global.h"



void fsm_automatic_run(){
	switch(status){
	case INIT:
		//TODO
		setTimeInit();
		setLightInit();
		status = RED_GREEN;
		setTimer3(1000);
		setTimer1(green_time_temp * 1000);
		break;

	case RED_GREEN:
		setRed_1();
		setGreen_2();
		if (timer3_flag == 1){
			red_time_temp--;
			green_time_temp--;
			setTimer3(1000);
		}

		if (timer1_flag == 1){
			status = RED_AMBER;
			green_time_temp = green_time;
			setTimer1(amber_time_temp * 1000);
		}

		if (isButton1Pressed() == 1){
			status = MAN_RED;
			setTimer1(3000);
		}
		break;

	case RED_AMBER:
		setRed_1();
		setYellow_2();
		if(timer3_flag == 1){
			red_time_temp--;
			amber_time_temp--;
			setTimer3(1000);
		}

		if (timer1_flag == 1){
			status = GREEN_RED;
			amber_time_temp = amber_time;
			red_time_temp = red_time;
			setTimer1(green_time_temp * 1000);
		}

		if (isButton1Pressed() == 1){
			status = MAN_RED;
			setTimer1(10000);
		}
		break;


	case GREEN_RED:
		setGreen_1();
		setRed_2();
		if(timer3_flag == 1){
			red_time_temp--;
			green_time_temp--;
			setTimer3(1000);
		}
		if (timer1_flag == 1){
			status = AMBER_RED;
			green_time_temp = green_time;
			setTimer1(amber_time_temp * 1000);
		}

		if (isButton1Pressed() == 1){
			status = MAN_RED;
			setTimer1(10000);
		}
		break;

	case AMBER_RED:
		setYellow_1();
		setRed_2();
		if(timer3_flag == 1){
			red_time_temp--;
			amber_time_temp--;
			setTimer3(1000);
		}
		if (timer1_flag == 1){
			status = RED_GREEN;
			red_time_temp = red_time;
			amber_time_temp = amber_time;
			setTimer1(green_time_temp);
		}

		if (isButton1Pressed() == 1){
			status = MAN_RED;
			setTimer1(10000);
		}
		break;
	default:
		break;
	}
}


