
/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "LIB/Std_Types.h"
		 #include "LIB/Bit_Math.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "MCAL/SYSCFG/SYSCFG_Private.h"
		#include "MCAL/SYSCFG/SYSCFG.h"
		#include "MCAL/SYSCFG/SYSCFG_Config.h"
/*======================================*/
/*===========  INCLUDE HAL   ===========*/


/*======================================*/

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/


/*====================================================   Start_FUNCTION   ====================================================*/
void SYSCFG_vEXTILineInputSource(EXTI_LineNum Copy_u8EXTILine,EXTI_Port Copy_u8EXTIPort)
{
	if((Copy_u8EXTILine <= Line_15)&&((Copy_u8EXTIPort<=EXTI_PE)||(Copy_u8EXTIPort == EXTI_PH)))
	{
		SYSCFG->EXTICR[(Copy_u8EXTILine/4U)] |= (Copy_u8EXTIPort<<(4U*(Copy_u8EXTILine%4U)));
	}else
	{
		/*error*/
	}
}
/*====================================================   END_ FUNCTION   ====================================================*/
