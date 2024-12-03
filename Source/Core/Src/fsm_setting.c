/*
 * fsm_setting.c
 *
 *  Created on: Oct 30, 2024
 *      Author: Admin
 */


#include "fsm_setting.h"

void fsm_setting_run(){
//	int diff = 0;
	switch (status) {
		case SET_RED:
//			diff = red_time_temp - red_time;
			red_time = red_time_temp;
			red_time_temp = red_time;
//			green_time += diff;
//			green_time_temp += diff;
			status = MAN_RED;
			break;
		case SET_AMBER:
//			diff = amber_time_temp - amber_time;
			amber_time = amber_time_temp;
			amber_time_temp = amber_time;
//			red_time += diff;
//			red_time_temp += diff;
			status = MAN_AMBER;
			break;
		case SET_GREEN:
//			diff = green_time_temp - green_time;
			green_time = green_time_temp;
			green_time_temp = green_time;
//			red_time += diff;
//			red_time_temp += diff;
			status = MAN_GREEN;
			break;
		default:
			break;
	}
}
