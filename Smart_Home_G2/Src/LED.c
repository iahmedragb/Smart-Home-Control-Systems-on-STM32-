
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
/*======================================*/
#include "HAL/LED/LED_Config.h"
#include "HAL/LED/LED.h"

/*===========  INCLUDE HAL   ===========*/
void LED_Init(void)
{
	u8 L_u8Iter;
	for(L_u8Iter=0;L_u8Iter<LED_u8LEDNum;L_u8Iter++)
	{
		GPIO_vSetMode(LED[L_u8Iter].LED_Port, LED[L_u8Iter].LED_Pin, GPIO_Output);
	}
}
void LED_On(LED_t *pstrLED_Info)
{
	GPIO_vWritePinValue(pstrLED_Info->LED_Port, pstrLED_Info->LED_Pin, HighState);

}
void LED_Off(LED_t *pstrLED_Info)
{
	GPIO_vWritePinValue(pstrLED_Info->LED_Port, pstrLED_Info->LED_Pin, LowState);
}
