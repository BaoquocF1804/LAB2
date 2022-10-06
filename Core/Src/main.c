/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "SoftwareTimer.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
{
	timerRun();
 }


void displayDOT ( uint8_t num ) { // LSB (0) = > MSB (7)
	HAL_GPIO_WritePin ( EMM0_GPIO_Port , EMM7_Pin , !( num & 0x01 )) ;
	HAL_GPIO_WritePin ( EMM1_GPIO_Port , EMM6_Pin , !( num & 0x02 )) ;
	HAL_GPIO_WritePin ( EMM2_GPIO_Port , EMM5_Pin , !( num & 0x04 )) ;
	HAL_GPIO_WritePin ( EMM3_GPIO_Port , EMM4_Pin , !( num & 0x08 )) ;
	HAL_GPIO_WritePin ( EMM4_GPIO_Port , EMM3_Pin , !( num & 0x10 )) ;
	HAL_GPIO_WritePin ( EMM5_GPIO_Port , EMM2_Pin , !( num & 0x20 )) ;
	HAL_GPIO_WritePin ( EMM6_GPIO_Port , EMM1_Pin , !( num & 0x40 )) ;
	HAL_GPIO_WritePin ( EMM7_GPIO_Port , EMM0_Pin , !( num & 0x80 )) ;
 }

void clearMatrix () {
 HAL_GPIO_WritePin ( ROW0_GPIO_Port , ROW0_Pin , 1) ;
 HAL_GPIO_WritePin ( ROW1_GPIO_Port , ROW1_Pin , 1) ;
 HAL_GPIO_WritePin ( ROW2_GPIO_Port , ROW2_Pin , 1) ;
 HAL_GPIO_WritePin ( ROW3_GPIO_Port , ROW3_Pin , 1) ;
 HAL_GPIO_WritePin ( ROW4_GPIO_Port , ROW4_Pin , 1) ;
 HAL_GPIO_WritePin ( ROW5_GPIO_Port , ROW5_Pin , 1) ;
 HAL_GPIO_WritePin ( ROW6_GPIO_Port , ROW6_Pin , 1) ;
 HAL_GPIO_WritePin ( ROW7_GPIO_Port , ROW7_Pin , 1) ;
}

uint8_t matrix_buffer [8] = {0x18 ,0x3c ,0x66 ,0x66 ,0x7e ,0x66 ,0x66 ,0x66 }; // 	 .


void updateLEDMatrix (int index ) {
 switch ( index ) {
 	 case 0:
		displayDOT ( matrix_buffer [0]) ;
		HAL_GPIO_WritePin ( ROW7_GPIO_Port , ROW7_Pin , 1) ;
		HAL_GPIO_WritePin ( ROW0_GPIO_Port , ROW0_Pin , 0) ;
		break ;
 	 case 1:
 		 displayDOT ( matrix_buffer [1]) ;
 		 HAL_GPIO_WritePin ( ROW0_GPIO_Port , ROW0_Pin , 1) ;
 		 HAL_GPIO_WritePin ( ROW1_GPIO_Port , ROW1_Pin , 0) ;
 		 break ;
 	 case 2:
 		 displayDOT ( matrix_buffer [2]) ;
 		 HAL_GPIO_WritePin ( ROW1_GPIO_Port , ROW1_Pin , 1) ;
 		 HAL_GPIO_WritePin ( ROW2_GPIO_Port , ROW2_Pin , 0) ;
 		 break ;
 	 case 3:
 		 displayDOT ( matrix_buffer [3]) ;
 		 HAL_GPIO_WritePin ( ROW2_GPIO_Port , ROW2_Pin , 1) ;
 		 HAL_GPIO_WritePin ( ROW3_GPIO_Port , ROW3_Pin , 0) ;
 		 break ;
 	 case 4:
 		 displayDOT ( matrix_buffer [4]) ;
 		 HAL_GPIO_WritePin ( ROW3_GPIO_Port , ROW3_Pin , 1) ;
 		 HAL_GPIO_WritePin ( ROW4_GPIO_Port , ROW4_Pin , 0) ;
 		 break ;
 	 case 5:
 		 displayDOT ( matrix_buffer [5]) ;
 		 HAL_GPIO_WritePin ( ROW4_GPIO_Port , ROW4_Pin , 1) ;
 		 HAL_GPIO_WritePin ( ROW5_GPIO_Port , ROW5_Pin , 0) ;
 		 break ;
	 case 6:
		 displayDOT ( matrix_buffer [6]) ;
		 HAL_GPIO_WritePin ( ROW5_GPIO_Port , ROW5_Pin , 1) ;
		 HAL_GPIO_WritePin ( ROW6_GPIO_Port , ROW6_Pin , 0) ;
		 break ;
	 case 7:
		 displayDOT ( matrix_buffer [7]) ;
		 HAL_GPIO_WritePin ( ROW6_GPIO_Port , ROW6_Pin , 1) ;
		 HAL_GPIO_WritePin ( ROW7_GPIO_Port , ROW7_Pin , 0) ;
		 break ;
	 default :
	 break ;
	 }
 }


//void shiftBit () {
// // Shift MSB to LSB matrix_buffer [0]
// int msb = ( matrix_buffer [0] & 0x80 ) >> 7;
// matrix_buffer [0] = ( matrix_buffer [0] << 1) + msb ;
// // Shift MSB to LSB matrix_buffer [1]
// msb = ( matrix_buffer [1] & 0x80 ) >> 7;
// matrix_buffer [1] = ( matrix_buffer [1] << 1) + msb ;
// // Shift MSB to LSB matrix_buffer [2]
// msb = ( matrix_buffer [2] & 0x80 ) >> 7;
// matrix_buffer [2] = ( matrix_buffer [2] << 1) + msb ;
// // Shift MSB to LSB matrix_buffer [3]
// msb = ( matrix_buffer [3] & 0x80 ) >> 7;
// matrix_buffer [3] = ( matrix_buffer [3] << 1) + msb ;
// // Shift MSB to LSB matrix_buffer [4]
// msb = ( matrix_buffer [4] & 0x80 ) >> 7;
// matrix_buffer [4] = ( matrix_buffer [4] << 1) + msb ;
// // Shift MSB to LSB matrix_buffer [5]
// msb = ( matrix_buffer [5] & 0x80 ) >> 7;
// matrix_buffer [5] = ( matrix_buffer [5] << 1) + msb ;
// // Shift MSB to LSB matrix_buffer [6]
// msb = ( matrix_buffer [6] & 0x80 ) >> 7;
// matrix_buffer [6] = ( matrix_buffer [6] << 1) + msb ;
// // Shift MSB to LSB matrix_buffer [7]
// msb = ( matrix_buffer [7] & 0x80 ) >> 7;
// matrix_buffer [7] = ( matrix_buffer [7] << 1) + msb ;
// }
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT (& htim2 ) ;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
 setTimer2 (10) ;
 int index = 0;
 clearMatrix () ;
 while (1)
   {
     /* USER CODE END WHILE */
 	  if( timer2_flag == 1) {
 	   setTimer2 (1000) ;
 	   updateLEDMatrix ( index ++) ;
 	   if( index > 7) {
 	   index = 0;
 	   }
 	  }

     /* USER CODE BEGIN 3 */
   }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 1;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, EMM0_Pin|EMM1_Pin|DOT_Pin|LED_RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |EMM2_Pin|EMM3_Pin|EMM4_Pin|EMM5_Pin
                          |EMM6_Pin|EMM7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED7_0_Pin|LED7_1_Pin|LED7_2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|LED7_3_Pin|LED7_4_Pin|LED7_5_Pin
                          |LED7_6_Pin|ROW0_Pin|ROW1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : EMM0_Pin EMM1_Pin DOT_Pin LED_RED_Pin
                           EN0_Pin EN1_Pin EN2_Pin EN3_Pin
                           EMM2_Pin EMM3_Pin EMM4_Pin EMM5_Pin
                           EMM6_Pin EMM7_Pin */
  GPIO_InitStruct.Pin = EMM0_Pin|EMM1_Pin|DOT_Pin|LED_RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |EMM2_Pin|EMM3_Pin|EMM4_Pin|EMM5_Pin
                          |EMM6_Pin|EMM7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED7_0_Pin LED7_1_Pin LED7_2_Pin ROW2_Pin
                           ROW3_Pin ROW4_Pin ROW5_Pin ROW6_Pin
                           ROW7_Pin LED7_3_Pin LED7_4_Pin LED7_5_Pin
                           LED7_6_Pin ROW0_Pin ROW1_Pin */
  GPIO_InitStruct.Pin = LED7_0_Pin|LED7_1_Pin|LED7_2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|LED7_3_Pin|LED7_4_Pin|LED7_5_Pin
                          |LED7_6_Pin|ROW0_Pin|ROW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
