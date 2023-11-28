/*
 * servo.h
 *
 *  Created on: Oct 27, 2023
 *      Author: justin
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_

#include "main.h"
#include "tim.h"
#include "usart.h"

#define DELAY_TIME_90 	500
#define DELAY_TIME_180 	900
#define DELAY_TIME_P	500
#define DELAY_TIME_sP	200

#define CENTRE_DEGREE_1 	95
#define LEFT_90_1 			37
#define RIGHT_90_1 			153
#define CENTRE_DEGREE_2 	88
#define LEFT_90_2 			29
#define RIGHT_90_2 			145
#define CENTRE_DEGREE_3 	92
#define LEFT_90_3 			31
#define RIGHT_90_3 			150
#define CENTRE_DEGREE_4 	94
#define LEFT_90_4 			36
#define RIGHT_90_4 			153
#define PULL_DEGREE_1		30	// north
#define PUSH_DEGREE_1 		100
#define PULL_DEGREE_2		30	// east
#define PUSH_DEGREE_2 		100
#define PULL_DEGREE_3		30	// south
#define PUSH_DEGREE_3 		100
#define PULL_DEGREE_4		30	// west
#define PUSH_DEGREE_4 		100

extern UART_HandleTypeDef huart1;

typedef enum {
	north_front = 1,
	north_back,
	east_front,
	east_back,
	south_front,
	south_back,
	west_front,
	west_back
} servos;

void servo_init(void);
void insert_cube(void);
void remove_cube(void);
void centre_0(servos);
void clockwise_90(servos);
void anticlockwise_90(servos);
void servo_pull(servos);
void servo_push(servos);

#endif /* INC_SERVO_H_ */
