/*
 * CameraWithErrorCorrection.c
 *
 *  Created on: 2023年11月6日
 *      Author: him
 */

#include "CameraWithErrorCorrection.h"
#include "bsp_ov7725.h"
// #include "xpt2046.h"
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

uint16_t convertColor2RGB(char Color) { // need change
	if (Color == 'W') {
		return WHITE;
	}
	if (Color == 'O') {
		return ORANGE;
	}
	if (Color == 'G') {
		return GREEN;
	}
	if (Color == 'Y') {
		return YELLOW;
	}
	if (Color == 'B') {
		return BLUE;
	}
	if (Color == 'R') {
		return RED;
	}
	return CYAN; // a color to indicate wrong color
}

int stringCompare(char* target, char* src, int size) {
	for (int i=0; i<size; ++i) {
		if (target[i] != src[i]) {
			return 1;
		}
	}
	return 0;
}
//void Error_correction(char* SquareOfOneFace) {
//	printFace(SquareOfOneFace);
//	// Need changing
//	// while (1) {
//	// 		wait signal
//	// 		if str != terminate --> change faces
//	//		else return
////	while (1) {
////		if (ucXPT2046_TouchFlag == 1) {
////			Check_touchkey(SquareOfOneFace);
////			ucXPT2046_TouchFlag = 0;
////		}
////		HAL_Delay(50);
////		if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET) {
////			HAL_Delay(50);
////			if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_RESET) {
////				printFace(SquareOfOneFace);
////				LCD_Clear(90, 240, 60, 60, WHITE);
////				LCD_DrawString(20, 240, "This face's colors are: ");
////				break;
////			}
////		}
////	}
//	return;
//}

void printFace(char* SquareOfOneFace) {
	LCD_Clear(10, 10, 220, 220, BLACK);
	for (int row=0; row<3; ++row) {
		for (int col=0; col<3; ++col) {
			int num = row*3+col;
			uint16_t RGB = convertColor2RGB(SquareOfOneFace[num]);
			int x = (SQUARE_SIZE+10)*col+FIRST_ROW_COL;
			int y = (SQUARE_SIZE+10)*row+FIRST_ROW_COL;
			LCD_Clear(x, y, SQUARE_SIZE, SQUARE_SIZE, RGB);
		}
	}
}

//int checkingAllFaces(char* AllFaces) {
//	int countWhite = 0;
//	int countOrange = 0;
//	int countRed = 0;
//	int countBlue = 0;
//	int countGreen = 0;
//	int countYellow = 0;
//	for (int i=0; i<54; ++i) {
//		switch (AllFaces[i]) {
//		case 'W':
//			countWhite++;
//			break;
//		case 'O':
//			countOrange++;
//			break;
//		case 'R':
//			countRed++;
//			break;
//		case 'B':
//			countBlue++;
//			break;
//		case 'G':
//			countGreen++;
//			break;
//		default:
//			countYellow++;
//		}
//	}
//	if (countWhite!=9 || countOrange!=9 || countRed!=9 || countBlue!=9 || countGreen!=9 || countYellow!= 9) {
//		return 0;
//	}
//	return 1;
//}

int CameraWithErrorCorrection(char* AllFaces) {
	  // macXPT2046_CS_DISABLE();
	// while( ! XPT2046_Touch_Calibrate () );
	LCD_Clear ( 0, 0, 240, 320, GREY );
	// for (int NumOfFaces=0; NumOfFaces<6; ++NumOfFaces) {

	// THE SIGNAL
	// AND THE VARIABLE NumOfFaces
	int NumOfFaces;

		char SquareOfOneFace[9];
		// Need signal
		// if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET) {
		// 	HAL_Delay(50);
		// 	if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_RESET) {
				while(Ov7725_Init() != SUCCESS);
			  	Ov7725_vsync = 0;
				HAL_Delay(1000);
				 while(1) {
					if (Ov7725_vsync == 2)
						{
							FIFO_PREPARE;
							ReadSquare(SquareOfOneFace);
							return 0;
//							ImagDisp();
							Ov7725_vsync = 0;
						}
				 }
//				LCD_Clear ( 0, 0, 240, 320, GREY );
//				Error_correction(SquareOfOneFace);
//				printArray(SquareOfOneFace);
//				writeDataIntoAllFaces(AllFaces, SquareOfOneFace, NumOfFaces);
//				HAL_Delay(500);
		// 	}
		// }
	// }

	// NEED TO PUT OUTSIDE
//	LCD_Clear ( 0, 0, 240, 320, GREY );
//	LCD_DrawString(10, 10, "All faces colors are: ");
//	LCD_DrawString(10, 30, AllFaces);
//	if (checkingAllFaces(AllFaces)) {
//		LCD_DrawString(20, 130, "# of colors are correct");
//		LCD_DrawString(20, 150, "Proceed to next process...");
//		return 1;
//	} else {
//		LCD_DrawString(20, 130, "# of colors are not correct");
//		return 0;
//	}
	// printArray(AllFaces+9*3, 9*3);

}
