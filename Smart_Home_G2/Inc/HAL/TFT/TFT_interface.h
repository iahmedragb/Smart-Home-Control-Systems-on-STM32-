/*
 * TFT_interface.h
 *
 *  Created on: April 25, 2022
 *  Author    : Abdelhai Tahoon
 *  Version   : 1.0
 */

#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

void TFT_voidInit(void);

void TFT_vClearScreen();

void TFT_vUserPanel(void);
void TFT_vPasswordPanel();
void TFT_vPolicePanel();

void TFT_vLedOn(u8 led_num);
void TFT_vLedOff(u8 led_num);
void TFT_vToggle(u8 led_num);

/*takes value from 0 to 255 */

void TFT_vControlDimmerLed( u8 Copy_u8PwmValue);

void TFT_vDoorOpened();
void TFT_vDoorClosed();

void TFT_vAcOn();
void TFT_vAcOff();

void TFT_vDrawPassword(u8 Copy_u8PasswordIndex);
void TFT_vDrawTempValue(u16 Num);
void TFT_vChangePasswordPanel();

void TFT_vTrialLeft(u8 Copy_u8LeftTrials);

/* takes coordinates of the picture*/
void TFT_vDrawPic(u8 x1,u8 x2,u16 y1,u16 y2, u16*Copy_Image);


void TFT_vDrawPicturesPixels(u8 x1,u8 x2,u16 y1,u16 y2, u16*Copy_Image);

void TFT_vDrawAirConditioner();
void TFT_vAcButton();

#endif //TFT_INTERFACE_H
