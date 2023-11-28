/*
 * process.c
 *
 *  Created on: Nov 26, 2023
 *      Author: justin
 */

#include "process.h"

/*
 * Splitting a string into an array of string
 *
 * @param src[] string
 * @param target[][SIZE_OF_ONE_MOVEMENT] an array of string
 * @return number of rows of listOfCommand[][SIZE_OF_ONE_MOVEMENT]
 */
int splitCharArray(char src[], char target[][SIZE_OF_ONE_MOVEMENT]) {
    int pos = 0;
    int index = 0;
    int num = 0;
    while (src[pos] != ENDING_CHAR) {
        if (src[pos] != DELIMETER) {
            target[index][num++] = src[pos];
        } else {
            target[index][num] = END_OF_CHAR;
            index++;
            num = 0;
        }
        pos++;
    }
    target[index][num] = END_OF_CHAR;
    index++;
    return index;
}

/*
 * Read input and transform it into list of commands
 *
 * @param input[] string of input
 * @param *size number of rows of listOfCommand[][SIZE_OF_ONE_MOVEMENT]
 * @param listOfCommand[][SIZE_OF_ONE_MOVEMENT] string that store different movements into seperated rows
 */
void ReadInput(char input[], int *size, char listOfCommand[][SIZE_OF_ONE_MOVEMENT]) {
	LCD_DrawString(0,16, "Not yet");
	HAL_UART_Receive(&huart1, input, 100, 0xFFFF);
	LCD_DrawString(0,0, input);
    (*size) = splitCharArray(input, listOfCommand);
}

/*
 * Perform one movement according to character array
 *
 * @param Movement[SIZE_OF_ONE_MOVEMENT] character array that store one command of movement
 */
void makeOneMovement(char Movement[]) {
	switch (Movement[0]) {
		case 'F':
			if (Movement[1] == '2')
				movement_F2();
			else if (Movement[1] == '\'')
				movement_aF();
			else
				movement_F();
			break;
		case 'R':
			if (Movement[1] == '2')
				movement_R2();
			else if (Movement[1] == '\'')
				movement_aR();
			else
				movement_R();
			break;
		case 'L':
			if (Movement[1] == '2')
				movement_L2();
			else if (Movement[1] == '\'')
				movement_aL();
			else
				movement_L();
			break;
		case 'B':
			if (Movement[1] == '2')
				movement_B2();
			else if (Movement[1] == '\'')
				movement_aB();
			else
				movement_B();
			break;
		case 'U':
			if (Movement[1] == '2')
				movement_U2();
			else if (Movement[1] == '\'')
				movement_aU();
			else
				movement_U();
			break;
		case 'D':
			if (Movement[1] == '2')
				movement_D2();
			else if (Movement[1] == '\'')
				movement_aD();
			else
				movement_D();
			break;
	}
}

/*
 * Controlling servos for performing different movements
 *
 * @param listOfCommand[][SIZE_OF_ONE_MOVEMENT] array that contains different movements
 * @param size number of rows of listOfCommand[][SIZE_OF_ONE_MOVEMENT]
 *
 */
void SolveTheCube(char listOfCommand[][SIZE_OF_ONE_MOVEMENT], int size) {
    for (int i=0; i<size; ++i)
        makeOneMovement(listOfCommand[i]);
}

void ScanCube(void) {
	for (uint8_t steps = 1; steps <= 6; steps++) {
		char signal_r;
		char signal_t = 'T';
		switch (steps) {
			// up
			case 1: {
				movement_scan_up();
				HAL_UART_Transmit(&huart1, &signal_t, 1, 0xFFFF); // ackonwledge Camera Board to capture image
				HAL_UART_Receive(&huart1, &signal_r, 1, 0xFFFF); // Camera Board finish capturing image
				movement_scan_up_r();
				break;
			}
			// north
			case 6: {
				movement_scan_north();
				HAL_UART_Transmit(&huart1, &signal_t, 1, 0xFFFF);
				HAL_UART_Receive(&huart1, &signal_r, 1, 0xFFFF);
				movement_scan_north_r();
				break;
			}
			// east
			case 2: {
				movement_scan_east();
				HAL_UART_Transmit(&huart1, &signal_t, 1, 0xFFFF);
				HAL_UART_Receive(&huart1, &signal_r, 1, 0xFFFF);
				movement_scan_east_r();
				break;
			}
			// south
			case 3: {
				movement_scan_south();
				HAL_UART_Transmit(&huart1, &signal_t, 1, 0xFFFF);
				HAL_UART_Receive(&huart1, &signal_r, 1, 0xFFFF);
				movement_scan_south_r();
				break;
			}
			// west
			case 5: {
				movement_scan_west();
				HAL_UART_Transmit(&huart1, &signal_t, 1, 0xFFFF);
				HAL_UART_Receive(&huart1, &signal_r, 1, 0xFFFF);
				movement_scan_west_r();
				break;
			}
			// down
			case 4: {
				movement_scan_down();
				HAL_UART_Transmit(&huart1, &signal_t, 1, 0xFFFF);
				HAL_UART_Receive(&huart1, &signal_r, 1, 0xFFFF);
				movement_scan_down_r();
				break;
			}
		}
	}
}

/*
 * Switching different modes of Rubik's Cube Solver
 *
 * Mode 1: Solving mode
 * Mode 2: Shuffling mode
 *
 * @param choice choice of mode
 */
void mode(uint8_t choice) {
	switch (choice) {
		case 1: {
			static char listOfCommand[100][SIZE_OF_ONE_MOVEMENT];
			char receive[100];
			char stage, signal;
			int size;
			stage = '1';
			HAL_UART_Transmit(&huart1, &stage, 1, 0xFFFF);
			insert_cube();
			stage = '2';
			HAL_UART_Transmit(&huart1, &stage, 1, 0xFFFF);
			ScanCube();
			stage = '3';
			HAL_UART_Transmit(&huart1, &stage, 1, 0xFFFF);
			ReadInput(receive, &size, listOfCommand);
			SolveTheCube(listOfCommand, size);
			remove_cube();
			stage = '4';
			HAL_UART_Transmit(&huart1, &stage, 1, 0xFFFF);
			HAL_UART_Receive(&huart1, &signal, 1, 0xFFFF);
			break;
		}
		case 2: {
			char listOfCommand[100][SIZE_OF_ONE_MOVEMENT];
			char receive[100];
			char stage, signal;
			int size;
			stage = '1';
			HAL_UART_Transmit(&huart1, &stage, 1, 0xFFFF);
			insert_cube();
			stage = '2';
			HAL_UART_Transmit(&huart1, &stage, 1, 0xFFFF);
			ReadInput(receive, &size, listOfCommand);
			SolveTheCube(listOfCommand, size);
			remove_cube();
			stage = '3';
			HAL_UART_Transmit(&huart1, &stage, 1, 0xFFFF);
			HAL_UART_Receive(&huart1, &signal, 1, 0xFFFF);
			break;
		}
		default:
	}
}
