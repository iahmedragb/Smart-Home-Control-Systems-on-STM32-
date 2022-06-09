/***************************************************************************************
 *************************** - SYSCFG_Private.h				 ***************************
***************************   -Created: 4/15/2022			 ***************************
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

#ifndef MCAL_SYSCFG_SYSCFG_PRIVATE_H_
#define MCAL_SYSCFG_SYSCFG_PRIVATE_H_

#define SYSCFG_BASE_ADDRESS						0x40013800
typedef struct
{
	volatile u32 MEMRMP     ;
	volatile u32 PMC        ;
	volatile u32 EXTICR[4]  ;
	volatile u32 CMPCR      ;

}SYSCFG_TypeDef;

#define SYSCFG							((SYSCFG_TypeDef*)(SYSCFG_BASE_ADDRESS))
#endif /* MCAL_SYSCFG_SYSCFG_PRIVATE_H_ */
