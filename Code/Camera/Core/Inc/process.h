/*
 * process.h
 *
 *  Created on: Nov 27, 2023
 *      Author: justin
 */

#ifndef INC_PROCESS_H_
#define INC_PROCESS_H_

#include "main.h"
#include "lcd.h"
#include "bsp_ov7725.h"
#include "bsp_sccb.h"
#include "xpt2046.h"
#include "CameraWithErrorCorrection.h"
#include "usart.h"

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;

void mode(int);

#endif /* INC_PROCESS_H_ */
