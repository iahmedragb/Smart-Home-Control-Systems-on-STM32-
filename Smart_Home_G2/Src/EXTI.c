
/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "LIB/Std_Types.h"
		 #include "LIB/Bit_Math.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "MCAL/EXTI/EXTI_Private.h"
		#include "MCAL/EXTI/EXTI.h"
		#include "MCAL/EXTI/EXTI_Config.h"
/*======================================*/
/*===========  INCLUDE HAL   ===========*/


/*======================================*/

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/

static void(*EXTI_ApAppFun[16])(void*)={NULL};
static void*EXTI_ApAppFunParameter[16]={NULL};
/*====================================================   Start_FUNCTION   ====================================================*/
void EXTI_vEnableLine(EXTI_Line Copy_u8EXTILine,EXTI_Trigger Copy_u8EXTITrigger)
{
	if((Copy_u8EXTILine<= EXTI_15)&&(Copy_u8EXTITrigger <=ANY_CHANGE))
	{
		EXTI->IMR |= (1U<<Copy_u8EXTILine);
		switch(Copy_u8EXTITrigger)
		{
		case RISING:EXTI->RTSR |= (1U<<Copy_u8EXTILine);break;
		case FALLING:EXTI->FTSR |= (1U<<Copy_u8EXTILine);break;
		case ANY_CHANGE:
			EXTI->RTSR |= (1U<<Copy_u8EXTILine);
			EXTI->FTSR |= (1U<<Copy_u8EXTILine);
			break;
		default: //error
			break;
		}
	}else
	{
		//error
	}
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
void EXTI_vDisableLine(EXTI_Line Copy_u8EXTILine)
{
	if(Copy_u8EXTILine<= EXTI_15)
		{
			EXTI->IMR &=~ (1U<<Copy_u8EXTILine);
		}else
		{
			//error
		}
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
void EXTI_vSoftwareInterruptEvent(EXTI_Line Copy_u8EXTILine)
{
	if(Copy_u8EXTILine<= EXTI_15)
			{
				EXTI->SWIER |= (1U<<Copy_u8EXTILine);
			}else
			{
				//error
			}
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
void EXTI_vCallBack(EXTI_Line Copy_u8EXTILine, void(*pAppFun)(void*),void* Copy_pvAppFunParameter)
{
	if((Copy_u8EXTILine<=EXTI_15)&&(pAppFun!=NULL))
	{
		EXTI_ApAppFun[Copy_u8EXTILine] = pAppFun;
		if(Copy_pvAppFunParameter !=NULL)
		{
			EXTI_ApAppFunParameter[Copy_u8EXTILine] = Copy_pvAppFunParameter;
		}
	}
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
void EXTI0_IRQHandler(void)
{
	SET_BIT(EXTI -> PR , EXTI_0);
	if(EXTI_ApAppFun[EXTI_0]!=NULL)
	{
		if(EXTI_ApAppFunParameter[EXTI_0]!=NULL)
		{
			EXTI_ApAppFun[EXTI_0](EXTI_ApAppFunParameter[EXTI_0]);
		}else
		{
			EXTI_ApAppFun[EXTI_0](NULL);
		}
	}else
	{
		//error
	}

}
void EXTI1_IRQHandler(void)
{
	SET_BIT(EXTI -> PR , EXTI_1);
	if(EXTI_ApAppFun[EXTI_1]!=NULL)
	{
		if(EXTI_ApAppFunParameter[EXTI_1]!=NULL)
		{
			EXTI_ApAppFun[EXTI_1](EXTI_ApAppFunParameter[EXTI_1]);
		}else
		{
			EXTI_ApAppFun[EXTI_1](NULL);
		}
	}else
	{
		//error
	}

}
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);
void EXTI4_IRQHandler(void);
void EXTI5_IRQHandler(void);
void EXTI6_IRQHandler(void);
void EXTI7_IRQHandler(void);
void EXTI8_IRQHandler(void);
void EXTI9_IRQHandler(void);
void EXTI10_IRQHandler(void);
void EXTI11_IRQHandler(void);
void EXTI12_IRQHandler(void);
void EXTI13_IRQHandler(void);
void EXTI14_IRQHandler(void);
void EXTI15_IRQHandler(void);
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/

/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/

/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/

/*====================================================   END_ FUNCTION   ====================================================*/
