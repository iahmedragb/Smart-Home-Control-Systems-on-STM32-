/***************************************************************************************
 *************************** - STK_Private.h				 ***************************
***************************   -Created: 4/8/2022			 ***************************
***************************   -Author: Ragab			     ***************************
***************************   -Version : _1_				 ***************************
***************************   -Note :
									*-
									*-
 **************************************************************************************/

/**************************************************************************************

*	 - Developer can't Edit in it
*	  - Register _ Defination
*	  - Design :
					- #define	:	NO
					- Union		:	NO
					- Struct	:	YES

**************************************************************************************/
#ifndef MCAL_STK_STK_PRIVATE_H_
#define MCAL_STK_STK_PRIVATE_H_

#define STK_BASE_ADDRES				0xE000E010

typedef struct
{
	volatile u32 CTRL  ;
	volatile u32 LOAD  ;
	volatile u32 VAL   ;
	volatile u32 CALIB ;
}STK_TypeDef;

#define STK				((STK_TypeDef*)(STK_BASE_ADDRES))

#define STK_CTRL_ENABLE		(1U<<0)
#define STK_CTRL_TICKINT	(1U<<1)
#define STK_CTRL_CLKSOURCE	(1U<<2)
#define STK_CTRL_COUNTFLAG	(1U<<16)

#define PERIODIC	1
#define ONE_TIME	0
#define PWM			2
#endif /* MCAL_STK_STK_PRIVATE_H_ */
