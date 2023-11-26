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
#include <stdio.h>
#include "lcd.h"
#include "servo.h"
#include "movement.h"
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
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);

  LCD_INIT();
  uint8_t flag = 4, start = 0;
  uint32_t last_tick = 0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  char string[20];
	  sprintf(string, "It is now flag %d.", flag);
	  LCD_DrawString(0, HEIGHT_EN_CHAR*8, string);
	  display_servo_info(&last_tick);
	  if (start <= 1)
		  insert_cube(&start);
	  else {
		  if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == SET) {
			  switch (flag) {
			  	  case 0:
			  		  movement_F();
			  		  movement_aF();
			  		  flag++;
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
			  		  break;
			  	  case 1:
			  		  movement_R();
					  movement_aR();
					  flag++;
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
					  break;
			  	  case 2:
			  		  movement_L();
					  movement_aL();
					  flag++;
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
					  break;
			  	  case 3:
			  		  movement_B();
					  movement_aB();
					  flag++;
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
					  break;
			  	  case 4:
			  		  movement_U();
					  movement_aU();
					  flag++;
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
					  break;
			  	  case 5:
			  		  movement_D();
					  movement_aD();
					  flag++;
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
					  break;
			  	  case 6:
			  		  movement_X();
					  movement_aX();
					  flag++;
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
					  break;
			  	  case 7:
			  		  movement_Y();
					  movement_aY();
					  flag++;
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
					  break;
			  	  case 8:
			  		  movement_Z();
					  movement_aZ();
					  flag++;
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
					  break;
			  	  case 9:
			  		  movement_M();
					  movement_aM();
					  flag++;
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
					  break;
			  	  case 10:
			  		  movement_E();
					  movement_aE();
					  flag++;
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
					  break;
			  	  case 11:
			  		  movement_S();
					  movement_aS();
					  flag++;
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
					  break;
			  	  case 12:
			  		  movement_u();
					  movement_au();
					  flag++;
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
					  break;
			  	  case 13:
			  		  movement_l();
					  movement_al();
					  flag++;
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
					  break;
			  	  case 14:
			  		  movement_f();
					  movement_af();
					  flag++;
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
					  break;
			  	  case 15:
			  		  movement_r();
					  movement_ar();
					  flag++;
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
					  break;
			  	  case 16:
			  		  movement_b();
					  movement_ab();
					  flag++;
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
					  break;
			  	  case 17:
			  		  movement_d();
					  movement_ad();
					  flag++;
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
					  break;
			  	  case 18:
			  		  movement_F2();
					  movement_aF2();
					  flag++;
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
					  break;
			  	  case 19:
			  		  movement_R2();
					  movement_aR2();
					  flag++;
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
					  break;
			  	  case 20:
			  		  movement_L2();
					  movement_aL2();
					  flag++;
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
					  break;
			  	  case 21:
			  		  movement_B2();
					  movement_aB2();
					  flag++;
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
					  break;
			  	  case 22:
			  		  movement_U2();
					  movement_aU2();
					  flag++;
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
					  break;
			  	  case 23:
			  		  movement_D2();
					  movement_aD2();
					  remove_cube();
					  flag++;
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
					  break;
			  	  case 100:
			  		  servo_pull(north_back);
			  		  servo_pull(south_back);
			  		  HAL_Delay(DELAY_TIME_P);
			  		  clockwise_90(west_front);
			  		  anticlockwise_90(east_front);
			  		  HAL_Delay(DELAY_TIME_90);
			  		  LCD_Clear (0, 0, 240, 320, BACKGROUND);
			  		  flag++;
			  		  break;
			  	  default:
			  		  return 0;
			  }
		  }
	  }
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
