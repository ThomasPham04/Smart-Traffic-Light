/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Button0_Pin GPIO_PIN_13
#define Button0_GPIO_Port GPIOC
#define EN0_Pin GPIO_PIN_1
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_2
#define EN1_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_3
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_4
#define EN3_GPIO_Port GPIOA
#define LED_RED_Pin GPIO_PIN_5
#define LED_RED_GPIO_Port GPIOA
#define LED_GREEN_Pin GPIO_PIN_6
#define LED_GREEN_GPIO_Port GPIOA
#define LED_YELLOW_Pin GPIO_PIN_7
#define LED_YELLOW_GPIO_Port GPIOA
#define LED_1_RED_Pin GPIO_PIN_0
#define LED_1_RED_GPIO_Port GPIOB
#define LED_1_GREEN_Pin GPIO_PIN_1
#define LED_1_GREEN_GPIO_Port GPIOB
#define LED_1_YELLOW_Pin GPIO_PIN_2
#define LED_1_YELLOW_GPIO_Port GPIOB
#define SEG_04_Pin GPIO_PIN_10
#define SEG_04_GPIO_Port GPIOB
#define SEG_05_Pin GPIO_PIN_11
#define SEG_05_GPIO_Port GPIOB
#define SEG_06_Pin GPIO_PIN_12
#define SEG_06_GPIO_Port GPIOB
#define Button1_Pin GPIO_PIN_13
#define Button1_GPIO_Port GPIOB
#define Button2_Pin GPIO_PIN_14
#define Button2_GPIO_Port GPIOB
#define Button3_Pin GPIO_PIN_15
#define Button3_GPIO_Port GPIOB
#define LED_BLUE_Pin GPIO_PIN_8
#define LED_BLUE_GPIO_Port GPIOA
#define SEG_0_Pin GPIO_PIN_9
#define SEG_0_GPIO_Port GPIOA
#define SEG_1_Pin GPIO_PIN_10
#define SEG_1_GPIO_Port GPIOA
#define SEG_2_Pin GPIO_PIN_11
#define SEG_2_GPIO_Port GPIOA
#define SEG_3_Pin GPIO_PIN_12
#define SEG_3_GPIO_Port GPIOA
#define SEG_4_Pin GPIO_PIN_13
#define SEG_4_GPIO_Port GPIOA
#define SEG_5_Pin GPIO_PIN_14
#define SEG_5_GPIO_Port GPIOA
#define SEG_6_Pin GPIO_PIN_15
#define SEG_6_GPIO_Port GPIOA
#define LED_2_RED_Pin GPIO_PIN_3
#define LED_2_RED_GPIO_Port GPIOB
#define LED_2_GREEN_Pin GPIO_PIN_4
#define LED_2_GREEN_GPIO_Port GPIOB
#define LED_2_YELLOW_Pin GPIO_PIN_5
#define LED_2_YELLOW_GPIO_Port GPIOB
#define SEG_00_Pin GPIO_PIN_6
#define SEG_00_GPIO_Port GPIOB
#define SEG_01_Pin GPIO_PIN_7
#define SEG_01_GPIO_Port GPIOB
#define SEG_02_Pin GPIO_PIN_8
#define SEG_02_GPIO_Port GPIOB
#define SEG_03_Pin GPIO_PIN_9
#define SEG_03_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
#ifdef SCH_REPORT_ERRORS
#define Error_port PORTA
#endif
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
