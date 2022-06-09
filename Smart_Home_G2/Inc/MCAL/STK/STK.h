/***************************************************************************************
 *************************** - STK.h						 ***************************
***************************   -Created: 4/15/2022			 ***************************
***************************   -Author: Ragab			     ***************************
***************************   -Version : _1_				 ***************************
***************************   -Note :
									*-
									*-
 **************************************************************************************/

/*=====================================================================================
		* What i sell To Customer
		*  The Archictect Give The API
						- The Name Of Function
						- What is The Input
						- What Is The Output
						- Macro

======================================================================================*/

#ifndef MCAL_STK_STK_H_
#define MCAL_STK_STK_H_

typedef enum
{
	STK_CLK_SRC_HCLK=0,
	STK_CLK_SRC_HCLK_Div8=1
}STK_CLK_SRC_t;

void STK_Init(STK_CLK_SRC_t STK_CLK_SRC);
void STK_Stop(void);

void STK_DelayMs(u32 Copy_u32RequiredMs);
void STK_DelayUs(u32 Copy_u32RequiredUs);

void STK_PeriodicCallBackMs(u32 Copy_u32RequiredDelay,void(*pAppFun)(void));
void STK_SingleCallBackMs(u32 Copy_u32RequiredDelay,void(*pAppFun)(void));

u32 STK_GetRemainingTime(void);
u32 STK_GetElapsedTime(void);
void STK_PWM(u8 Freq,u16 Duty,void(*pAppFun)(void));

#endif /* MCAL_STK_STK_H_ */
