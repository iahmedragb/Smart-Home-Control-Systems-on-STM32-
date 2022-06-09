/***************************************************************************************
 *************************** - EXTI.h				 ***************************
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
#ifndef MCAL_EXTI_EXTI_H_
#define MCAL_EXTI_EXTI_H_
typedef enum
{
	EXTI_0=0,
	EXTI_1=1,
	EXTI_2=2,
	EXTI_3=3,
	EXTI_4=4,
	EXTI_5=5,
	EXTI_6=6,
	EXTI_7=7,
	EXTI_8=8,
	EXTI_9=9,
	EXTI_10=10,
	EXTI_11=11,
	EXTI_12=12,
	EXTI_13=13,
	EXTI_14=14,
	EXTI_15=15
}EXTI_Line;
typedef enum
{
	RISING=0,
	FALLING=1,
	ANY_CHANGE=2
}EXTI_Trigger;
void EXTI_vEnableLine(EXTI_Line Copy_u8EXTILine,EXTI_Trigger Copy_u8EXTITrigger);
void EXTI_vDisableLine(EXTI_Line Copy_u8EXTILine);
void EXTI_vSoftwareInterruptEvent(EXTI_Line Copy_u8EXTILine);
void EXTI_vCallBack(EXTI_Line Copy_u8EXTILine, void(*pAppFun)(void*),void* Copy_pvAppFunParameter);

#endif /* MCAL_EXTI_EXTI_H_ */
