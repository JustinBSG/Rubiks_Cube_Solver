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
    (*size) = splitCharArray(input, listOfCommand);
}

/*
 * Perform one movement according to character array
 *
 * @param Movement[SIZE_OF_ONE_MOVEMENT] character array that store one command of movement
 */
void makeOneMovement(char Movement[SIZE_OF_ONE_MOVEMENT]) {
	switch (Movement[0]) {
		case 'F':
			if (Movement[2] != '\0')
				movement_aF2();
			else if (Movement[1] == '\0' && Movement[2] == '\0')
				movement_F();
			else if (Movement[1] == '2')
				movement_F2();
			else
				movement_aF();
			break;
		case 'R':
			if (Movement[2] != '\0')
				movement_aR2();
			else if (Movement[1] == '\0' && Movement[2] == '\0')
				movement_R();
			else if (Movement[1] == '2')
				movement_R2();
			else
				movement_aR();
			break;
		case 'L':
			if (Movement[2] != '\0')
				movement_aL2();
			else if (Movement[1] == '\0' && Movement[2] == '\0')
				movement_L();
			else if (Movement[1] == '2')
				movement_L2();
			else
				movement_aL();
			break;
		case 'B':
			if (Movement[2] != '\0')
				movement_aB2();
			else if (Movement[1] == '\0' && Movement[2] == '\0')
				movement_B();
			else if (Movement[1] == '2')
				movement_B2();
			else
				movement_aB();
			break;
		case 'U':
			if (Movement[2] != '\0')
				movement_aU2();
			else if (Movement[1] == '\0' && Movement[2] == '\0')
				movement_U();
			else if (Movement[1] == '2')
				movement_U2();
			else
				movement_aU();
			break;
		case 'D':
			if (Movement[2] != '\0')
				movement_aD2();
			else if (Movement[1] == '\0' && Movement[2] == '\0')
				movement_D();
			else if (Movement[1] == '2')
				movement_D2();
			else
				movement_aD();
			break;
		case 'X':
			if (Movement[2] != '\0') {
				movement_aX();
				movement_aX();
			} else if (Movement[1] == '\0' && Movement[2] == '\0')
				movement_X();
			else if (Movement[1] == '2') {
				movement_X();
				movement_X();
			} else
				movement_aX();
			break;
		case 'Y':
			if (Movement[2] != '\0') {
				movement_aY();
				movement_aY();
			} else if (Movement[1] == '\0' && Movement[2] == '\0')
				movement_Y();
			else if (Movement[1] == '2') {
				movement_Y();
				movement_Y();
			} else
				movement_aY();
			break;
		case 'Z':
			if (Movement[2] != '\0') {
				movement_aZ();
				movement_aZ();
			} else if (Movement[1] == '\0' && Movement[2] == '\0')
				movement_Z();
			else if (Movement[1] == '2') {
				movement_Z();
				movement_Z();
			} else
				movement_aZ();
			break;
		case 'M':
			if (Movement[2] != '\0') {
				movement_aM();
				movement_aM();
			} else if (Movement[1] == '\0' && Movement[2] == '\0')
				movement_M();
			else if (Movement[1] == '2') {
				movement_M();
				movement_M();
			} else
				movement_aM();
			break;
		case 'E':
			if (Movement[2] != '\0') {
				movement_aE();
				movement_aE();
			} else if (Movement[1] == '\0' && Movement[2] == '\0')
				movement_E();
			else if (Movement[1] == '2') {
				movement_E();
				movement_E();
			} else
				movement_aE();
			break;
		case 'S':
			if (Movement[2] != '\0') {
				movement_aS();
				movement_aS();
			} else if (Movement[1] == '\0' && Movement[2] == '\0')
				movement_S();
			else if (Movement[1] == '2') {
				movement_S();
				movement_S();
			} else
				movement_aS();
			break;
		case 'u':
			if (Movement[2] != '\0') {
				movement_au();
				movement_au();
			} else if (Movement[1] == '\0' && Movement[2] == '\0')
				movement_u();
			else if (Movement[1] == '2') {
				movement_u();
				movement_u();
			} else
				movement_au();
			break;
		case 'l':
			if (Movement[2] != '\0') {
				movement_al();
				movement_al();
			} else if (Movement[1] == '\0' && Movement[2] == '\0')
				movement_l();
			else if (Movement[1] == '2') {
				movement_l();
				movement_l();
			} else
				movement_al();
			break;
		case 'f':
			if (Movement[2] != '\0') {
				movement_af();
				movement_af();
			} else if (Movement[1] == '\0' && Movement[2] == '\0')
				movement_f();
			else if (Movement[1] == '2') {
				movement_f();
				movement_f();
			} else
				movement_af();
			break;
		case 'r':
			if (Movement[2] != '\0') {
				movement_ar();
				movement_ar();
			} else if (Movement[1] == '\0' && Movement[2] == '\0')
				movement_r();
			else if (Movement[1] == '2') {
				movement_r();
				movement_r();
			} else
				movement_ar();
			break;
		case 'b':
			if (Movement[2] != '\0') {
				movement_ab();
				movement_ab();
			} else if (Movement[1] == '\0' && Movement[2] == '\0')
				movement_b();
			else if (Movement[1] == '2') {
				movement_b();
				movement_b();
			} else
				movement_ab();
			break;
		case 'd':
			if (Movement[2] != '\0') {
				movement_ad();
				movement_ad();
			} else if (Movement[1] == '\0' && Movement[2] == '\0')
				movement_d();
			else if (Movement[1] == '2') {
				movement_d();
				movement_d();
			} else
				movement_ad();
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
		case 0:
			break;
		case 1:
			break;
	}
}
