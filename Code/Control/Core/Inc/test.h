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

extern uint8_t flag, start;
extern uint32_t last_tick;
extern UART_HandleTypeDef huart1;

void test_servo_movement(void);
void test_communication_two_boards(void);
void test_commands(void);

#endif /* INC_TEST_H_ */
