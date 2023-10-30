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

#define CENTRE_DEGREE 	94
#define LEFT_90 		35
#define RIGHT_90 		151
#define PULL_DEGREE		00
#define PUSH_DEGREE 	00

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

void servo_reset(void);
void centre_0(servos);
void clockwise_90(servos);
void anticlockwise_90(servos);
void servo_pull(servos);
void servo_push(servos);

#endif /* INC_SERVO_H_ */
