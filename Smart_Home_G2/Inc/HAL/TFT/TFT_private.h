/*
 * TFT_private.h
 *
 *  Created on: April 25, 2022
 *  Author    : Abdelhai Tahoon
 *  Version   : 1.0
 */

#ifndef TFT_PRIVATE_H
#define TFT_PRIVATE_H

#define LED1_x 		200
#define lED1_Y		20

#define LED2_x 		170
#define lED2_Y		20

#define LED3_x 		140
#define lED3_Y		20

#define LED4_x 		110
#define lED4_Y		20

#define LED5_x 		100
#define lED5_Y		20

#define LED6_x 		70
#define lED6_Y		20

#define LED_SIZE_X			30
#define LED_SIZE_Y			40



#define LED_DIMMER_X  	50
#define LED_DIMMER_Y	20

#define LED_DIMMER_SIZE_X 				 30
#define LED_DIMMER_SIZE_Y 			     40










#define PASS_X					75		/*password first position x*/
#define PASS_Y					181     /*password first position x*/
#define STAR_SIZE 				11		/*must be odd*/
#define STAR_COLOR 				0x0010	/*red*/
#define PASS_SPACE				17


#define NEW_PASS_X			60
#define NEW_PASS_Y			55
#define NEW_PASS_X_SIZE		120
#define NEW_PASS_Y_SIZE		49

#define TRIAL_PIC_X					80
#define TRIAL_PIC_Y					70
#define TRIAL_PIC_X_SIZE			70
#define TRIAL_PIC_Y_SIZE			25

#define TRIAL_NUM_X			150
#define TRIAL_NUM_Y 		75


#define PASS_PIC_X				85
#define PASS_PIC_Y				125
#define PASS_PIC_X_SIZE			70
#define PASS_PIC_Y_SIZE			70


#define door_x					130
#define door_y					80

#define door_size_x				100
#define door_size_y				65




#define AC_X					160
#define AC_Y					148 +20

#define AC_SIZE_Y				50
#define AC_SIZE_X				75


#define BUTTON1_UP_X			124
#define BUTTON1_UP_Y			165 +20
#define BUTTON1_UP_SIZE			12
#define BUTTON1_UP_COLOR		0x0220 /*green */

#define BUTTON1_DOWN_X			124
#define BUTTON1_DOWN_Y			170	+20
#define BUTTON1_DOWN_SIZE		12
#define BUTTON2_DOWN_COLOR		0xfe86 /*blue */

#define CHANGE_PASS_BUTT_X			10
#define CHANGE_PASS_BUTT_Y			180 +40
#define CHANGE_PASS_BUTT_X_SIZE		95
#define CHANGE_PASS_BUTT_Y_SIZE		27


#define NUM_X				210
#define NUM_y				155 +20
#define NUM_X_SIZE 		    10
#define NUM_Y_SIZE 		    10

#define NUM_SPACE 		    10


#define LED_ON				1
#define LED_OFF				0
#define MAX_LED				5


#define KEYPAD_X				52
#define KEYPAD_Y				200
#define KEYPAD_X_SIZE			140
#define KEYPAD_Y_SIZE			48


#define POLICE_X				15
#define POLICE_Y				30

#define POLICE_SIZE_X			205
#define POLICE_SIZE_Y			210


/*for tft instructions */
static void voidWriteCommand(u8 Copy_u8Command);
static void voidWriteData(u8 Copy_u8Data);


static void TFT_vDrawRectangular( u8 x1,u8 x2,u16 y1,u16 y2,u16 Copy_u16Color);


/*to draw one pixel at a time */
static void TFT_vSetCursorPosition(u8 x1, u16 y1, u8 x2, u16 y2);
static void TFT_vDrawPixel(u8 x,u16 y, u16 color);

/*some drawing shapes*/
static void TFT_vDrawHLine(u8 x1, u16 y1, u8 lenght, u16 color);
static void TFT_vDrawVLine(u8 x1, u16 y1, u16 lenght, u16 color);
static void TFT_vDrawUpTriangle(u8 x1, u16 y1, u8 size, u16 color);
static void TFT_vDrawDownTriangle(u8 x1, u16 y1, u8 size, u16 color);


static void TFT_vDrawRectanglePixel(u8 x1, u8 x2,u16 y1, u16 y2 , u16 color);
static void TFT_vDrawStar(u8 x1, u16 y1, u8 size, u16 color);

static void HTFT_vDrawKeyPad();

/*function for stating panels the start up photo will appear */
static void TFT_vDrawLeds();
static void TFT_vNumberAtPosition(u8 x,u8 y ,u8 num);
static void TFT_vDrawChangePassButton();
static void TFT_vDrawDimmerLed();


#endif  //TFT_PRIVATE_H
