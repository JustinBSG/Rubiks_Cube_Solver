/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "tim.h"
#include "gpio.h"
#include "fsmc.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lcd.h"
#include "servo.h"
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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_FSMC_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */
  LCD_INIT();
  LCD_DrawString(0, 0, "PSC: ");
  LCD_DrawString(0, HEIGHT_EN_CHAR, "ARR: ");
  LCD_DrawString(0, 2*HEIGHT_EN_CHAR, "CCR1: ");
//  LCD_DrawString(0, 3*HEIGHT_EN_CHAR, "CCR2: ");

  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4);
  servo_init();
  uint8_t flag_1 = 0, flag_2 = 0;
  uint8_t pre_state_1 = 0, pre_state_2 = 0;
  uint16_t last_tick = 0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == SET && pre_state_1 == 0) {
		  pre_state_1 = 1;
	  } else if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == RESET && pre_state_1 == 1) {
		  flag_1++;
		  if (flag_1 == 4)
			  flag_1 = 0;
//		  TIM3->CCR1 += 5;
		  pre_state_1 = 0;
	  }

//	  if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == SET && pre_state_2 == 0) {
//		  pre_state_2 = 1;
//	  } else if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == RESET && pre_state_2 == 1) {
//		  flag_2++;
//		  if (flag_2 == 4)
//			  flag_2 = 0;
//		  pre_state_2 = 0;
//	  }

	  if (flag_1 == 0)
		  centre_0(west_front);
	  else if (flag_1 == 1)
		  clockwise_90(west_front);
	  else if (flag_1 == 2)
		  centre_0(west_front);
	  else if (flag_1 == 3)
		  anticlockwise_90(west_front);

//	  if (flag_2 == 0)
//		  clockwise_90(east_front);
//	  else if (flag_2 == 1)
//		  centre_0(east_front);
//	  else if (flag_2 == 2)
//		  anticlockwise_90(east_front);
//	  else if (flag_2 == 3)
//		  centre_0(east_front);

	  char PSC[6];
	  char ARR[6];
	  char CCR1[6];
	  char CCR2[6];

	  sprintf(PSC, "%d", TIM3->PSC+1);
	  sprintf(ARR, "%d", TIM3->ARR+1);
	  sprintf(CCR1, "%d ", TIM3->CCR1);
//	  sprintf(CCR2, "%d ", TIM3->CCR2);
	  LCD_DrawString(7*WIDTH_EN_CHAR, 0, PSC);
	  LCD_DrawString(7*WIDTH_EN_CHAR, HEIGHT_EN_CHAR, ARR);
	  LCD_DrawString(7*WIDTH_EN_CHAR, 2*HEIGHT_EN_CHAR, CCR1);
	  LCD_DrawString(7*WIDTH_EN_CHAR, 3*HEIGHT_EN_CHAR, CCR2);

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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
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

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
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
