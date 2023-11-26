/*
 * servo.c
 *
 *  Created on: Oct 27, 2023
 *      Author: justin
 */

#include "servo.h"

GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

void servo_init(void) {
	for (uint8_t i = 1; i <= 4; i++) {
		servo_pull(i*2);
		centre_0(i*2-1);
	}
	HAL_Delay(DELAY_TIME_P);
	for (uint8_t i = 1; i <= 4; i++)
		servo_push(i*2);
}

void insert_cube(void) {
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_sP);
	servo_pull(east_back);
	HAL_Delay(DELAY_TIME_P);

	char stage;
	HAL_UART_Receive(&huart1, &stage, 1, 0xFFFF);
	for (uint8_t i = 1; i <= 4; i++)
		servo_push(i*2);
	HAL_Delay(DELAY_TIME_P);
}

void remove_cube(void) {
	servo_pull(west_back);
	servo_pull(south_back);
	servo_pull(east_back);
	HAL_Delay(DELAY_TIME_P);
}

void centre_0(servos servo) {
	if (servo%2 != 0) {
		uint8_t target = servo/2+1;
		switch (target) {
			case 1:
				TIM3->CCR1 = CENTRE_DEGREE_1;
				break;
			case 2:
				TIM3->CCR2 = CENTRE_DEGREE_2;
				break;
			case 3:
				TIM3->CCR3 = CENTRE_DEGREE_3;
				break;
			case 4:
				TIM3->CCR4 = CENTRE_DEGREE_4;
				break;
		}
	}
}

void clockwise_90(servos servo) {
	if (servo%2 != 0) {
		uint8_t target = servo/2+1;
		switch (target) {
			case 1:
				TIM3->CCR1 = RIGHT_90_1;
				break;
			case 2:
				TIM3->CCR2 = RIGHT_90_2;
				break;
			case 3:
				TIM3->CCR3 = RIGHT_90_3;
				break;
			case 4:
				TIM3->CCR4 = RIGHT_90_4;
				break;
		}
	}
}

void anticlockwise_90(servos servo) {
	if (servo%2 != 0) {
		uint8_t target = servo/2+1;
		switch (target) {
			case 1:
				TIM3->CCR1 = LEFT_90_1;
				break;
			case 2:
				TIM3->CCR2 = LEFT_90_2;
				break;
			case 3:
				TIM3->CCR3 = LEFT_90_3;
				break;
			case 4:
				TIM3->CCR4 = LEFT_90_4;
				break;
		}
	}
}

void servo_pull(servos servo) {
	if (servo%2 == 0) {
		uint8_t target = servo/2;
		switch (target) {
			case 1:
				TIM4->CCR1 = PULL_DEGREE_1;
				break;
			case 2:
				TIM2->CCR3 = PULL_DEGREE_2;
				break;
			case 3:
				TIM4->CCR3 = PULL_DEGREE_3;
				break;
			case 4:
				TIM4->CCR4 = PULL_DEGREE_4;
				break;
		}
	}
}

void servo_push(servos servo) {
	if (servo%2 == 0) {
		uint8_t target = servo/2;
		switch (target) {
			case 1:
				TIM4->CCR1 = PUSH_DEGREE_1;
				break;
			case 2:
				TIM2->CCR3 = PUSH_DEGREE_2;
				break;
			case 3:
				TIM4->CCR3 = PUSH_DEGREE_3;
				break;
			case 4:
				TIM4->CCR4 = PUSH_DEGREE_4;
				break;
		}
	}
}
