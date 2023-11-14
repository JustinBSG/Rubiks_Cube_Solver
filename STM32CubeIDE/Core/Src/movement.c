/*
 * movement.c
 *
 *  Created on: Nov 5, 2023
 *      Author: justin
 */

#include "movement.h"

// Number of Delay: 4
void movement_F(void) {
	clockwise_90(south_front);
	HAL_Delay(DELAY_TIME_90);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(south_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 4
void movement_aF(void) {
	anticlockwise_90(south_front);
	HAL_Delay(DELAY_TIME_90);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(south_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 4
void movement_R(void) {
	clockwise_90(east_front);
	HAL_Delay(DELAY_TIME_90);
	servo_pull(east_front);
	HAL_Delay(DELAY_TIME_P);
	centre_0(east_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_front);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 4
void movement_aR(void) {
	anticlockwise_90(east_front);
	HAL_Delay(DELAY_TIME_90);
	servo_pull(east_front);
	HAL_Delay(DELAY_TIME_P);
	centre_0(east_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_front);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 4
void movement_L(void) {
	clockwise_90(west_front);
	HAL_Delay(DELAY_TIME_90);
	servo_pull(west_front);
	HAL_Delay(DELAY_TIME_P);
	centre_0(west_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(west_front);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 4
void movement_aL(void) {
	anticlockwise_90(west_front);
	HAL_Delay(DELAY_TIME_90);
	servo_pull(west_front);
	HAL_Delay(DELAY_TIME_P);
	centre_0(west_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(west_front);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 4
void movement_B(void) {
	clockwise_90(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_pull(north_front);
	HAL_Delay(DELAY_TIME_P);
	centre_0(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_front);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 4
void movement_aB(void) {
	anticlockwise_90(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_pull(north_front);
	HAL_Delay(DELAY_TIME_P);
	centre_0(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_front);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 13
void movement_U(void) {
	servo_pull(east_back);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(south_front);
	anticlockwise_90(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
	servo_pull(north_back);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(north_front);
	centre_0(south_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(east_front);
	HAL_Delay(DELAY_TIME_90);
	servo_pull(east_back);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	anticlockwise_90(south_front);
	clockwise_90(north_front);
	centre_0(east_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
	servo_pull(north_back);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(south_front);
	centre_0(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 13
void movement_aU(void) {
	servo_pull(east_back);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(south_front);
	anticlockwise_90(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
	servo_pull(north_back);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(north_front);
	centre_0(south_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
	anticlockwise_90(east_front);
	HAL_Delay(DELAY_TIME_90);
	servo_pull(east_back);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	anticlockwise_90(south_front);
	clockwise_90(north_front);
	centre_0(east_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
	servo_pull(north_back);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(south_front);
	centre_0(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 13
void movement_D(void) {
	servo_pull(east_back);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(south_front);
	anticlockwise_90(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
	servo_pull(north_back);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(north_front);
	centre_0(south_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(west_front);
	HAL_Delay(DELAY_TIME_90);
	servo_pull(east_back);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	anticlockwise_90(south_front);
	clockwise_90(north_front);
	centre_0(west_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
	servo_pull(north_back);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(south_front);
	centre_0(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 13
void movement_aD(void) {
	servo_pull(east_back);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(south_front);
	anticlockwise_90(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
	servo_pull(north_back);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(north_front);
	centre_0(south_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
	anticlockwise_90(west_front);
	HAL_Delay(DELAY_TIME_90);
	servo_pull(east_back);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	anticlockwise_90(south_front);
	clockwise_90(north_front);
	centre_0(west_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
	servo_pull(north_back);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(south_front);
	centre_0(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 8
void movement_F2(void) {
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	anticlockwise_90(south_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(south_front);
	HAL_Delay(DELAY_TIME_180);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(south_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 8
void movement_aF2(void) {
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(south_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
	anticlockwise_90(south_front);
	HAL_Delay(DELAY_TIME_180);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(south_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 8
void movement_R2(void) {
	servo_pull(east_back);
	HAL_Delay(DELAY_TIME_P);
	anticlockwise_90(east_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(east_front);
	HAL_Delay(DELAY_TIME_180);
	servo_pull(east_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(east_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 8
void movement_aR2(void) {
	servo_pull(east_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(east_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	HAL_Delay(DELAY_TIME_P);
	anticlockwise_90(east_front);
	HAL_Delay(DELAY_TIME_180);
	servo_pull(east_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(east_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 8
void movement_L2(void) {
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	anticlockwise_90(west_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(west_front);
	HAL_Delay(DELAY_TIME_180);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(west_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 8
void movement_aL2(void) {
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(west_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
	anticlockwise_90(west_front);
	HAL_Delay(DELAY_TIME_180);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(west_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 8
void movement_B2(void) {
	servo_pull(north_back);
	HAL_Delay(DELAY_TIME_P);
	anticlockwise_90(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(north_front);
	HAL_Delay(DELAY_TIME_180);
	servo_pull(north_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 8
void movement_aB2(void) {
	servo_pull(north_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	HAL_Delay(DELAY_TIME_P);
	anticlockwise_90(north_front);
	HAL_Delay(DELAY_TIME_180);
	servo_pull(north_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 17
void movement_U2(void) {
	servo_pull(east_back);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(south_front);
	anticlockwise_90(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
	servo_pull(north_back);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(north_front);
	centre_0(south_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
	servo_pull(east_back);
	HAL_Delay(DELAY_TIME_P);
	anticlockwise_90(east_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(east_front);
	HAL_Delay(DELAY_TIME_180);
	servo_pull(east_back);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	anticlockwise_90(south_front);
	clockwise_90(north_front);
	centre_0(east_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
	servo_pull(north_back);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(south_front);
	centre_0(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 17
void movement_aU2(void) {
	servo_pull(east_back);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(south_front);
	anticlockwise_90(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
	servo_pull(north_back);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(north_front);
	centre_0(south_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
	servo_pull(east_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(east_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	HAL_Delay(DELAY_TIME_P);
	anticlockwise_90(east_front);
	HAL_Delay(DELAY_TIME_180);
	servo_pull(east_back);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	anticlockwise_90(south_front);
	clockwise_90(north_front);
	centre_0(east_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
	servo_pull(north_back);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(south_front);
	centre_0(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 17
void movement_D2(void) {
	servo_pull(east_back);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(south_front);
	anticlockwise_90(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
	servo_pull(north_back);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(north_front);
	centre_0(south_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	anticlockwise_90(west_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(west_front);
	HAL_Delay(DELAY_TIME_180);
	servo_pull(east_back);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	anticlockwise_90(south_front);
	clockwise_90(north_front);
	centre_0(west_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
	servo_pull(north_back);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(south_front);
	centre_0(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 17
void movement_aD2(void) {
	servo_pull(east_back);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(south_front);
	anticlockwise_90(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
	servo_pull(north_back);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(north_front);
	centre_0(south_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(west_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
	anticlockwise_90(west_front);
	HAL_Delay(DELAY_TIME_180);
	servo_pull(east_back);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	anticlockwise_90(south_front);
	clockwise_90(north_front);
	centre_0(west_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
	servo_pull(north_back);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(south_front);
	centre_0(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_90);
}

// Number of Delay: 6
void movement_X(void) {
	servo_pull(north_back);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(east_front);
	anticlockwise_90(west_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
	servo_pull(east_back);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(west_front);
	centre_0(east_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 6
void movement_aX(void) {
	servo_pull(north_back);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(west_front);
	anticlockwise_90(east_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
	servo_pull(east_back);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(east_front);
	centre_0(west_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 18
void movement_Y(void) {
	movement_X();
	movement_aZ();
	movement_aX();
}

// Number of Delay: 18
void movement_aY(void) {
	movement_X();
	movement_Z();
	movement_aX();
}

// Number of Delay: 6
void movement_Z(void) {
	servo_pull(east_back);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	clockwise_90(south_front);
	anticlockwise_90(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
	servo_pull(north_back);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(south_front);
	centre_0(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 6
void movement_aZ(void) {
	servo_pull(east_back);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	anticlockwise_90(south_front);
	clockwise_90(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
	servo_pull(north_back);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(south_front);
	centre_0(north_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 4
void movement_M(void) {
	clockwise_90(east_front);
	anticlockwise_90(west_front);
	HAL_Delay(DELAY_TIME_90);
	servo_pull(north_back);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(east_front);
	centre_0(west_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 4
void movement_aM(void) {
	anticlockwise_90(east_front);
	clockwise_90(west_front);
	HAL_Delay(DELAY_TIME_90);
	servo_pull(north_back);
	servo_pull(south_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(east_front);
	centre_0(west_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(north_back);
	servo_push(south_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 14
void movement_E(void) {
	movement_Z();
	movement_M();
	movement_aZ();
}

// Number of Delay: 14
void movement_aE(void) {
	movement_aZ();
	movement_M();
	movement_Z();
}

// Number of Delay: 4
void movement_S(void) {
	clockwise_90(north_front);
	anticlockwise_90(south_front);
	HAL_Delay(DELAY_TIME_90);
	servo_pull(east_back);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(north_front);
	centre_0(south_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 4
void movement_aS(void) {
	anticlockwise_90(north_front);
	clockwise_90(south_front);
	HAL_Delay(DELAY_TIME_90);
	servo_pull(east_back);
	servo_pull(west_back);
	HAL_Delay(DELAY_TIME_P);
	centre_0(north_front);
	centre_0(south_front);
	HAL_Delay(DELAY_TIME_90);
	servo_push(east_back);
	servo_push(west_back);
	HAL_Delay(DELAY_TIME_P);
}

// Number of Delay: 31
void movement_u(void) {
	movement_D();
	movement_Y();
}

// Number of Delay: 31
void movement_au(void) {
	movement_aD();
	movement_aY();
}

// Number of Delay: 10
void movement_l(void) {
	movement_R();
	movement_aX();
}

// Number of Delay: 10
void movement_al(void) {
	movement_aR();
	movement_X();
}

// Number of Delay: 10
void movement_f(void) {
	movement_B();
	movement_Z();
}

// Number of Delay: 10
void movement_af(void) {
	movement_aB();
	movement_aZ();
}

// Number of Delay: 10
void movement_r(void) {
	movement_L();
	movement_X();
}

// Number of Delay: 10
void movement_ar(void) {
	movement_aL();
	movement_aX();
}

// Number of Delay: 10
void movement_b(void) {
	movement_F();
	movement_aX();
}

// Number of Delay: 10
void movement_ab(void) {
	movement_aF();
	movement_X();
}

// Number of Delay: 31
void movement_d(void) {
	movement_U();
	movement_aY();
}

// Number of Delay: 31
void movement_ad(void) {
	movement_aU();
	movement_Y();
}
