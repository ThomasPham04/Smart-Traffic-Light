/*
 * global.c
 *
 *  Created on: Oct 27, 2024
 *      Author: Admin
 */
#include "global.h"

 int status = INIT;
 uint8_t led_buffer[4] = {0};
 int index_led = 0;
 int red_time = RED_TIME, green_time = GREEN_TIME, amber_time = AMBER_TIME;
 int red_time_temp, green_time_temp, amber_time_temp;
 int mode = 1;
