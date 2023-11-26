/*
 * test.c
 *
 *  Created on: Nov 26, 2023
 *      Author: justin
 */

#include "test.h"

void test_communication_two_boards(void) {
	char test_receive[10] = "";
	char test_transmit[10] = "123456789";
	LCD_DrawString(0, 0, test_transmit);
	HAL_UART_Transmit(&huart1, test_transmit, sizeof(test_transmit), 0xFFFF);
	LCD_DrawString(0, HEIGHT_EN_CHAR, "Transmit Success!!!");
	HAL_Delay(500);
	HAL_UART_Receive(&huart1, test_receive, sizeof(test_receive), 0xFFFF);
	LCD_DrawString(0, HEIGHT_EN_CHAR*2, test_receive);

}
