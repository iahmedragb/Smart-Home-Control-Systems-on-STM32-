
/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "LIB/Std_Types.h"
		 #include "LIB/Bit_Math.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "MCAL/GPIO/GPIO_Config.h"
		#include "MCAL/GPIO/GPIO.h"
		#include "MCAL/STK/STK.h"

/*======================================*/
#include "HAL/LCD/LCD_Private.h"
#include "HAL/LCD/LCD_Config.h"
#include "HAL/LCD/LCD.h"

/*===========  INCLUDE HAL   ===========*/

void LCD_enuInit(void)
{
	STK_DelayMs(35);
	GPIO_vSetMode(LCD_CTRL_RS_GPIO_PORT, LCD_CTRL_RS_GPIO_PIN_NUM, GPIO_Output);
	GPIO_vSetMode(LCD_CTRL_RW_GPIO_PORT, LCD_CTRL_RW_GPIO_PIN_NUM, GPIO_Output);
	GPIO_vSetMode(LCD_CTRL_EN_GPIO_PORT, LCD_CTRL_EN_GPIO_PIN_NUM, GPIO_Output);

	GPIO_vSetMode(LCD_DATA_D4_GPIO_PORT, LCD_DATA_D4_GPIO_PIN_NUM, GPIO_Output);
	GPIO_vSetMode(LCD_DATA_D5_GPIO_PORT, LCD_DATA_D5_GPIO_PIN_NUM, GPIO_Output);
	GPIO_vSetMode(LCD_DATA_D6_GPIO_PORT, LCD_DATA_D6_GPIO_PIN_NUM, GPIO_Output);
	GPIO_vSetMode(LCD_DATA_D7_GPIO_PORT, LCD_DATA_D7_GPIO_PIN_NUM, GPIO_Output);

	#if LCD_MODE == EIGHT_BIT_MODE

	GPIO_vSetMode(LCD_DATA_D0_GPIO_PORT, LCD_DATA_D0_GPIO_PIN_NUM, GPIO_Output);
	GPIO_vSetMode(LCD_DATA_D1_GPIO_PORT, LCD_DATA_D1_GPIO_PIN_NUM, GPIO_Output);
	GPIO_vSetMode(LCD_DATA_D2_GPIO_PORT, LCD_DATA_D2_GPIO_PIN_NUM, GPIO_Output);
	GPIO_vSetMode(LCD_DATA_D3_GPIO_PORT, LCD_DATA_D3_GPIO_PIN_NUM, GPIO_Output);

	GPIO_vWritePinValue(LCD_CTRL_RS_GPIO_PORT, LCD_CTRL_RS_GPIO_PIN_NUM, LowState);

	/*Function Set*/
	STK_DelayMs(35);

	//LCD_enuLatch((0x30 | (N_DISPLAY_LINES<<3)|(F_DISPLAY_FONT<<2)));
	LCD_enuLatch(0x38);
	STK_DelayMs(1);
	#elif LCD_MODE == FOUR_BIT_MODE

	GPIO_vWritePinValue(LCD_CTRL_RS_GPIO_PORT, LCD_CTRL_RS_GPIO_PIN_NUM, LowState);
	/*Function Set*/
	GPIO_vWritePinValue(LCD_DATA_D4_GPIO_PORT, LCD_DATA_D4_GPIO_PIN_NUM, LowState);
	GPIO_vWritePinValue(LCD_DATA_D5_GPIO_PORT, LCD_DATA_D5_GPIO_PIN_NUM, HighState);
	GPIO_vWritePinValue(LCD_DATA_D6_GPIO_PORT, LCD_DATA_D6_GPIO_PIN_NUM, LowState);
	GPIO_vWritePinValue(LCD_DATA_D7_GPIO_PORT, LCD_DATA_D7_GPIO_PIN_NUM, LowState);

	GPIO_vWritePinValue(LCD_CTRL_EN_GPIO_PORT, LCD_CTRL_EN_GPIO_PIN_NUM, HighState);
	STK_DelayMs(5);
	GPIO_vWritePinValue(LCD_CTRL_EN_GPIO_PORT, LCD_CTRL_EN_GPIO_PIN_NUM, LowState);
	STK_DelayMs(5);

	LCD_enuLatch((0x20 | (N_DISPLAY_LINES<<3)|(F_DISPLAY_FONT<<2)));
	STK_DelayMs(1);
	#else
	#error "Undefined LCD Mode"
	#endif
	/*Display Control*/
	LCD_enuLatch((0x08)|(D_DISPLAY_MODE<<2)|(C_CURSOR_MODE<<1)|(B_BLINK_MODE<<0));
	STK_DelayMs(1);
	/*Display Clear*/
	LCD_enuLatch(LCD_COMMAND_CLEAR_DISPLAY);
	STK_DelayMs(2);
	/*Entry Set*/
	LCD_enuLatch((0x04)|(ID_INCREMENT_MODE<<1)|(SH_SHIFT_MODE<<0));
}
void LCD_enuWriteCommand(u8 Copy_u8Command)
{
	GPIO_vWritePinValue(LCD_CTRL_RS_GPIO_PORT, LCD_CTRL_RS_GPIO_PIN_NUM, LowState);
	GPIO_vWritePinValue(LCD_CTRL_RW_GPIO_PORT, LCD_CTRL_RW_GPIO_PIN_NUM, LowState);
	GPIO_vWritePinValue(LCD_CTRL_EN_GPIO_PORT, LCD_CTRL_EN_GPIO_PIN_NUM, LowState);
	LCD_enuLatch(Copy_u8Command);
}
void LCD_enuWriteData(u8 Copy_u8Data)
{
	GPIO_vWritePinValue(LCD_CTRL_RS_GPIO_PORT, LCD_CTRL_RS_GPIO_PIN_NUM, HighState);
	GPIO_vWritePinValue(LCD_CTRL_RW_GPIO_PORT, LCD_CTRL_RW_GPIO_PIN_NUM, LowState);
	GPIO_vWritePinValue(LCD_CTRL_EN_GPIO_PORT, LCD_CTRL_EN_GPIO_PIN_NUM, LowState);
	LCD_enuLatch(Copy_u8Data);
}
void LCD_enuWriteString( u8 *Copy_pu8String)
{
	if(Copy_pu8String != NULL)
	{
		u8 Local_u8iter = 0;
		while(Copy_pu8String[Local_u8iter] != '\0')
		{
			LCD_enuWriteData(Copy_pu8String[Local_u8iter++]);
		}
	//	Local_u8ErrorState = ES_OK;
	}else
	{
		//Local_u8ErrorState = ES_NULL_POINTER;
	}
	//return Local_u8ErrorState;
}
void LCD_enuWriteIntegerNum(s32 Copy_s32IntegerNum)
{
	//u8 Local_u8ErrorState = ES_NOK;
	if(Copy_s32IntegerNum == 0)
	{
		LCD_enuWriteData('0');
		//Local_u8ErrorState = ES_OK;
	}else
	{
		if(Copy_s32IntegerNum<0)
		{
			LCD_enuWriteData('-');
			Copy_s32IntegerNum *= (-1);
		}
		u32 Local_u32Num = 0,Local_u32DecimalUnit=10;
		u8 Local_u8Digits=0;
		while(Copy_s32IntegerNum)
		{
			Local_u8Digits++;
			Local_u32Num *= Local_u32DecimalUnit;

			Local_u32Num += (Copy_s32IntegerNum%10) ;
			Copy_s32IntegerNum /= 10;

		}
		while(Local_u8Digits)
		{
			LCD_enuWriteData((Local_u32Num%10)+'0');
			Local_u32Num /=10;
			Local_u8Digits--;
		}
		//Local_u8ErrorState = ES_OK;
	}
	//return Local_u8ErrorState;
}
void LCD_enuWriteFloatNum(f32 Copy_f32FloatNum)
{
	//u8 Local_u8ErrorState = ES_NOK;
	if(Copy_f32FloatNum == 0)
	{
		LCD_enuWriteData('0');
		//Local_u8ErrorState = ES_OK;
	}else
	{
		s32 Local_s32DecimalVal = Copy_f32FloatNum;
		LCD_enuWriteIntegerNum(Local_s32DecimalVal);
		LCD_enuWriteData('.');
		Copy_f32FloatNum -= Local_s32DecimalVal;
		Copy_f32FloatNum *= 1000000;
		Local_s32DecimalVal = Copy_f32FloatNum;
		while((Local_s32DecimalVal%10 == 0))
		{
			Local_s32DecimalVal /=10;
		}
		LCD_enuWriteIntegerNum(Local_s32DecimalVal);

		//Local_u8ErrorState = ES_OK;
	}
	//return Local_u8ErrorState;
}
void LCD_enuGoToPosition(u8 Copy_u8Row, u8 Copy_u8Column)
{
	//u8 Local_u8ErrorState = ES_NOK;
	if(Copy_u8Row<=2 && Copy_u8Column<=16)
	{
		switch(Copy_u8Row)
		{
			case  1 :
			LCD_enuWriteCommand((0x80)+Copy_u8Column-1);
		//	Local_u8ErrorState = ES_OK;
			break;
			case 2 :
			LCD_enuWriteCommand((0xC0)+Copy_u8Column-1);
			//Local_u8ErrorState = ES_OK;
			break;
			default:break;
			//Local_u8ErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		//Local_u8ErrorState = ES_OUT_OF_RANGE;
	}
	//return Local_u8ErrorState;
}
void LCD_enuCharacterGenerator(u8 Pattern, const u8 *Copy_u8CustomCharacter)
{
	//u8 Local_u8ErrorState = ES_NOK;
	if(Copy_u8CustomCharacter != NULL)
	{
		LCD_enuWriteCommand((0x40)+(8*Pattern));
		u8 Local_u8Iter = 0;
		for(;Local_u8Iter<8 ; Local_u8Iter++)
		{
			LCD_enuWriteData(Copy_u8CustomCharacter[Local_u8Iter]);
		}
	}else
	{
		//Local_u8ErrorState = ES_NULL_POINTER;
	}
	//return Local_u8ErrorState;
}

static void LCD_enuLatch(u8 Copy_u8Latch)
{
	GPIO_vWritePinValue(LCD_CTRL_RW_GPIO_PORT, LCD_CTRL_RW_GPIO_PIN_NUM, LowState);
	GPIO_vWritePinValue(LCD_CTRL_EN_GPIO_PORT, LCD_CTRL_EN_GPIO_PIN_NUM, LowState);

	#if LCD_MODE == EIGHT_BIT_MODE
	GPIO_vWritePinValue(LCD_DATA_D0_GPIO_PORT, LCD_DATA_D0_GPIO_PIN_NUM, ((Copy_u8Latch>>LCD_D0)& (1U)));
	GPIO_vWritePinValue(LCD_DATA_D1_GPIO_PORT, LCD_DATA_D1_GPIO_PIN_NUM, ((Copy_u8Latch>>LCD_D1)& (1U)));
	GPIO_vWritePinValue(LCD_DATA_D2_GPIO_PORT, LCD_DATA_D2_GPIO_PIN_NUM, ((Copy_u8Latch>>LCD_D2)& (1U)));
	GPIO_vWritePinValue(LCD_DATA_D3_GPIO_PORT, LCD_DATA_D3_GPIO_PIN_NUM, ((Copy_u8Latch>>LCD_D3)& (1U)));
	GPIO_vWritePinValue(LCD_DATA_D4_GPIO_PORT, LCD_DATA_D4_GPIO_PIN_NUM, ((Copy_u8Latch>>LCD_D4)& (1U)));
	GPIO_vWritePinValue(LCD_DATA_D5_GPIO_PORT, LCD_DATA_D5_GPIO_PIN_NUM, ((Copy_u8Latch>>LCD_D5)& (1U)));
	GPIO_vWritePinValue(LCD_DATA_D6_GPIO_PORT, LCD_DATA_D6_GPIO_PIN_NUM, ((Copy_u8Latch>>LCD_D6)& (1U)));
	GPIO_vWritePinValue(LCD_DATA_D7_GPIO_PORT, LCD_DATA_D7_GPIO_PIN_NUM, ((Copy_u8Latch>>LCD_D7)& (1U)));

	#elif LCD_MODE == FOUR_BIT_MODE
	GPIO_vWritePinValue(LCD_DATA_D4_GPIO_PORT, LCD_DATA_D4_GPIO_PIN_NUM, ((Copy_u8Latch>>LCD_D4)& (1U)));
	GPIO_vWritePinValue(LCD_DATA_D5_GPIO_PORT, LCD_DATA_D5_GPIO_PIN_NUM, ((Copy_u8Latch>>LCD_D5)& (1U)));
	GPIO_vWritePinValue(LCD_DATA_D6_GPIO_PORT, LCD_DATA_D6_GPIO_PIN_NUM, ((Copy_u8Latch>>LCD_D6)& (1U)));
	GPIO_vWritePinValue(LCD_DATA_D7_GPIO_PORT, LCD_DATA_D7_GPIO_PIN_NUM, ((Copy_u8Latch>>LCD_D7)& (1U)));

	GPIO_vWritePinValue(LCD_CTRL_EN_GPIO_PORT, LCD_CTRL_EN_GPIO_PIN_NUM, HighState);
	STK_DelayMs(5);
	GPIO_vWritePinValue(LCD_CTRL_EN_GPIO_PORT, LCD_CTRL_EN_GPIO_PIN_NUM, LowState);
	STK_DelayMs(5);

	GPIO_vWritePinValue(LCD_DATA_D4_GPIO_PORT, LCD_DATA_D4_GPIO_PIN_NUM, ((Copy_u8Latch>>LCD_D0)& (1U)));
	GPIO_vWritePinValue(LCD_DATA_D5_GPIO_PORT, LCD_DATA_D5_GPIO_PIN_NUM, ((Copy_u8Latch>>LCD_D1)& (1U)));
	GPIO_vWritePinValue(LCD_DATA_D6_GPIO_PORT, LCD_DATA_D6_GPIO_PIN_NUM, ((Copy_u8Latch>>LCD_D2)& (1U)));
	GPIO_vWritePinValue(LCD_DATA_D7_GPIO_PORT, LCD_DATA_D7_GPIO_PIN_NUM, ((Copy_u8Latch>>LCD_D3)& (1U)));

	#else
	#error "Undefined LCD Mode"
	#endif
	GPIO_vWritePinValue(LCD_CTRL_EN_GPIO_PORT, LCD_CTRL_EN_GPIO_PIN_NUM, HighState);

	STK_DelayMs(5);
	GPIO_vWritePinValue(LCD_CTRL_EN_GPIO_PORT, LCD_CTRL_EN_GPIO_PIN_NUM, LowState);
	STK_DelayMs(5);

}




void LCD_enuStopWatch(u8 Seconds,u8  Minutes,u8  Hours)
{
	/*Hours Display*/
	LCD_enuGoToPosition(1,5);
	if(Hours<=9)
	{
		LCD_enuWriteData('0');
	}
	LCD_enuWriteIntegerNum(Hours);
	LCD_enuWriteData(':');
	/*Minutes Display*/
	if(Minutes<=9)
	{
		LCD_enuWriteData('0');
	}
	LCD_enuWriteIntegerNum(Minutes);
	LCD_enuWriteData(':');
	/*Seconds Display*/
	if(Seconds<=9)
	{
		LCD_enuWriteData('0');
	}
	LCD_enuWriteIntegerNum(Seconds);
	LCD_enuWriteCommand(0xC0);


	//return ES_OK;
}
