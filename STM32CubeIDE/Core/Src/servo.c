/*
 * servo.c
 *
 *  Created on: Oct 27, 2023
 *      Author: justin
 */

#include "servo.h"

void servo_reset(void) {

}

void centre_0(servos servo) {
	if (servo%2 != 0) {
		uint8_t target = servo/2+1;
		switch (target) {
			case 1:
				TIM3->CCR1 = CENTRE_DEGREE;
				break;
			case 2:
				TIM3->CCR2 = CENTRE_DEGREE;
				break;
			case 3:
				TIM3->CCR3 = CENTRE_DEGREE;
				break;
			case 4:
				TIM3->CCR4 = CENTRE_DEGREE;
				break;
		}
	}
}

void clockwise_90(servos servo) {
	if (servo%2 != 0) {
		uint8_t target = servo/2+1;
		switch (target) {
			case 1:
				TIM3->CCR1 = RIGHT_90;
				break;
			case 2:
				TIM3->CCR2 = RIGHT_90;
				break;
			case 3:
				TIM3->CCR3 = RIGHT_90;
				break;
			case 4:
				TIM3->CCR4 = RIGHT_90;
				break;
		}
	}
}

void anticlockwise_90(servos servo) {
	if (servo%2 != 0) {
		uint8_t target = servo/2+1;
		switch (target) {
			case 1:
				TIM3->CCR1 = LEFT_90;
				break;
			case 2:
				TIM3->CCR2 = LEFT_90;
				break;
			case 3:
				TIM3->CCR3 = LEFT_90;
				break;
			case 4:
				TIM3->CCR4 = LEFT_90;
				break;
		}
	}
}

void servo_pull(servos servo) {
	if (servo%2 == 0) {
		uint8_t target = servo/2;
		switch (target) {
			case 1:
				TIM4->CCR1 = PULL_DEGREE;
				break;
			case 2:
				TIM4->CCR2 = PULL_DEGREE;
				break;
			case 3:
				TIM4->CCR3 = PULL_DEGREE;
				break;
			case 4:
				TIM4->CCR4 = PULL_DEGREE;
				break;
		}
	}
}

void servo_push(servos servo) {
	if (servo%2 == 0) {
		uint8_t target = servo/2;
		switch (target) {
			case 1:
				TIM4->CCR1 = PUSH_DEGREE;
				break;
			case 2:
				TIM4->CCR2 = PUSH_DEGREE;
				break;
			case 3:
				TIM4->CCR3 = PUSH_DEGREE;
				break;
			case 4:
				TIM4->CCR4 = PUSH_DEGREE;
				break;
		}
	}
}
