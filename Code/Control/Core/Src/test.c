///*
// * test.c
// *
// *  Created on: Nov 26, 2023
// *      Author: justin
// */
//
#include "test.h"

void test_scanCube(uint8_t *flag) {
	if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == SET && (*flag) != 7) {
		LCD_Clear(0, 0, 240, 320, BACKGROUND);
		switch (*flag) {
			case 0:
				LCD_DrawString(0,0,"Scan up");
				movement_scan_up();
				break;
			case 1:
				LCD_DrawString(0,0,"Scan east");
				movement_scan_east();
				break;
			case 2:
				LCD_DrawString(0,0,"Scan south");
				movement_scan_south();
				break;
			case 3:
				LCD_DrawString(0,0,"Scan down");
				movement_scan_down();
				break;
			case 4:
				LCD_DrawString(0,0,"Scan west");
				movement_scan_west();
				break;
			case 5:
				LCD_DrawString(0,0,"Scan north");
				movement_scan_north();
				break;
			case 6:
				LCD_DrawString(0,0,"Recover");
				movement_scan_north_r();
				break;
		}
		if ((*flag) != 6)
			(*flag)++;
		else
			(*flag) = 31;
	}
}
//
//void test_servo_movement(void) {
//	char string[20];
////	sprintf(string, "It is now flag %d.", flag);
//	LCD_DrawString(0, HEIGHT_EN_CHAR*8, string);
////	display_servo_info(&last_tick);
//	if (start <= 1)
//	  insert_cube();
//	else {
//	  if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == SET) {
//		  switch (flag) {
//			  case 0:
//				  movement_F();
//				  movement_aF();
//				  flag++;
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  break;
//			  case 1:
//				  movement_R();
//				  movement_aR();
//				  flag++;
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  break;
//			  case 2:
//				  movement_L();
//				  movement_aL();
//				  flag++;
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  break;
//			  case 3:
//				  movement_B();
//				  movement_aB();
//				  flag++;
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  break;
//			  case 4:
//				  movement_U();
//				  movement_aU();
//				  flag++;
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  break;
//			  case 5:
//				  movement_D();
//				  movement_aD();
//				  flag++;
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  break;
//			  case 6:
//				  movement_X();
//				  movement_aX();
//				  flag++;
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  break;
//			  case 7:
//				  movement_Y();
//				  movement_aY();
//				  flag++;
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  break;
//			  case 8:
//				  movement_Z();
//				  movement_aZ();
//				  flag++;
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  break;
//			  case 9:
//				  movement_M();
//				  movement_aM();
//				  flag++;
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  break;
//			  case 10:
//				  movement_E();
//				  movement_aE();
//				  flag++;
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  break;
//			  case 11:
//				  movement_S();
//				  movement_aS();
//				  flag++;
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  break;
//			  case 12:
//				  movement_u();
//				  movement_au();
//				  flag++;
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  break;
//			  case 13:
//				  movement_l();
//				  movement_al();
//				  flag++;
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  break;
//			  case 14:
//				  movement_f();
//				  movement_af();
//				  flag++;
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  break;
//			  case 15:
//				  movement_r();
//				  movement_ar();
//				  flag++;
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  break;
//			  case 16:
//				  movement_b();
//				  movement_ab();
//				  flag++;
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  break;
//			  case 17:
//				  movement_d();
//				  movement_ad();
//				  flag++;
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  break;
//			  case 18:
//				  movement_F2();
//				  movement_aF2();
//				  flag++;
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  break;
//			  case 19:
//				  movement_R2();
//				  movement_aR2();
//				  flag++;
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  break;
//			  case 20:
//				  movement_L2();
//				  movement_aL2();
//				  flag++;
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  break;
//			  case 21:
//				  movement_B2();
//				  movement_aB2();
//				  flag++;
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  break;
//			  case 22:
//				  movement_U2();
//				  movement_aU2();
//				  flag++;
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  break;
//			  case 23:
//				  movement_D2();
//				  movement_aD2();
//				  remove_cube();
//				  flag++;
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  break;
//			  case 100:
//				  servo_pull(north_back);
//				  servo_pull(south_back);
//				  HAL_Delay(DELAY_TIME_P);
//				  clockwise_90(west_front);
//				  anticlockwise_90(east_front);
//				  HAL_Delay(DELAY_TIME_90);
//				  LCD_Clear (0, 0, 240, 320, BACKGROUND);
//				  flag++;
//				  break;
//			  default:
//				  HAL_Delay(0xFFFF);
//		  }
//	  }
//	}
//}
//
//void test_communication_two_boards(void) {
//	char test_receive[10] = "";
//	char test_transmit[10] = "987654321";
//	HAL_UART_Receive(&huart1, test_receive, sizeof(test_receive), 0xFFFF);
//	LCD_DrawString(0, 0, test_receive);
//	HAL_Delay(1000);
//	LCD_DrawString(0, HEIGHT_EN_CHAR, test_transmit);
//	HAL_UART_Transmit(&huart1, test_transmit, sizeof(test_transmit), 0xFFFF);
//	LCD_DrawString(0, HEIGHT_EN_CHAR*2, "Transmit Success!!!");
//
//}
//
//void test_commands(void) {
//	static char listOfCommand[100][SIZE_OF_ONE_MOVEMENT];
//	char input[] = "F F' F2 F2'#";
//	int size;
//	ReadInput(input, &size, listOfCommand);
//	SolveTheCube(listOfCommand, size);
//}
