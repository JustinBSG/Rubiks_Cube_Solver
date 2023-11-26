/*
 * process.c
 *
 *  Created on: Nov 27, 2023
 *      Author: justin
 */

#include "process.h"

void mode(int choice) {
	switch (choice) {
		case 1: {
			while (1) {
				char signal;
				HAL_UART_Receive(&huart1, &signal, 1, 0xFFFF);
				switch (signal) {
					case '1': {
						char message_r[3], message_t = 'T';
						HAL_UART_Receive(&huart2, message_r, sizeof(message_r), 0xFFFF);
						HAL_UART_Transmit(&huart1, &message_t, 1, 0xFFFF);
						break;
					}
					case '2': {
						uint8_t face = 1;
						while (face <= 6) {
							// receive signal from Control Board
							// show result on LCD
							// receive message from PC
								// correct then
									// transmit signal to Control Board
								// wrong then
									// correct it and go back to receceive message from PC
							face++;
						}
						// transmit capture result to PC
						break;
					}
					case '3': {
						char message_r[100];
						HAL_UART_Receive(&huart2, message_r, sizeof(message_r), 0xFFFF);
						HAL_UART_Transmit(&huart1, message_r, sizeof(message_r), 0xFFFF);
						break;
					}
					case '4': {
						char message_r[3], message_t = 'T';
						HAL_UART_Receive(&huart2, message_r, sizeof(message_r), 0xFFFF);
						HAL_UART_Transmit(&huart1, &message_t, 1, 0xFFFF);
						break;
					}
				}
				if (signal == '4')
					break;
			}
			break;
		}
		case 2: {
			while (1) {
				char signal;
				HAL_UART_Receive(&huart1, &signal, 1, 0xFFFF);
				switch (signal) {
					case '1': {
						char message_r[3], message_t = 'T';
						HAL_UART_Receive(&huart2, message_r, sizeof(message_r), 0xFFFF);
						HAL_UART_Transmit(&huart1, &message_t, 1, 0xFFFF);
						break;
					}
					case '2': {
						char message_r[100];
						HAL_UART_Receive(&huart2, message_r, sizeof(message_r), 0xFFFF);
						HAL_UART_Transmit(&huart1, message_r, sizeof(message_r), 0xFFFF);
						break;
					}
					case '3': {
						char message_r[3], message_t = 'T';
						HAL_UART_Receive(&huart2, message_r, sizeof(message_r), 0xFFFF);
						HAL_UART_Transmit(&huart1, &message_t, 1, 0xFFFF);
						break;
					}
				}
				if (signal == '3')
					break;
			}
			break;
		}
	}
}
