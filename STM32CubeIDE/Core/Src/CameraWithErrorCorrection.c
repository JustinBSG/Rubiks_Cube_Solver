/*
 * CameraWithErrorCorrection.c
 *
 *  Created on: 2023年11月6日
 *      Author: him
 */

#include "CameraWithErrorCorrection.h"
#include "bsp_ov7725.h"
#include "xpt2046.h"
#include "main.h"
#include "lcd.h"

extern uint8_t Ov7725_vsync;

void writeDataIntoAllFaces(char* AllFaces, char* OneFace, int num) {
	for (int i=0; i<9; ++i) {
		AllFaces[num*9+i] = OneFace[i];
	}
}

void printArray(char* Array) {
	LCD_DrawString(10, 260, Array);
}

int checkingAllFaces(char* AllFaces) {
	int countWhite = 0;
	int countOrange = 0;
	int countRed = 0;
	int countBlue = 0;
	int countGreen = 0;
	int countYellow = 0;
	for (int i=0; i<54; ++i) {
		if (AllFaces[i] == 'W') countWhite++;
		else if (AllFaces[i] == 'O') countOrange++;
		else if (AllFaces[i] == 'R') countRed++;
		else if (AllFaces[i] == 'B') countBlue++;
		else if (AllFaces[i] == 'G') countGreen++;
		else countYellow++;
	}
	if (countWhite!=9 || countOrange!=9 || countRed!=9 || countBlue!=9 || countGreen!=9 || countYellow!= 9) {
		return 0;
	}
	return 1;
}

int CameraWithErrorCorrection(char* AllFaces) {
	  // macXPT2046_CS_DISABLE();
	// while( ! XPT2046_Touch_Calibrate () );
	LCD_Clear ( 0, 0, 240, 320, GREY );
	for (int NumOfFaces=0; NumOfFaces<6; ++NumOfFaces) {
		char SquareOfOneFace[9];
		// Need signal
		// if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET) {
		// 	HAL_Delay(50);
		// 	if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_RESET) {
				while(Ov7725_Init() != SUCCESS);
			  	Ov7725_vsync = 0;
				HAL_Delay(1000);
				// while(1) {
					if (Ov7725_vsync == 2)
						{
							FIFO_PREPARE;
							ReadSquare(SquareOfOneFace);
							return;
							// ImagDisp();
							Ov7725_vsync = 0;
						}
				// }
				LCD_Clear ( 0, 0, 240, 320, GREY );
				Error_correction(SquareOfOneFace);
				printArray(SquareOfOneFace);
				writeDataIntoAllFaces(AllFaces, SquareOfOneFace, NumOfFaces);
				HAL_Delay(500);
		// 	}
		// }
	}
	LCD_Clear ( 0, 0, 240, 320, GREY );
	LCD_DrawString(10, 10, "All faces colors are: ");
	LCD_DrawString(10, 30, AllFaces);
	if (checkingAllFaces(AllFaces)) {
		LCD_DrawString(20, 130, "# of colors are correct");
		LCD_DrawString(20, 150, "Proceed to next process...");
		return 1;
	} else {
		LCD_DrawString(20, 130, "# of colors are not correct");
		return 0;
	}
	// printArray(AllFaces+9*3, 9*3);

}
