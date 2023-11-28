#include "bsp_ov7725.h"
#include "bsp_sccb.h"
#include "lcd.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"

typedef struct Reg
{
	uint8_t Address;			       
	uint8_t Value;		           
}Reg_Info;


Reg_Info Sensor_Config[] =
{
	{CLKRC,     0x00}, /*clock config*/
	{COM7,      0x46}, /*QVGA RGB565 */
  {HSTART,    0x3f},
	{HSIZE,     0x50},
	{VSTRT,     0x03},
	{VSIZE,     0x78},
	{HREF,      0x00},
	{HOutSize,  0x50},
	{VOutSize,  0x78},
	{EXHCH,     0x00},
 
	/*DSP control*/
	{TGT_B,     0x7f},
	{FixGain,   0x09},
	{AWB_Ctrl0, 0xe0},
	{DSP_Ctrl1, 0xff},
	{DSP_Ctrl2, 0x20},
	{DSP_Ctrl3,	0x00},
	{DSP_Ctrl4, 0x00},

	/*AGC AEC AWB*/
	{COM8,		  0xf0},
	{COM4,		  0x81}, /*Pll AEC CONFIG*/
	{COM6,		  0xc5},
	{COM9,		  0x21},
	{BDBase,	  0xFF},
	{BDMStep,	  0x01},
	{AEW,		    0x34},
	{AEB,		    0x3c},
	{VPT,		    0xa1},
	{EXHCL,		  0x00},
	{AWBCtrl3,  0xaa},
	{COM8,		  0xff},
	{AWBCtrl1,  0x5d},

	{EDGE1,		  0x0a},
	{DNSOff,	  0x01},
	{EDGE2,		  0x01},
	{EDGE3,		  0x01},

	{MTX1,		  0x5f},
	{MTX2,		  0x53},
	{MTX3,		  0x11},
	{MTX4,		  0x1a},
	{MTX5,		  0x3d},
	{MTX6,		  0x5a},
	{MTX_Ctrl,  0x1e},

	{BRIGHT,	  0x00},
	{CNST,		  0x25},
	{USAT,		  0x65},
	{VSAT,		  0x65},
	{UVADJ0,	  0x81},
	{SDE,		    0x06},
	
    /*GAMMA config*/
	{GAM1,		  0x0c},
	{GAM2,		  0x16},
	{GAM3,		  0x2a},
	{GAM4,		  0x4e},
	{GAM5,		  0x61},
	{GAM6,		  0x6f},
	{GAM7,		  0x7b},
	{GAM8,		  0x86},
	{GAM9,		  0x8e},
	{GAM10,		  0x97},
	{GAM11,		  0xa4},
	{GAM12,		  0xaf},
	{GAM13,		  0xc5},
	{GAM14,		  0xd7},
	{GAM15,		  0xe8},
	{SLOP,		  0x20},

	{HUECOS,	  0x80},
	{HUESIN,	  0x80},
	{DSPAuto,	  0xff},
	{DM_LNL,	  0x00},
	{BDBase,	  0x99},
	{BDMStep,	  0x03},
	{LC_RADI,	  0x00},
	{LC_COEF,	  0x13},
	{LC_XC,		  0x08},
	{LC_COEFB,  0x14},
	{LC_COEFR,  0x17},
	{LC_CTR,	  0x05},
	
	{COM3,		  0xd0},/*Horizontal mirror image*/

	/*night mode auto frame rate control*/
	{COM5,		0xf5},	 /*auto reduce rate*/
	//{COM5,		0x31},	/*no auto*/
};

uint8_t OV7725_REG_NUM = sizeof(Sensor_Config)/sizeof(Sensor_Config[0]);	  

extern uint8_t Ov7725_vsync ;	 



/************************************************
 * Sensor_Init
 ************************************************/
ErrorStatus Ov7725_Init(void)
{
	uint16_t i = 0;
	uint8_t Sensor_IDCode = 0;	
	
	if( 0 == SCCB_WriteByte ( 0x12, 0x80 ) ) /*reset sensor */
	{
		return ERROR ;
	}	

	if( 0 == SCCB_ReadByte( &Sensor_IDCode, 1, 0x0b ) )	 /* read sensor ID*/
	{
		return ERROR;
	}
	//DEBUG("Sensor ID is 0x%x", Sensor_IDCode);	
	
	if(Sensor_IDCode == OV7725_ID)
	{
		for( i = 0 ; i < OV7725_REG_NUM ; i++ )
		{
			if( 0 == SCCB_WriteByte(Sensor_Config[i].Address, Sensor_Config[i].Value) )
			{                
				return ERROR;
			}
		}
	}
	else
	{
		return ERROR;
	}
	
	return SUCCESS;
}

void ImagDisp(void)
{
	uint16_t i, j;
	uint16_t Camera_Data;
	
	LCD_Cam_Gram();
	
	for(i = 0; i < 240; i++)
	{
		for(j = 0; j < 320; j++)
		{
			READ_FIFO_PIXEL(Camera_Data);		
			LCD_Write_Data(Camera_Data);
		}
	}
	HAL_Delay(1000);
}

void initArray(int* Array, int size) {
	for (int i=0; i<size; ++i) {
		Array[i] = 0;
	}
}

int detect(uint16_t i, uint16_t j) {
	if ((abs(FACE_ONE_X - i)<=SAMPLE_SIZE/2) && (abs(FACE_ONE_Y - j)<=SAMPLE_SIZE/2)) {
		return 0;
	}
	if ((abs(FACE_TWO_X - i)<=SAMPLE_SIZE/2) && (abs(FACE_TWO_Y - j)<=SAMPLE_SIZE/2)) {
		return 1;
	}
	if ((abs(FACE_THREE_X - i)<=SAMPLE_SIZE/2) && (abs(FACE_THREE_Y - j)<=SAMPLE_SIZE/2)) {
		return 2;
	}
	if ((abs(FACE_FOUR_X - i)<=SAMPLE_SIZE/2) && (abs(FACE_FOUR_Y - j)<=SAMPLE_SIZE/2)) {
		return 3;
	}
	if ((abs(FACE_FIVE_X - i)<=SAMPLE_SIZE/2) && (abs(FACE_FIVE_Y - j)<=SAMPLE_SIZE/2)) {
		return 4;
	}
	if ((abs(FACE_SIX_X - i)<=SAMPLE_SIZE/2) && (abs(FACE_SIX_Y - j)<=SAMPLE_SIZE/2)) {
		return 5;
	}
	if ((abs(FACE_SEVEN_X - i)<=SAMPLE_SIZE/2) && (abs(FACE_SEVEN_Y - j)<=SAMPLE_SIZE/2)) {
		return 6;
	}
	if ((abs(FACE_EIGHT_X - i)<=SAMPLE_SIZE/2) && (abs(FACE_EIGHT_Y - j)<=SAMPLE_SIZE/2)) {
		return 7;
	}
	if ((abs(FACE_NINE_X - i)<=SAMPLE_SIZE/2) && (abs(FACE_NINE_Y - j)<=SAMPLE_SIZE/2)) {
		return 8;
	}
	return 9;
}

void int2RGB(uint16_t RGB, int* R, int* G, int* B) {
	*R = (RGB & 31 << 11) >> 11;
	*G = (RGB & 63 << 5) >> 5;
	*B = RGB & 31;
}
// For debug
void printRGB(int R, int G, int B, int row, int col) {
	char str_R[2], str_G[2], str_B[2];
	sprintf(str_R, "%d", R);
	sprintf(str_G, "%d", G);
	sprintf(str_B, "%d", B);
	int x = 70*col + 20;
	int y = 40*row + 40;
	LCD_DrawString(x, y, str_R);
	LCD_DrawString(x+20, y, str_G);
	LCD_DrawString(x+40, y, str_B);
}
// For debug
void printColor(int R, int G, int B, int row, int col) { // need to change the write array --> this is only for debug
	int num = row*3 + col + 1;
	char str_num[1];
	sprintf(str_num, "%d", num);
	int x = 70*col + 20;
	int y = 40*row + 20;
	LCD_DrawString(x, y, str_num);
	x += 8;
	LCD_DrawString(x, y, ".");
	x += 8;
	if (G > 45) {
		LCD_DrawString(x, y, "Yellow");
	} else {
		if (R < 8) {
			if (G > 30) {
				LCD_DrawString(x, y, "Green");
			} else {
				LCD_DrawString(x, y, "Blue");
			}
		} else {
			if (B > 13) {
				LCD_DrawString(x, y, "White");
			} else {
				if (G < 24) {
					LCD_DrawString(x, y, "Red");
				} else {
					LCD_DrawString(x, y, "Orange");
				}
			}
		}
	}
}
// call printRGB & printColor for debug
void printColorRGB(int* R, int* G, int* B) {
	for (int row=0; row<3; ++row) {
		for (int col=0; col<3; ++col) {
			int num = row*3 + col;
			printColor(R[num], G[num], B[num], row, col);
			printRGB(R[num], G[num], B[num], row, col);
		}
	}
}

void sumRGB(int Camera_Data, int* R_Sum, int* G_Sum, int* B_Sum) {
	int R, G, B;
	int2RGB(Camera_Data, &R, &G, &B);
	*R_Sum += R;
	*G_Sum += G;
	*B_Sum += B;
}

void averageRGB(int sum, int size, int* average) {
	*average = sum/size;
}
// detect which square and sum the RGB value
void detect_sum(uint16_t i, uint16_t j, uint16_t Camera_Data, int* R, int* G, int* B) {
	int num = detect(i, j);
	if (num != 9) {
		sumRGB(Camera_Data, &(R[num]), &(G[num]), &(B[num]));
	}
}
// write the color into the return array
void writeColorIntoArray(int* R, int* G, int* B, char* SquareOfOneFace) {
	// content the same with printColor()
	for (int num=0; num<9; num++) {
		if (G > 45) {
				SquareOfOneFace[num] = 'Y';
			} else {
				if (R < 8) {
					if (G > 30) {
						SquareOfOneFace[num] = 'G';
					} else {
						SquareOfOneFace[num] = 'B';
					}
				} else {
					if (B > 13) {
						SquareOfOneFace[num] = 'W';
					} else {
						if (G < 24) {
							SquareOfOneFace[num] = 'R';
						} else {
							SquareOfOneFace[num] = 'O';
						}
					}
				}
			}
	}
}

// main system will make use of this function to scan one face
void ReadSquare(char* SquareOfOneFace) {
	uint16_t i, j;
	uint16_t Camera_Data;
	int R[9];
	int G[9];
	int B[9];
	initArray(R, 9);
	initArray(G, 9);
	initArray(B, 9);

	// LCD_Cam_Gram();

	for(i = 0; i < 240; i++)
	{
		for(j = 0; j < 320; j++)
		{
			READ_FIFO_PIXEL(Camera_Data);
			detect_sum(i, j, Camera_Data, R, G, B);
		}
	}
	for (i=0; i<9; ++i) {
		averageRGB(R[i], SAMPLE_SIZE*SAMPLE_SIZE, &(R[i]));
		averageRGB(G[i], SAMPLE_SIZE*SAMPLE_SIZE, &(G[i]));
		averageRGB(B[i], SAMPLE_SIZE*SAMPLE_SIZE, &(B[i]));
	}
	// printColorRGB(R, G, B);
	writeColorIntoArray(R, G, B, SquareOfOneFace);
	// printArray(SquareOfOneFace);
	// HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
	// HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
	// HAL_Delay(1000);
}
