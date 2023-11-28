/*
 * process.c
 *
 *  Created on: Nov 27, 2023
 *      Author: justin
 */

#include "process.h"
#include "CameraWithErrorCorrection.h"

extern uint8_t Ov7725_vsync;

void mode(int choice) {
	switch (choice) {
		case 1: {
			while (1) {
				char signal;
				char AllFaces[55];
				AllFaces[54] = '\0';
				HAL_UART_Receive(&huart1, &signal, 1, 0xFFFF);
				switch (signal) {
					case '1': {
						char message_r[2], message_t = 'T';
						HAL_UART_Transmit(&huart3, &signal, 1, 0xFFFF);
						LCD_DrawChar(0,0,signal);
						HAL_UART_Receive(&huart3, message_r, sizeof(message_r), 0xFFFF);	// ok
						HAL_UART_Transmit(&huart1, &message_t, 1, 0xFFFF);
						break;
					}
					case '2': {
						uint8_t face = 0;
						HAL_UART_Transmit(&huart3, &signal, 1, 0xFFFF);
						while (face < 6) {
							// receive signal from Control Board
							char message_r, SquareOfOneFace[9], message_t = 'T';
							HAL_UART_Receive(&huart1, &message_r, 1, 0xFFFF);
							// scan the cube
							while(Ov7725_Init() != SUCCESS);
							Ov7725_vsync = 0;
							HAL_Delay(1000);
							while(1) {
								if (Ov7725_vsync == 2)
									{
										FIFO_PREPARE;
										ReadSquare(SquareOfOneFace);
										break;
										// ImagDisp();
										Ov7725_vsync = 0;
									}
							}
							// show result on LCD
							LCD_Clear ( 0, 0, 240, 320, GREY );
							printFace(SquareOfOneFace);
							while (1) {
								// receive message from PC
								char correctionMessage[7];
								printFace(SquareOfOneFace);
								HAL_UART_Receive(&huart3, correctionMessage, sizeof(correctionMessage), 0xFFFF);
								if (stringCompare(correctionMessage, "confirm", 7) == 0) {	// correct then
									writeDataIntoAllFaces(AllFaces, SquareOfOneFace,face);	// write one face data into all face data
									HAL_UART_Transmit(&huart1, &message_t, 1, 0xFFFF);		// transmit signal to Control Board
									face++;
									break;
								} else {	// wrong then
									SquareOfOneFace[correctionMessage[0]-'1'] = (char) ((int) correctionMessage[1] - 32);// correct it and go back to receceive message from PC
								}
							}
						}
						HAL_UART_Transmit(&huart3, AllFaces, sizeof(AllFaces), 0xFFFF);		// transmit capture result to PC
						break;
					}
					case '3': {
						char message_r[100];
						LCD_Clear( 0, 0, 240, 320, GREY );
						LCD_DrawString(0,0,"123");
						HAL_UART_Transmit(&huart3, &signal, 1, 0xFFFF);
						LCD_DrawString(0,8,"123");
						HAL_UART_Receive(&huart3, message_r, sizeof(message_r), 0xFFFF);
						LCD_DrawString(0,16,"123");
						HAL_UART_Transmit(&huart1, message_r, sizeof(message_r), 0xFFFF);
						LCD_DrawString(0,32,"123");
						break;
					}
					case '4': {
						char message_r[2], message_t = 'T';
						HAL_UART_Transmit(&huart3, &signal, 1, 0xFFFF);
						HAL_UART_Receive(&huart3, message_r, sizeof(message_r), 0xFFFF);
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
						char message_r[2], message_t = 'T';
						HAL_UART_Receive(&huart3, message_r, sizeof(message_r), 0xFFFF);
						HAL_UART_Transmit(&huart1, &message_t, 1, 0xFFFF);
						break;
					}
					case '2': {
						char message_r[100];
						HAL_UART_Receive(&huart3, message_r, sizeof(message_r), 0xFFFF);
						HAL_UART_Transmit(&huart1, message_r, sizeof(message_r), 0xFFFF);
						break;
					}
					case '3': {
						char message_r[2], message_t = 'T';
						HAL_UART_Receive(&huart3, message_r, sizeof(message_r), 0xFFFF);
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
