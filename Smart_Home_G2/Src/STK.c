/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
#include "LIB/Std_Types.h"
#include "LIB/Bit_Math.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
#include "MCAL/STK/STK_Private.h"
#include "MCAL/STK/STK.h"
#include "MCAL/STK/STK_Config.h"
/*======================================*/
/*===========  INCLUDE HAL   ===========*/


/*======================================*/

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/
static u32 STK_CLK_Ms_Ticks;
static u32 STK_RequiredOnTime;
static u32 STK_RequiredOffTime;
//static u32 L_RequiredIntervalTime;
static void(*STK_pAppFun)(void)=NULL;
//static void*STK_pAppFunParameter=NULL;
static volatile u8 STK_CallBackMode;
static volatile u8 L_u8ReadFlag;
static u32 counter;
/*====================================================   Start_FUNCTION   ====================================================*/
void STK_Init(STK_CLK_SRC_t STK_CLK_SRC)
{
	/*Clear Val & Count flag*/
	STK->VAL =0;
	/*Clk Source*/
	switch(STK_CLK_SRC)
	{
	case STK_CLK_SRC_HCLK:		STK->CTRL |=STK_CTRL_CLKSOURCE;STK_CLK_Ms_Ticks=16000U;break;
	case STK_CLK_SRC_HCLK_Div8:	STK->CTRL &=~STK_CTRL_CLKSOURCE;STK_CLK_Ms_Ticks=2000U;break;
	default ://error
		break;
	}
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
void STK_Stop(void)
{
	STK->CTRL &=~ STK_CTRL_ENABLE;
	STK->LOAD=0;
	STK->VAL=0;
	STK->CTRL &=~ STK_CTRL_TICKINT;
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
void STK_DelayMs(u32 Copy_u32RequiredMs)
{
	STK->LOAD = (STK_CLK_Ms_Ticks*Copy_u32RequiredMs)-1;
	STK->VAL=0;
	STK->CTRL |= STK_CTRL_ENABLE;
	while((STK->CTRL & STK_CTRL_COUNTFLAG) == 0);
	STK->CTRL &=~ STK_CTRL_ENABLE;

}
/*====================================================   END_ FUNCTION   ====================================================*/
void STK_DelayUs(u32 Copy_u32RequiredUs)
{
	STK->LOAD = ((STK_CLK_Ms_Ticks/1000U)*Copy_u32RequiredUs)-1;
	STK->VAL=0;
	STK->CTRL |= STK_CTRL_ENABLE;
	while((STK->CTRL & STK_CTRL_COUNTFLAG) == 0);
	STK->CTRL &=~ STK_CTRL_ENABLE;

}
/*====================================================   Start_FUNCTION   ====================================================*/
void STK_PeriodicCallBackMs(u32 Copy_u32RequiredDelay,void(*pAppFun)(void))
{
	if(pAppFun!=NULL)
	{
		STK_pAppFun =pAppFun;
		STK->LOAD = (STK_CLK_Ms_Ticks*Copy_u32RequiredDelay)-1;
		STK->VAL=0;
		STK->CTRL |= 3U;
		STK_CallBackMode = PERIODIC;
	}else
	{
		//error
	}
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void STK_SingleCallBackMs(u32 Copy_u32RequiredDelay,void(*pAppFun)(void))
{
	if(pAppFun!=NULL)
	{
		STK_pAppFun =pAppFun;
		STK->LOAD = (STK_CLK_Ms_Ticks*Copy_u32RequiredDelay)-1;
		STK->VAL=0;
		STK->CTRL |= 3U;
		STK_CallBackMode = ONE_TIME;
	}else
	{
		//error
	}
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
u32 STK_GetRemainingTime(void)
{
	u32 L_ReadValR;
	L_ReadValR= STK->VAL;
	return L_ReadValR;
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
u32 STK_GetElapsedTime(void)
{
	u32 L_ReadElapsedTime;
	L_ReadElapsedTime= (STK->LOAD)-	(STK->VAL);
	return L_ReadElapsedTime;
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*void STK_PWM(u8 Freq,u16 Duty,void(*pAppFun)(void))
{
	u32 L_RequiredTime = (1000U*1000U/Freq);//how us in this freq
	 L_RequiredOnTime = (Duty*(L_RequiredTime/1000));
	 L_RequiredOffTime = ((1000-Duty)*(L_RequiredTime/1000));
	STK_pAppFun = pAppFun;
	STK->LOAD = (16U-1);		//1us
	STK->VAL=0;
	STK->CTRL |= 3U;
	STK_CallBackMode = PERIODIC;



}*/
void STK_PWM(u8 Freq,u16 Duty,void(*pAppFun)(void))
{
	u32 L_RequiredTime = ((1000U/Freq)*2U);//how 0.5ms in this freq
	STK_RequiredOnTime = (Duty*L_RequiredTime/1000);
	STK_RequiredOffTime = ((1000-Duty)*L_RequiredTime/1000);
	STK_pAppFun = pAppFun;
	STK->LOAD = (8000U-1);		//.5ms
	STK->VAL=0;
	STK_CallBackMode = PWM;
	STK_pAppFun();
	STK->CTRL |= 3U;

}
/*====================================================   Start_FUNCTION   ====================================================*/

void SysTick_Handler(void)
{
	if(STK_CallBackMode != PWM)
	{
		if(STK_CallBackMode == ONE_TIME)
		{
			STK->CTRL &=~ STK_CTRL_ENABLE;
			STK->LOAD=0;
			STK->VAL=0;
			STK->CTRL &=~ STK_CTRL_TICKINT;
		}
		STK_pAppFun();
	}else
	{
		counter++;
		if(counter == (STK_RequiredOnTime))
		{
			STK_pAppFun();
		}else if(counter == (STK_RequiredOnTime+STK_RequiredOffTime))
		{
			STK_pAppFun();
			counter=0;
		}
	}

	L_u8ReadFlag = GET_BIT(STK->CTRL,16U);
}
/*For PWM*/
/*
void SysTick_Handler(void)
{
	u8 L_u8ReadFlag;
	static u8 flag;
	static u32 counter;
	counter++;

	if(flag == 0)
	{
		flag=1;
		STK_pAppFun();
	}else if(counter == L_RequiredOnTime)
	{
		STK_pAppFun();
		counter=0;
	}else if (counter == (L_RequiredOnTime+L_RequiredOffTime-1))
	{
		flag=0;
	}

	L_u8ReadFlag = GET_BIT(STK->CTRL,16U);
}*/

/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/

/*====================================================   END_ FUNCTION   ====================================================*/
