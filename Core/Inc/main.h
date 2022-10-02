/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define EMM0_Pin GPIO_PIN_1
#define EMM0_GPIO_Port GPIOA
#define EMM1_Pin GPIO_PIN_2
#define EMM1_GPIO_Port GPIOA
#define DOT_Pin GPIO_PIN_4
#define DOT_GPIO_Port GPIOA
#define LED_RED_Pin GPIO_PIN_5
#define LED_RED_GPIO_Port GPIOA
#define EN0_Pin GPIO_PIN_6
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_7
#define EN1_GPIO_Port GPIOA
#define LED7_0_Pin GPIO_PIN_0
#define LED7_0_GPIO_Port GPIOB
#define LED7_1_Pin GPIO_PIN_1
#define LED7_1_GPIO_Port GPIOB
#define LED7_2_Pin GPIO_PIN_2
#define LED7_2_GPIO_Port GPIOB
#define ROW2_Pin GPIO_PIN_10
#define ROW2_GPIO_Port GPIOB
#define ROW3_Pin GPIO_PIN_11
#define ROW3_GPIO_Port GPIOB
#define ROW4_Pin GPIO_PIN_12
#define ROW4_GPIO_Port GPIOB
#define ROW5_Pin GPIO_PIN_13
#define ROW5_GPIO_Port GPIOB
#define ROW6_Pin GPIO_PIN_14
#define ROW6_GPIO_Port GPIOB
#define ROW7_Pin GPIO_PIN_15
#define ROW7_GPIO_Port GPIOB
#define EN2_Pin GPIO_PIN_8
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_9
#define EN3_GPIO_Port GPIOA
#define EMM2_Pin GPIO_PIN_10
#define EMM2_GPIO_Port GPIOA
#define EMM3_Pin GPIO_PIN_11
#define EMM3_GPIO_Port GPIOA
#define EMM4_Pin GPIO_PIN_12
#define EMM4_GPIO_Port GPIOA
#define EMM5_Pin GPIO_PIN_13
#define EMM5_GPIO_Port GPIOA
#define EMM6_Pin GPIO_PIN_14
#define EMM6_GPIO_Port GPIOA
#define EMM7_Pin GPIO_PIN_15
#define EMM7_GPIO_Port GPIOA
#define LED7_3_Pin GPIO_PIN_3
#define LED7_3_GPIO_Port GPIOB
#define LED7_4_Pin GPIO_PIN_4
#define LED7_4_GPIO_Port GPIOB
#define LED7_5_Pin GPIO_PIN_5
#define LED7_5_GPIO_Port GPIOB
#define LED7_6_Pin GPIO_PIN_6
#define LED7_6_GPIO_Port GPIOB
#define ROW0_Pin GPIO_PIN_8
#define ROW0_GPIO_Port GPIOB
#define ROW1_Pin GPIO_PIN_9
#define ROW1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
