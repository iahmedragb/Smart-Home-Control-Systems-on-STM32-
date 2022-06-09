/*
 * LCD_Private.h
 *
 *  Created on: Apr 22, 2022
 *      Author: Ahmed
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_
typedef enum
{
	LCD_D0=0,
	LCD_D1=1,
	LCD_D2=2,
	LCD_D3=3,
	LCD_D4=4,
	LCD_D5=5,
	LCD_D6=6,
	LCD_D7=7
}LCD_Data_PinNum_t;
#define FOUR_BIT_MODE			0
#define EIGHT_BIT_MODE			1

#define SINGLE_LINE_MODE		0
#define DOUBLE_LINE_MODE		1

#define FIVE_x7					0
#define FIVE_x11				1

#define DISPLAY_OFF				0
#define DISPLAY_ON				1

#define CURSOR_OFF				0
#define CURSOR_ON				1

#define BLINK_OFF				0
#define BLINK_ON				1

#define DECREMENT				0
#define INCREMENT				1

#define NO_DISPLAY_SHIFT		0
#define DISPLAY_SHIFT			1


#define PATTERN0		(*(volatile u8*)(0x40))
#define PATTERN1		(*(volatile u8*)(0x48))
#define PATTERN2		(*(volatile u8*)(0x50))
#define PATTERN3		(*(volatile u8*)(0x58))
#define PATTERN4		(*(volatile u8*)(0x60))
#define PATTERN5		(*(volatile u8*)(0x68))
#define PATTERN6		(*(volatile u8*)(0x70))
#define PATTERN7		(*(volatile u8*)(0x78))



static void LCD_enuLatch(u8 Copy_u8Latch);


#endif /* HAL_LCD_LCD_PRIVATE_H_ */
