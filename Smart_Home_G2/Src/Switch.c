
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
		#include "MCAL/STK/STK_Config.h"
		#include "MCAL/STK/STK.h"
/*======================================*/
#include "HAL/Switch/Switch_Config.h"
#include "HAL/Switch/Switch.h"

/*===========  INCLUDE HAL   ===========*/
void Switch_Init(void)
{
	u8 L_u8Iter;
	for(L_u8Iter=0;L_u8Iter<Switch_u8SwitchNum;L_u8Iter++)
	{
		GPIO_vSetMode(Switch[L_u8Iter].Switch_Port, Switch[L_u8Iter].Switch_Pin, GPIO_Input);
		GPIO_vSetPullUpPullDown(Switch[L_u8Iter].Switch_Port, Switch[L_u8Iter].Switch_Pin, Switch[L_u8Iter].Switch_Input_type);
	}
}
u8 Switch_Read(Switch_t *pstrSwitch_Info)
{
	u8 L_u8ReadValue = NOT_PRESSED;
	GPIO_vGetPinValue(pstrSwitch_Info->Switch_Port, pstrSwitch_Info->Switch_Pin, &L_u8ReadValue);
	if(pstrSwitch_Info->Switch_Input_type == Pull_Up)
	{
		if(L_u8ReadValue == LowState)
		{
			STK_DelayMs(10);
			GPIO_vGetPinValue(pstrSwitch_Info->Switch_Port, pstrSwitch_Info->Switch_Pin, &L_u8ReadValue);
			if(L_u8ReadValue == LowState)
			{
				while(L_u8ReadValue == LowState)
							{
								GPIO_vGetPinValue(pstrSwitch_Info->Switch_Port, pstrSwitch_Info->Switch_Pin, &L_u8ReadValue);
							}
							return LowState;
			}

		}
	}else if(pstrSwitch_Info->Switch_Input_type == Pull_Down)
	{
		if(L_u8ReadValue == HighState)
				{
			STK_DelayMs(10);
			GPIO_vGetPinValue(pstrSwitch_Info->Switch_Port, pstrSwitch_Info->Switch_Pin, &L_u8ReadValue);
			if(L_u8ReadValue == HighState)
			{
				while(L_u8ReadValue == HighState)
									{
										GPIO_vGetPinValue(pstrSwitch_Info->Switch_Port, pstrSwitch_Info->Switch_Pin, &L_u8ReadValue);
									}
									return HighState;
			}


				}
	}
	return NOT_PRESSED;
}
