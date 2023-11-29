/*
 * test.h
 *
 *  Created on: Nov 26, 2023
 *      Author: justin
 */

#ifndef INC_TEST_H_
#define INC_TEST_H_

#include "main.h"
#include "lcd.h"
#include "movement.h"
#include "usart.h"
#include "process.h"

extern UART_HandleTypeDef huart1;

//void test_servo_movement(void);
//void test_communication_two_boards(void);
//void test_commands(void);
void test_scanCube(uint8_t*);

#endif /* INC_TEST_H_ */
