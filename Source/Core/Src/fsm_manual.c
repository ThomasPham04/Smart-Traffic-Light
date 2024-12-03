/*
 * fsm_manual.c
 *
 *  Created on: Oct 30, 2024
 *      Author: Admin
 */

#include "fsm_manual.h"

int counter_led = 0;

void fsm_manual_run() {
    switch (status) {
    case MAN_RED:
        if (counter_led > 0) counter_led--;
        if (counter_led == 0) {
            setToggleRed();
            counter_led = 50;
        }

        if (counter1 > 0) counter1--;
        if (counter1 == 0) {
            status = RED_GREEN;
            counter1 = 1000;
        }

        if (isButton1Pressed() == 1) {
            red_time_temp = red_time;
            status = MAN_AMBER;
            counter1 = 1000;
        }

        if (isButton2Pressed() == 1) {
            red_time_temp++;
            if (red_time_temp > 99) red_time_temp = 0;
            counter1 = 1000;
        }

        if (isButton3Pressed() == 1) {
            status = SET_RED;
        }

        break;

    case MAN_AMBER:
        if (counter_led > 0) counter_led--;
        if (counter_led == 0) {
            setToggleYellow();
            counter_led = 50;
        }

        if (counter1 > 0) counter1--;
        if (counter1 == 0) {
            status = RED_GREEN;
            counter1 = 1000;
        }

        if (isButton1Pressed() == 1) {
            amber_time_temp = amber_time;
            status = MAN_GREEN;
            counter1 = 1000;
        }

        if (isButton2Pressed() == 1) {
            amber_time_temp++;
            if (amber_time_temp > 99) amber_time_temp = 0;
            counter1 = 1000;
        }

        if (isButton3Pressed() == 1) {
            status = SET_AMBER;
        }
        break;

    case MAN_GREEN:
        if (counter_led > 0) counter_led--;
        if (counter_led == 0) {
            setToggleGreen();
            counter_led = 50;
        }

        if (counter1 > 0) counter1--;
        if (counter1 == 0) {
            green_time_temp = green_time;
            status = RED_GREEN;
            counter1 = 1000;
        }

        if (isButton1Pressed() == 1) {
            green_time_temp = green_time;
            status = INIT;
            counter1 = 100;
        }

        if (isButton2Pressed() == 1) {
            green_time_temp++;
            if (green_time_temp > 99) green_time_temp = 0;
            counter1 = 1000;
        }

        if (isButton3Pressed() == 1) {
            status = SET_GREEN;
        }
        break;

    default:
        break;
    }
}
