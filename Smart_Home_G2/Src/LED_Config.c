
/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "LIB/Std_Types.h"
		 #include "LIB/Bit_Math.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "MCAL/GPIO/GPIO.h"
/*======================================*/
#include "HAL/LED/LED_Config.h"
#include "HAL/LED/LED.h"
/*===========  INCLUDE HAL   ===========*/

u8 LED_u8LEDNum= LED_NUM;
LED_t LED[LED_NUM]=
{
		{GPIO_A,Pin5},
		{GPIO_B,Pin1},
		{GPIO_B,Pin2},
		{GPIO_C,Pin9}
};

