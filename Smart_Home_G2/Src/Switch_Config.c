
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
#include "HAL/Switch/Switch_Config.h"
#include "HAL/Switch/Switch.h"
/*===========  INCLUDE HAL   ===========*/

u8 Switch_u8SwitchNum= SWITCH_NUM;
Switch_t Switch[SWITCH_NUM]=
{
		{GPIO_A,Pin6,Pull_Up},
		{GPIO_B,Pin3,Pull_Up},
		{GPIO_B,Pin4,Pull_Up},
		{GPIO_A,Pin0,Pull_Down},
};

