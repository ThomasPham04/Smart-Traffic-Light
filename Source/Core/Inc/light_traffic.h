/*
 * light_traffic.h
 *
 *  Created on: Oct 27, 2024
 *      Author: Admin
 */

#ifndef INC_LIGHT_TRAFFIC_H_
#define INC_LIGHT_TRAFFIC_H_

#include "global.h"

void setLightInit();
void setTimeInit();

void setRed_1();
void setGreen_1();
void setYellow_1();

void setRed_2();
void setGreen_2();
void setYellow_2();

void setRed();
void setGreen();
void setYellow();

void setToggleRed();
void setToggleGreen();
void setToggleYellow();

void display7SEG(int num);
void update7SEG(int num);
void updateClockBuffer();

void updateTime();
void updateClock();

void dispMode();

extern const int MAX_LED;
extern int index_led;

#endif /* INC_LIGHT_TRAFFIC_H_ */
