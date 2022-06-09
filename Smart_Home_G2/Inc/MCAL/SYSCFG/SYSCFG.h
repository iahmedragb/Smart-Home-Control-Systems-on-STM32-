/***************************************************************************************
 *************************** - SYSCFG.h				 ***************************
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
#ifndef MCAL_SYSCFG_SYSCFG_H_
#define MCAL_SYSCFG_SYSCFG_H_

typedef enum
{
	Line_0=0,
	Line_1=1,
	Line_2=2,
	Line_3=3,
	Line_4=4,
	Line_5=5,
	Line_6=6,
	Line_7=7,
	Line_8=8,
	Line_9=9,
	Line_10=10,
	Line_11=11,
	Line_12=12,
	Line_13=13,
	Line_14=14,
	Line_15=15
}EXTI_LineNum;

typedef enum
{
	EXTI_PA=0,
	EXTI_PB=1,
	EXTI_PC=2,
	EXTI_PD=3,
	EXTI_PE=4,
	EXTI_PH=7
}EXTI_Port;

void SYSCFG_vEXTILineInputSource(EXTI_LineNum Copy_u8EXTILine,EXTI_Port Copy_u8EXTIPort);
#endif /* MCAL_SYSCFG_SYSCFG_H_ */
