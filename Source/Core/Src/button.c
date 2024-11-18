/*
 * button.c
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */

#include "button.h"

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

//button 1
int Key1Reg0 = NORMAL_STATE;
int Key1Reg1 = NORMAL_STATE;
int Key1Reg2 = NORMAL_STATE;

int Key1Reg3 = NORMAL_STATE;
int TimerForKey1Press = 200;

//button 2
int Key2Reg0 = NORMAL_STATE;
int Key2Reg1 = NORMAL_STATE;
int Key2Reg2 = NORMAL_STATE;

int Key2Reg3 = NORMAL_STATE;
int TimerForKey2Press = 200;

//button 3
int Key3Reg0 = NORMAL_STATE;
int Key3Reg1 = NORMAL_STATE;
int Key3Reg2 = NORMAL_STATE;

int Key3Reg3 = NORMAL_STATE;
int TimerForKey3Press = 200;


int isButton1Pressed(){
	if (button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}

int isButton2Pressed(){
	if (button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}

int isButton3Pressed(){
	if (button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}


void subKey1Process(){
//	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	button1_flag = 1;
}

void subKey2Process(){
//	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	button2_flag = 1;
}

void subKey3Process(){
//	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	button3_flag = 1;
}

void getKey1Input(){
	Key1Reg0 = Key1Reg1;
	Key1Reg1 = Key1Reg2;
	Key1Reg2 = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
	if ((Key1Reg0 == Key1Reg1) && (Key1Reg1 == Key1Reg2)){
		if (Key1Reg3 != Key1Reg2){//nhan tha
			Key1Reg3 = Key1Reg2;
			if (Key1Reg2 == PRESSED_STATE){
				//TODO
				subKey1Process();
				TimerForKey1Press = 200;
			}
		} else{//nhan giu
			TimerForKey1Press--;
			if (TimerForKey1Press == 0){
				Key1Reg3 = NORMAL_STATE;
			}
		}
	}
}

void getKey2Input(){
	Key2Reg0 = Key2Reg1;
	Key2Reg1 = Key2Reg2;
	Key2Reg2 = HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
	if ((Key2Reg0 == Key2Reg1) && (Key2Reg1 == Key2Reg2)){
		if (Key2Reg3 != Key2Reg2){
			Key2Reg3 = Key2Reg2;
			if (Key2Reg2 == PRESSED_STATE){
				//TODO
				button2_flag = 1;
				TimerForKey2Press = 200;
			}
		} else{
			TimerForKey2Press--;
			if (TimerForKey2Press == 0){
				Key2Reg3 = NORMAL_STATE;
			}
		}
	}
}


void getKey3Input(){
	Key3Reg0 = Key3Reg1;
	Key3Reg1 = Key3Reg2;
	Key3Reg2 = HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin);
	if ((Key3Reg0 == Key3Reg1) && (Key3Reg1 == Key3Reg2)){
		if (Key3Reg3 != Key3Reg2){
			Key3Reg3 = Key3Reg2;
			if (Key3Reg2 == PRESSED_STATE){
				//TODO
				button3_flag = 1;
				TimerForKey3Press = 200;
			}
		} else{
			TimerForKey3Press--;
			if (TimerForKey3Press == 0){
				Key3Reg3 = NORMAL_STATE;
			}
		}
	}
}
