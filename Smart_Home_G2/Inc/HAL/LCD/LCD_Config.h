/*
 * LCD_Config.h
 *
 *  Created on: Apr 22, 2022
 *      Author: Ahmed
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

#define LCD_CTRL_RS_GPIO_PORT		GPIO_D
#define LCD_CTRL_RW_GPIO_PORT		GPIO_D
#define LCD_CTRL_EN_GPIO_PORT		GPIO_D
#define LCD_DATA_D0_GPIO_PORT		GPIO_D
#define LCD_DATA_D1_GPIO_PORT		GPIO_D
#define LCD_DATA_D2_GPIO_PORT		GPIO_D
#define LCD_DATA_D3_GPIO_PORT		GPIO_D
#define LCD_DATA_D4_GPIO_PORT		GPIO_D
#define LCD_DATA_D5_GPIO_PORT		GPIO_D
#define LCD_DATA_D6_GPIO_PORT		GPIO_D
#define LCD_DATA_D7_GPIO_PORT		GPIO_D

#define LCD_CTRL_RS_GPIO_PIN_NUM		Pin13
#define LCD_CTRL_RW_GPIO_PIN_NUM		Pin14
#define LCD_CTRL_EN_GPIO_PIN_NUM		Pin15
#define LCD_DATA_D0_GPIO_PIN_NUM		Pin3
#define LCD_DATA_D1_GPIO_PIN_NUM		Pin4
#define LCD_DATA_D2_GPIO_PIN_NUM		Pin5
#define LCD_DATA_D3_GPIO_PIN_NUM		Pin6
#define LCD_DATA_D4_GPIO_PIN_NUM		Pin9
#define LCD_DATA_D5_GPIO_PIN_NUM		Pin10
#define LCD_DATA_D6_GPIO_PIN_NUM		Pin11
#define LCD_DATA_D7_GPIO_PIN_NUM		Pin12

/*Function Set*/

/*LCD MODE			EIGHT_BIT_MODE		or		FOUR_BIT_MODE*/
#define LCD_MODE	FOUR_BIT_MODE
/*DISPLAY_LINES		SINGLE_LINE_MODE	or		DOUBLE_LINE_MODE*/
#define N_DISPLAY_LINES	DOUBLE_LINE_MODE
/*DISPLAY_FONT		FIVE_x7	or		FIVE_x11*/
#define F_DISPLAY_FONT	FIVE_x7

/*DISPLAY Control*/
/*DISPLAY_MODE		DISPLAY_ON		or		DISPLAY_OFF*/
#define D_DISPLAY_MODE	DISPLAY_ON
/*CURSOR_MODE		CURSOR_ON		or		CURSOR_OFF*/
#define C_CURSOR_MODE		CURSOR_OFF
/*BLINK_MODE		BLINK_ON		or		BLINK_OFF*/
#define B_BLINK_MODE		BLINK_OFF

/*Entry Mode Set*/
/*INCREMENT_MODE		INCREMENT		or		DECREMENT*/
#define ID_INCREMENT_MODE		INCREMENT
/*SHIFT_MODE		NO_DISPLAY_SHIFT		or		DISPLAY_SHIFT*/
#define SH_SHIFT_MODE		NO_DISPLAY_SHIFT





#define DATA_PATTERN0		0
#define DATA_PATTERN1		1
#define DATA_PATTERN2		2
#define DATA_PATTERN3		3
#define DATA_PATTERN4		4
#define DATA_PATTERN5		5
#define DATA_PATTERN6		6
#define DATA_PATTERN7		7



#endif /* HAL_LCD_LCD_CONFIG_H_ */
