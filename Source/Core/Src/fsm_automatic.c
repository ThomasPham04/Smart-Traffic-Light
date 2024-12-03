/*
 * fsm_auto.c
 *
 *  Created on: Oct 27, 2024
 *      Author: Admin
 */

#include "global.h"

// Counters to replace timers
int counter1 = 0;
int counter3 = 0;

void fsm_automatic_run() {
    switch (status) {
    case INIT:
        // TODO
        setTimeInit();
        setLightInit();
        status = RED_GREEN;
        counter3 = 100;  // 100 * 10ms = 1 second
        counter1 = green_time * 10;  // green_time in seconds
        break;

    case RED_GREEN:
        setRed_1();
        setGreen_2();

        if (counter3 > 0) counter3--;
        if (counter3 == 0) {
            red_time_temp--;
            green_time_temp--;
            counter3 = 100;  // Reset counter3 for the next 1 second
        }

        if (counter1 > 0) counter1--;
        if (counter1 <= 0) {
            status = RED_AMBER;
            green_time_temp = green_time;
            counter1 = amber_time * 10;
        }

        if (isButton1Pressed() == 1) {
            setTimeInit();
            status = MAN_RED;
            counter1 = 300;  // 3 seconds
        }
        break;

    case RED_AMBER:
        setRed_1();
        setYellow_2();

        if (counter3 > 0) counter3--;
        if (counter3 == 0) {
            red_time_temp--;
            amber_time_temp--;
            counter3 = 100;
        }

        if (counter1 > 0) counter1--;
        if (counter1 == 0) {
            status = GREEN_RED;
            amber_time_temp = amber_time;
            red_time_temp = red_time;
            counter1 = green_time * 10;
        }

        if (isButton1Pressed() == 1) {
            setTimeInit();
            status = MAN_RED;
            counter1 = 1000;  // 10 seconds
        }
        break;

    case GREEN_RED:
        setGreen_1();
        setRed_2();

        if (counter3 > 0) counter3--;
        if (counter3 == 0) {
            red_time_temp--;
            green_time_temp--;
            counter3 = 100;
        }

        if (counter1 > 0) counter1--;
        if (counter1 == 0) {
            status = AMBER_RED;
            green_time_temp = green_time;
            counter1 = amber_time * 10;
        }

        if (isButton1Pressed() == 1) {
            setTimeInit();
            status = MAN_RED;
            counter1 = 1000;  // 10 seconds
        }
        break;

    case AMBER_RED:
        setYellow_1();
        setRed_2();

        if (counter3 > 0) counter3--;
        if (counter3 == 0) {
            red_time_temp--;
            amber_time_temp--;
            counter3 = 100;
        }

        if (counter1 > 0) counter1--;
        if (counter1 == 0) {
            status = RED_GREEN;
            red_time_temp = red_time;
            amber_time_temp = amber_time;
            counter1 = green_time * 10;
        }

        if (isButton1Pressed() == 1) {
            setTimeInit();
            status = RED_GREEN;
            counter1 = 1000;  // 10 seconds
        }
        break;

    default:
        break;
    }
}
