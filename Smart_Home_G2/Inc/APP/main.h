/*
 * main.h
 *
 *  Created on: Apr 15, 2022
 *      Author: Ahmed
 */

#ifndef APP_MAIN_H_
#define APP_MAIN_H_

#include "LIB/Std_Types.h"
#include "LIB/Bit_Math.h"
#include "LIB/Error_State.h"

#include "MCAL/RCC/RCC.h"
#include "MCAL/GPIO/GPIO.h"
#include "MCAL/EXTI/EXTI.h"
#include "MCAL/SYSCFG/SYSCFG.h"
#include "MCAL/NVIC/NVIC.h"
#include "MCAL/STK/STK.h"
#include "MCAL/UART/UART.h"
#include "MCAL/ADC/ADC.h"
#include "MCAL/TIM/TIM.h"
#include "MCAL/SPI/SPI_interface.h"

#include "HAL/LED/LED.h"
#include "HAL/Switch/Switch.h"
#include "HAL/LCD/LCD.h"
#include "HAL/Keypad/Keypad.h"
#include "HAL/AC/AC.h"
#include "HAL/Door/Door.h"
#include "HAL/HC05/HC05.h"

#include "HAL/TFT/TFT_interface.h"
#include "HAL/TFT/TFT_images.h"


/********************headers***************************/
u8 strEqual(s8* Copy_ps8str1 , s8* Copy_ps8str2);
void PasswordTap(s8* RightPassword,s8* MasterPassword  );
void WelcomeTap(s8* Copy_ps8RightPassword);
void WrongTap(u8* Copy_ps8wrongInputRemain);
void BeebSound(void);
void Buzzer_TOG(void );



/**/
#define STR_NEQL 				0
#define STR_EQL 				1
#define MAX_PASS_NUM			4
#define WRONG_INPUTS_ALLOWED	3

#define START_TEMP				25

#define PASS_CHANGE 			'+'
#define SYS_LOCK	 			'='
#define TEMP_UP 				'C'
#define TEMP_DOWN	 			'0'
#define DOOR_OPEN 				'1'
#define DOOR_CLOSE	 			'2'
#define BRIGHTNESS_UP	 		'4'
#define BRIGHTNESS_DOWN	 		'5'
#define LED_1_BUTTON 			'7'
#define LED_2_BUTTON 			'8'
#define LED_3_BUTTON 			'9'
#define LED_4_BUTTON 			'/'


#endif /* APP_MAIN_H_ */
