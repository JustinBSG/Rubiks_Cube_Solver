/*
 * process.h
 *
 *  Created on: Nov 26, 2023
 *      Author: justin
 */

#ifndef INC_PROCESS_H_
#define INC_PROCESS_H_

#include "main.h"
#include "movement.h"
#include "lcd.h"
#include "usart.h"

#define ENDING_CHAR             '#'
#define END_OF_CHAR             '\0'
#define DELIMETER               ' '
#define SIZE_OF_ONE_MOVEMENT    3

extern UART_HandleTypeDef huart1;
extern uint8_t start;

int splitCharArray(char*, char(*)[3]);
void ReadInput(char*, int*, char(*)[3]);
void makeOneMovement(char*);
void SolveTheCube(char(*)[3], int);
void ScanCube(void);
void mode(uint8_t);

#endif /* INC_PROCESS_H_ */
