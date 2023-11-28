/*
 * CameraWithErrorCorrection.h
 *
 *  Created on: 2023年11月6日
 *      Author: him
 */

#ifndef INC_CAMERAWITHERRORCORRECTION_H_
#define INC_CAMERAWITHERRORCORRECTION_H_
#include "stdint.h"

#define				SQUARE_SIZE			60
#define 			FIRST_ROW_COL		20
#define 			SECOND_ROW_COL		80
#define				THIRD_ROW_COL		90
#define				FOURTH_ROW_COL		150
#define				FIFTH_ROW_COL		160
#define				SIXTH_ROW_COL		220

void writeDataIntoAllFaces(char*, char*, int);
void printArray(char*);
uint16_t convertColor2RGB(char Color);
int stringCompare(char*, char*, int);
// void Error_correction(char*);
void printFace(char*);
// int checkingAllFaces(char* AllFaces);
int CameraWithErrorCorrection(char*);



#endif /* INC_CAMERAWITHERRORCORRECTION_H_ */
