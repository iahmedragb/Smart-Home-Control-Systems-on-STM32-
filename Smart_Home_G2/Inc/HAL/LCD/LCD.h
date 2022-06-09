/*
 * LCD.h
 *
 *  Created on: Apr 22, 2022
 *      Author: Ahmed
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

void LCD_enuInit(void);
void LCD_enuWriteCommand(u8 Copy_u8Command);
void LCD_enuWriteData(u8 Copy_u8Data);
void LCD_enuWriteString( u8 *Copy_pu8String);
void LCD_enuWriteIntegerNum(s32 Copy_s32IntegerNum);
void LCD_enuWriteFloatNum(f32 Copy_f32FloatNum);
void LCD_enuGoToPosition(u8 Copy_u8Row, u8 Copy_u8Column);
void LCD_enuCharacterGenerator(u8 Pattern, const u8 *Copy_u8CustomCharacter);
void LCD_enuStopWatch(u8 Seconds,u8  Minutes,u8  Hours);


/*Commands List*/
#define LCD_COMMAND_CLEAR_DISPLAY						0x01
#define LCD_COMMAND_RETURN_HOME							0x02
#define LCD_COMMAND_DECREMENT_CURSOR					0x04
#define LCD_COMMAND_INCREMENT_CURSOR					0x06
#define LCD_COMMAND_SHIFT_DISPLAY_RIGHT					0x05
#define LCD_COMMAND_SHIFT_DISPLAY_LEFT					0x07
#define LCD_COMMAND_DISPLAY_OFF_CURSOR_OFF				0x08
#define LCD_COMMAND_DISPLAY_OFF_CURSOR_ON				0x0A
#define LCD_COMMAND_DISPLAY_ON_CURSOR_OFF				0x0C
#define LCD_COMMAND_DISPLAY_ON_CURSOR_BLINK				0x0E
#define LCD_COMMAND_DISPLAY_ON_CURSOR_BLINK2			0x0F
#define LCD_COMMAND_SHIFT_CURSOR_LEFT					0x10
#define LCD_COMMAND_SHIFT_CURSOR_RIGHT					0x14
#define LCD_COMMAND_SHIFT_ENTIRE_DISPLAY_RIGHT			0x1C
#define LCD_COMMAND_SHIFT_ENTIRE_DISPLAY_LEFT			0x18
#define LCD_COMMAND_FORCE_CURSOR_1ST_LINE_1ST_POSITION	0x80
#define LCD_COMMAND_FORCE_CURSOR_2ND_LINE_1ST_POSITION	0xC0
#define LCD_COMMAND_2LINES_FIVE_X_7_4BIT				0x28
#define LCD_COMMAND_2LINES_FIVE_X_7_8BIT				0x38

#endif /* HAL_LCD_LCD_H_ */
