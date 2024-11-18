/*
 * global.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "light_traffic.h"
#include "main.h"

#define INIT 			1
#define RED_GREEN		2
#define RED_AMBER		3
#define GREEN_RED		4
#define AMBER_RED		5

#define RED_TIME 5
#define GREEN_TIME 3
#define AMBER_TIME 2

#define MAN_RED 	12
#define MAN_AMBER	13
#define MAN_GREEN	14

#define SET_RED			21
#define SET_AMBER		22
#define SET_GREEN		23

extern uint8_t led_buffer[4];

extern int fsm_status;
extern int status;
extern int mode;

extern int red_time, green_time, amber_time;
extern int red_time_temp, green_time_temp, amber_time_temp;

extern int index_led;

#endif /* INC_GLOBAL_H_ */
