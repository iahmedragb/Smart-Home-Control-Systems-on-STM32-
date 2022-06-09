/*
 * TFT_program.C
 *
 *  Created on: April 25, 2022
 *  Author    : Abdelhai Tahoon
 *  Version   : 1.0
 */

/************** INCLUDE LIB **************/
#include "LIB/Std_Types.h"
#include "LIB/Bit_Math.h"
#include "MCAL/GPIO/GPIO_Config.h"
#include "MCAL/GPIO/GPIO.h"
#include "MCAL/SPI/SPI_interface.h"
#include "MCAL/STK/STK.h"
/************** INCLUDE HCAL**************/
#include "HAL/TFT/TFT_private.h"
#include "HAL/TFT/TFT_interface.h"
#include "HAL/TFT/TFT_config.h"


/******************************************* Start_FUNCTION  *******************************************/


extern u16 Num1[];
extern u16 Num2[];
extern u16 Num3[];
extern u16 Num4[];
extern u16 Num5[];
extern u16 Num6[];
extern u16 Num7[];
extern u16 Num8[];
extern u16 Num9[];
extern u16 Led_off_pic[];
extern u16 Led_on_pic[];
extern u16 PassScreen[];
extern u16 DoorOpened[];
extern u16 DoorClosed[];
extern u16 AirConditioner[];
extern u16 Police [];
extern u16 Dimmer_Led[];
extern u16 NewPassword[];
extern u16 TrialsLeftPic[];
extern u16 ChangePAsswordPic[];
extern u16 KeyPadPic[];

/*	For initialization of TFT  :

			-	Reset Pulse (High 100 microSeconds & Low 1 microSec & high 100 microSec & low 100 microSec & 120 MelliSec keep high )
			-	Sleep Out Command 0x3A
			-	Wait 150 Ms
			-	Color mode And Select The Option(Parameter)From ( 444 (0x03), 365(0x05) , 666(0x06) )  Send Option as Data Not Command
			-	Display command   0X29
 */
void TFT_voidInit(void)
{
	/*set Pin configuration for spi and tft */

	GPIO_vSetMode(TFT_SPI_CLK_PIN  ,GPIO_ALF);        //SPI CLK
	GPIO_vSetMode(TFT_SPI_MOSI_PIN ,GPIO_ALF);        //SPI MOSI

	GPIO_vSetMode(TFT_RESET_PIN ,GPIO_Output);        //Reset for TFT
	GPIO_vSetMode(TFT_DC_PIN	,GPIO_Output);        //Data/Command select for tft

	GPIO_vSetAlternateFunction(TFT_SPI_CLK_PIN  ,AF5);      //Setting Alternate func SPI CLK
	GPIO_vSetAlternateFunction(TFT_SPI_MOSI_PIN ,AF5);      //Setting Alternate func SPI MOSI
	/*init Systic for delay*/
	STK_Init(STK_CLK_SRC_HCLK);
	/***************************************/

	/*	reset Pulse  */
	GPIO_vWritePinValue(TFT_RESET_PIN, HighState) ;
	STK_DelayUs(100);
	GPIO_vWritePinValue(TFT_RESET_PIN, LowState)  ;
	STK_DelayUs(1);
	GPIO_vWritePinValue(TFT_RESET_PIN, HighState) ;
	STK_DelayUs(100);
	GPIO_vWritePinValue(TFT_RESET_PIN, LowState)  ;
	STK_DelayUs(100);
	GPIO_vWritePinValue(TFT_RESET_PIN, HighState) ;
	STK_DelayUs(120000);


	voidWriteCommand(0x3A)				   ;
	voidWriteData(0x05)					   ;
	/*		Display On Command		*/
	voidWriteCommand(0x29)				   ;
}


void voidWriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8Temp ;			// SPI Send Data here it donsen't receive So it affects nothing
	/* Set A0	Pin to Low to send a command 	*/
	GPIO_vWritePinValue(TFT_DC_PIN , LowState) ;
	/* Send Command Over SPI */
	MSPI1_voidSendReceiveSynch(Copy_u8Command ,  &Local_u8Temp );
}

void voidWriteData(u8 Copy_u8Data)
{
	u8 Local_u8Temp ;			// SPI Send Data here it donsen't receive So it affects nothing
	/* Set A0	Pin to High to send data 	*/
	GPIO_vWritePinValue(TFT_DC_PIN , HighState) ;
	/* Send DATA Over SPI */
	MSPI1_voidSendReceiveSynch(Copy_u8Data , &Local_u8Temp );
}

void TFT_vSetCursorPosition(u8 x1, u16 y1, u8 x2, u16 y2){
	/*	Set X_ADRESS */
	voidWriteCommand(0x2A);
	/* Start Position*/
	voidWriteData(0);							/*send higher byte always be 0 as x limit is 240*/
	voidWriteData(x1); 							/*send lower Byte*/
	/* End position */
	voidWriteData(0);
	voidWriteData(x2);

	/*	Set Y_ADRESS */
	voidWriteCommand(0x2B);
	/* Start Position*/
	voidWriteData(y1>>8);      					/*send higher byte*/
	voidWriteData(y1 & 0x00ff);					/*send lower Byte */
	/* End Position*/
	voidWriteData((y2)>>8);
	voidWriteData((y2) & 0x00ff);

}

void TFT_vDrawPic(u8 x1,u8 x2,u16 y1,u16 y2, u16* Copy_Image)
{
	u32 Counter ;
	u32 Local_u32Size =( x2 - x1 ) * ( y2 - y1 ) ; /*calculate image element numbers*/
	TFT_vSetCursorPosition(x1, y1, x2, y2);		  /*set addresses of x and y */

	/* RAM Write Command Every thing is coming After This Command Display on TFT*/
	voidWriteCommand(0x2C);
	for(Counter = 0 ; Counter < Local_u32Size-5 ; Counter ++)	/*5 for protus*/
	{
		/* Write For One Pixel The High Byte Then Low Byte For Each Pixel */
		/* Write The High Byte */
		voidWriteData(Copy_Image[Counter] >> 8);
		/* Write The LOW Byte */
		voidWriteData(Copy_Image[Counter] & 0x00ff);
	}
}

void TFT_vDrawRectangular( u8 x1,u8 x2,u16 y1,u16 y2,u16 Copy_u16Color)
{
	u32 Counter ;
	u32 Local_u32Size =( x2 - x1 ) * ( y2 - y1 ) ; /*calculate image element numbers*/
	TFT_vSetCursorPosition(x1, y1, x2, y2);		  /*set addresses of x and y */


	/* RAM Write Command Every thing is coming After This Command Display on TFT*/
	voidWriteCommand(0x2C);
	for(Counter = 0 ; Counter < Local_u32Size+5 ; Counter ++)
	{
		/* Write For One Pixel The High Byte Then Low Byte For Each Pixel */
		/* Write The High Byte */
		voidWriteData(Copy_u16Color >> 8);
		/* Write The LOW Byte */
		voidWriteData(Copy_u16Color &0x00ff);
	}
}

void TFT_vClearScreen(){
	TFT_vDrawRectangular(0, 240, 0, 300, 0xffff); /* if used all scren it should be 240 X 320 */
}

void TFT_vDrawLeds(){
	u8 i =0 ;
	for(i = 0 ; i<6 ;i++){
		TFT_vDrawPic(LED1_x ,(LED1_x+LED_SIZE_X) ,lED1_Y ,(lED1_Y+LED_SIZE_Y) ,Led_off_pic);
		TFT_vDrawPic(LED2_x ,(LED2_x+LED_SIZE_X) ,lED2_Y ,(lED2_Y+LED_SIZE_Y) ,Led_off_pic);
		TFT_vDrawPic(LED3_x ,(LED3_x+LED_SIZE_X) ,lED3_Y ,(lED3_Y+LED_SIZE_Y) ,Led_off_pic);
		TFT_vDrawPic(LED4_x ,(LED4_x+LED_SIZE_X) ,lED4_Y ,(lED4_Y+LED_SIZE_Y) ,Led_off_pic);
		//TFT_vDrawPic(LED5_x ,(LED5_x+LED_SIZE_X) ,lED5_Y ,(lED5_Y+LED_SIZE_Y) ,Led_off_pic);
		//TFT_vDrawPic(LED6_x ,(LED6_x+LED_SIZE_X) ,lED6_Y ,(lED6_Y+LED_SIZE_Y) ,Led_off_pic);
	}

}

void TFT_vLedOn(u8 led_num){

	switch (led_num)
	{
	case 1: TFT_vDrawPic(LED1_x ,(LED1_x+LED_SIZE_X) ,lED1_Y ,(lED1_Y+LED_SIZE_Y) ,Led_on_pic); break;
	case 2: TFT_vDrawPic(LED2_x ,(LED2_x+LED_SIZE_X) ,lED2_Y ,(lED2_Y+LED_SIZE_Y) ,Led_on_pic); break;
	case 3: TFT_vDrawPic(LED3_x ,(LED3_x+LED_SIZE_X) ,lED3_Y ,(lED3_Y+LED_SIZE_Y) ,Led_on_pic); break;
	case 4: TFT_vDrawPic(LED4_x ,(LED4_x+LED_SIZE_X) ,lED4_Y ,(lED4_Y+LED_SIZE_Y) ,Led_on_pic); break;
//	case 5: TFT_vDrawPic(LED5_x ,(LED5_x+LED_SIZE_X) ,lED5_Y ,(lED5_Y+LED_SIZE_Y) ,Led_on_pic); break;
//	case 6: TFT_vDrawPic(LED6_x ,(LED6_x+LED_SIZE_X) ,lED6_Y ,(lED6_Y+LED_SIZE_Y) ,Led_on_pic); break;
	default: break;

	}
}

void TFT_vLedOff(u8 led_num){

	switch (led_num)
	{
	case 1: TFT_vDrawPic(LED1_x ,(LED1_x+LED_SIZE_X) ,lED1_Y ,(lED1_Y+LED_SIZE_Y) ,Led_off_pic); break;
	case 2: TFT_vDrawPic(LED2_x ,(LED2_x+LED_SIZE_X) ,lED2_Y ,(lED2_Y+LED_SIZE_Y) ,Led_off_pic); break;
	case 3: TFT_vDrawPic(LED3_x ,(LED3_x+LED_SIZE_X) ,lED3_Y ,(lED3_Y+LED_SIZE_Y) ,Led_off_pic); break;
	case 4: TFT_vDrawPic(LED4_x ,(LED4_x+LED_SIZE_X) ,lED4_Y ,(lED4_Y+LED_SIZE_Y) ,Led_off_pic); break;
//	case 5: TFT_vDrawPic(LED5_x ,(LED5_x+LED_SIZE_X) ,lED5_Y ,(lED5_Y+LED_SIZE_Y) ,Led_off_pic); break;
//	case 6: TFT_vDrawPic(LED6_x ,(LED6_x+LED_SIZE_X) ,lED6_Y ,(lED6_Y+LED_SIZE_Y) ,Led_off_pic); break;
	default: break;

	}
}

void TFT_vToggle(u8 led_num){

	u8 static ledTog[MAX_LED +1]= {0} ;   // +1 because we start from 1.

	if(ledTog[led_num] == LED_ON)
	{
		ledTog[led_num] = LED_OFF;
	}
	else{
		ledTog[led_num] = LED_ON;
	}

	if (ledTog[led_num] == LED_ON)
	{
		switch (led_num)
		{
		case 1: TFT_vDrawPic(LED1_x ,(LED1_x+LED_SIZE_X) ,lED1_Y ,(lED1_Y+LED_SIZE_Y) ,Led_on_pic); break;
		case 2: TFT_vDrawPic(LED2_x ,(LED2_x+LED_SIZE_X) ,lED2_Y ,(lED2_Y+LED_SIZE_Y) ,Led_on_pic); break;
		case 3: TFT_vDrawPic(LED3_x ,(LED3_x+LED_SIZE_X) ,lED3_Y ,(lED3_Y+LED_SIZE_Y) ,Led_on_pic); break;
		case 4: TFT_vDrawPic(LED4_x ,(LED4_x+LED_SIZE_X) ,lED4_Y ,(lED4_Y+LED_SIZE_Y) ,Led_on_pic); break;
	//	case 5: TFT_vDrawPic(LED5_x ,(LED5_x+LED_SIZE_X) ,lED5_Y ,(lED5_Y+LED_SIZE_Y) ,Led_on_pic); break;
	//	case 6: TFT_vDrawPic(LED6_x ,(LED6_x+LED_SIZE_X) ,lED6_Y ,(lED6_Y+LED_SIZE_Y) ,Led_on_pic); break;
		default: break;
		}
	}
	else{
		switch (led_num)
		{
		case 1: TFT_vDrawPic(LED1_x ,(LED1_x+LED_SIZE_X) ,lED1_Y ,(lED1_Y+LED_SIZE_Y) ,Led_off_pic); break;
		case 2: TFT_vDrawPic(LED2_x ,(LED2_x+LED_SIZE_X) ,lED2_Y ,(lED2_Y+LED_SIZE_Y) ,Led_off_pic); break;
		case 3: TFT_vDrawPic(LED3_x ,(LED3_x+LED_SIZE_X) ,lED3_Y ,(lED3_Y+LED_SIZE_Y) ,Led_off_pic); break;
		case 4: TFT_vDrawPic(LED4_x ,(LED4_x+LED_SIZE_X) ,lED4_Y ,(lED4_Y+LED_SIZE_Y) ,Led_off_pic); break;
	//	case 5: TFT_vDrawPic(LED5_x ,(LED5_x+LED_SIZE_X) ,lED5_Y ,(lED5_Y+LED_SIZE_Y) ,Led_off_pic); break;
	//	case 6: TFT_vDrawPic(LED6_x ,(LED6_x+LED_SIZE_X) ,lED6_Y ,(lED6_Y+LED_SIZE_Y) ,Led_off_pic); break;
		default: break;

		}
	}
}

void TFT_vDoorOpened()
{
	TFT_vDrawPic(door_x ,door_x+door_size_x ,door_y ,door_y+door_size_y ,DoorOpened);
}

void TFT_vDoorClosed()
{
	TFT_vDrawPic(door_x ,door_x+door_size_x ,door_y ,door_y+door_size_y ,DoorClosed);
}

void TFT_vDrawAirConditioner()
{
	TFT_vDrawPic(AC_X ,AC_X + AC_SIZE_X ,AC_Y ,AC_Y+AC_SIZE_Y ,AirConditioner);

}

void TFT_vAcOn(){
	TFT_vDrawRectangular(AC_X +10 ,AC_X +15 ,AC_Y +15 ,AC_Y +20 ,0x0f80); /*red idicatoion for off */


}

void TFT_vAcOff()
{
	TFT_vDrawRectangular(AC_X +10 ,AC_X +15 ,AC_Y +15 ,AC_Y +20 ,0x00ff); /*green idicatoion for on */

}

void TFT_vDrawAcButton(){

	TFT_vDrawUpTriangle(BUTTON1_UP_X, BUTTON1_UP_Y,BUTTON1_UP_SIZE ,BUTTON1_UP_COLOR);
	TFT_vDrawDownTriangle(BUTTON1_DOWN_X, BUTTON1_DOWN_Y,BUTTON1_DOWN_SIZE ,BUTTON2_DOWN_COLOR);

}

void TFT_vNumberAtPosition(u8 x,u8 y,u8 num){
	switch (num){
	case 1 : TFT_vDrawPicturesPixels (x ,x+NUM_X_SIZE ,y ,y+NUM_Y_SIZE ,Num1); break;
	case 2 : TFT_vDrawPicturesPixels (x ,x+NUM_X_SIZE ,y ,y+NUM_Y_SIZE ,Num2); break;
	case 3 : TFT_vDrawPicturesPixels (x ,x+NUM_X_SIZE ,y ,y+NUM_Y_SIZE ,Num3); break;
	case 4 : TFT_vDrawPicturesPixels (x ,x+NUM_X_SIZE ,y ,y+NUM_Y_SIZE ,Num4); break;
	case 5 : TFT_vDrawPicturesPixels (x ,x+NUM_X_SIZE ,y ,y+NUM_Y_SIZE ,Num5); break;
	case 6 : TFT_vDrawPicturesPixels (x ,x+NUM_X_SIZE ,y ,y+NUM_Y_SIZE ,Num6); break;
	case 7 : TFT_vDrawPicturesPixels (x ,x+NUM_X_SIZE ,y ,y+NUM_Y_SIZE ,Num7); break;
	case 8 : TFT_vDrawPicturesPixels (x ,x+NUM_X_SIZE ,y ,y+NUM_Y_SIZE ,Num8); break;
	case 9 : TFT_vDrawPicturesPixels (x ,x+NUM_X_SIZE ,y ,y+NUM_Y_SIZE ,Num9); break;
	default:  break ;

	}
}

void TFT_vDrawTempValue(u16 Num){
	u8 mod;


	if(Num<9){
		TFT_vNumberAtPosition(NUM_X,NUM_y,Num);
	}
	else if (Num<99)
	{
		mod = Num % 10;
		TFT_vNumberAtPosition(NUM_X,NUM_y,mod);
		Num/=10;
		TFT_vNumberAtPosition(NUM_X + NUM_SPACE,NUM_y,Num);
	}
	else if (Num<999)
	{
		mod = Num % 10;
		TFT_vNumberAtPosition(NUM_X,NUM_y,mod);
		Num/=10;
		mod = Num % 10;
		TFT_vNumberAtPosition(NUM_X+ NUM_SPACE,NUM_y,mod);
		Num/=10;
		TFT_vNumberAtPosition(NUM_X + NUM_SPACE *2,NUM_y,Num);

	}

}


void TFT_vDrawDimmerLed()
{
	TFT_vDrawPic(LED_DIMMER_X,LED_DIMMER_X +LED_DIMMER_SIZE_X ,LED_DIMMER_Y, LED_DIMMER_Y+LED_DIMMER_SIZE_Y ,Dimmer_Led);

}

void TFT_vControlDimmerLed( u8 Copy_u8PwmValue){
	u32 Counter ;
	u16 color =0x0000;
	u32 Local_u32Size = LED_DIMMER_SIZE_X  *  LED_DIMMER_SIZE_Y ;
	TFT_vSetCursorPosition(LED_DIMMER_X,LED_DIMMER_Y ,(LED_DIMMER_X + LED_DIMMER_SIZE_X),(LED_DIMMER_Y+LED_DIMMER_SIZE_Y ));

	voidWriteCommand(0x2C);


	switch (Copy_u8PwmValue)
	{
	case 0		: color = 0x0000; break ; /*black*/
	case 50		: color = 0x00f2; break ;
	case 100	: color = 0x00f5; break ;
	case 150	: color = 0x00f7; break ;
	case 200	: color = 0x00f9; break ;
	case 250	: color = 0x00ff; break ;
	default 	: color = 0x0000;  break;
	}
	for(Counter = 0 ; Counter < Local_u32Size -6  ; Counter ++)
	{
		if(Dimmer_Led [ Counter] == 0x0000) /*find the lightining element of the led */
		{
			voidWriteData((color)>> 8);				/* value varies  from 0x0000 to 0x00ff which is max red color */
			voidWriteData(color & 0x00ff);
		}
		else
		{
			voidWriteData(0xffff >> 8);
			voidWriteData(0xffff & 0x00ff);
		}

	}



}


void TFT_vDrawChangePassButton(){
TFT_vDrawPic(CHANGE_PASS_BUTT_X ,(CHANGE_PASS_BUTT_X+CHANGE_PASS_BUTT_X_SIZE) ,CHANGE_PASS_BUTT_Y ,(CHANGE_PASS_BUTT_Y + CHANGE_PASS_BUTT_Y_SIZE) ,ChangePAsswordPic);

}
void TFT_vUserPanel(void)
{
	TFT_vClearScreen();
	TFT_vDrawLeds();
	TFT_vDoorClosed();
	TFT_vDrawAcButton();
	TFT_vDrawAirConditioner();
	TFT_vDrawDimmerLed();
	TFT_vDrawChangePassButton();
}




void TFT_vDrawPassword(u8 Copy_u8PasswordIndex){
	TFT_vDrawStar(PASS_X+(Copy_u8PasswordIndex*PASS_SPACE),PASS_Y,STAR_SIZE,STAR_COLOR);
}

void HTFT_vDeletePassword(u8 Copy_u8PasswordIndex){
	TFT_vDrawStar(PASS_X+(Copy_u8PasswordIndex*PASS_SPACE),PASS_Y,STAR_SIZE,0xffff);// clearing it with sending color with while
}


void HTFT_vDrawKeyPad()
{

	TFT_vDrawPic(KEYPAD_X, KEYPAD_X+KEYPAD_X_SIZE, KEYPAD_Y, KEYPAD_Y+KEYPAD_Y_SIZE, KeyPadPic);
}

void TFT_vPasswordPanel()
{
	TFT_vClearScreen();
	TFT_vDrawPic(PASS_PIC_X ,PASS_PIC_X+PASS_PIC_X_SIZE ,PASS_PIC_Y,PASS_PIC_Y+PASS_PIC_Y_SIZE, PassScreen);			/*for password picture*/
	HTFT_vDrawKeyPad();
}


void TFT_vTrialLeft(u8 Copy_u8LeftTrials){

	TFT_vDrawPic(TRIAL_PIC_X ,TRIAL_PIC_X+TRIAL_PIC_X_SIZE ,TRIAL_PIC_Y,TRIAL_PIC_Y+TRIAL_PIC_Y_SIZE, TrialsLeftPic);
	TFT_vNumberAtPosition(TRIAL_NUM_X, TRIAL_NUM_Y, Copy_u8LeftTrials);

}
void TFT_vChangePasswordPanel(){
TFT_vClearScreen();
TFT_vDrawPic(NEW_PASS_X ,(NEW_PASS_X+NEW_PASS_X_SIZE) ,NEW_PASS_Y ,(NEW_PASS_Y + NEW_PASS_Y_SIZE) ,NewPassword);
TFT_vDrawPic(PASS_PIC_X ,PASS_PIC_X+PASS_PIC_X_SIZE ,PASS_PIC_Y,PASS_PIC_Y+PASS_PIC_Y_SIZE, PassScreen);			/*for password picture*/
HTFT_vDrawKeyPad();
}



void TFT_vPolicePanel()
{
	TFT_vClearScreen();
	TFT_vDrawPic(POLICE_X ,POLICE_X+POLICE_SIZE_X ,POLICE_Y,POLICE_Y+POLICE_SIZE_Y, Police);

}

void TFT_vDrawPixel(u8 x,u16 y, u16 color){
	TFT_vSetCursorPosition(x,y,x,y);
	/* RAM Write Command Every thing is coming After This Command Display on TFT*/
	voidWriteCommand(0x2C);
	/* Write The High Byte */
	voidWriteData(color >> 8);
	/* Write The LOW Byte */
	voidWriteData(color &0x00ff);
}

void TFT_vDrawHLine(u8 x1, u16 y1, u8 lenght, u16 color)
{
	u16 i = 0 ;
	for(;i<lenght ; i++)
	{
		TFT_vDrawPixel(x1+i,y1,color);
	}
}

void TFT_vDrawVLine(u8 x1, u16 y1, u16 lenght, u16 color){
	u16 i = 0 ;
	for(;i<lenght ; i++)
	{
		TFT_vDrawPixel(x1,y1+i,color);
	}
}

void TFT_vDrawPicturesPixels(u8 x1,u8 x2,u16 y1,u16 y2, u16*Copy_Image){
	u32 Counter =0 ;
	u16 x_max =( x2 - x1 );
	u16 y_max =( y2 - y1 );
	u16 xi=0;
	u16 yi=0;
	for (yi = 0 ; yi < y_max ; yi++)
	{
		for (xi = 0 ; xi < x_max ; xi++)
		{
			TFT_vDrawPixel(x1+xi,y1+yi,Copy_Image[Counter]);
			Counter++;
		}

	}

}

void TFT_vDrawUpTriangle(u8 x1, u16 y1, u8 size ,u16 color){
	u8 i = 0 ;

	for(;i<size ; i++)
	{
		TFT_vDrawHLine(x1+i,y1-i,(2*size-(2*i)-1),color);
	}

}

void TFT_vDrawDownTriangle(u8 x1, u16 y1, u8 size ,u16 color){
	u8 i = 0 ;

	for(;i<size ; i++)
	{
		TFT_vDrawHLine(x1+i,y1+i,(2*size-(2*i)-1),color);
	}
}

void TFT_vDrawRectangle(u8 x1, u8 x2,u16 y1, u16 y2 , u16 color)
{

	TFT_vDrawHLine(x1,y1,(x2-x1),color);
	TFT_vDrawVLine(x1,y1,(y2-y1),color);
	TFT_vDrawHLine(x1,y2,(x2-x1),color);
	TFT_vDrawVLine(x2,y1,(y2-y1),color);
}

void TFT_vDrawStar(u8 x1, u16 y1, u8 size, u16 color)
{
	int i = 0 ;
	TFT_vDrawHLine(x1,y1,size,color);
	TFT_vDrawVLine(x1+(u8)(size/2),y1-(u8)(size/2),size,color);
	for(i=0 ; i<size-2; i++){
		if(i==(size/2)-2	|| i == (size/2) || i == (size/2)-1){continue;}
		TFT_vDrawPixel(x1+i+1, y1-(size/2 )+1+i, color);
	}
	for(i=0 ; i<size-2; i++){
		if(i==(size/2)-2	|| i == (size/2) || i == (size/2)-1){continue;}
		TFT_vDrawPixel(x1+i+1, y1+(size/2) -1-i, color);
	}
}
