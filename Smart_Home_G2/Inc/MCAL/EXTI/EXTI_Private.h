/***************************************************************************************
 *************************** - EXTI_Private.h				 ***************************
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
#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

#define EXTI_BASE_ADDRESS						0x40013C00

typedef struct
{
	volatile u32 IMR   ;  /*!< EXTI Interrupt mask register,            Address offset: 0x00 */
	volatile u32 EMR   ;  /*!< EXTI Event mask register,                Address offset: 0x04 */
	volatile u32 RTSR  ;  /*!< EXTI Rising trigger selection register,  Address offset: 0x08 */
	volatile u32 FTSR  ;  /*!< EXTI Falling trigger selection register, Address offset: 0x0C */
	volatile u32 SWIER ;  /*!< EXTI Software interrupt event register,  Address offset: 0x10 */
	volatile u32 PR    ;  /*!< EXTI Pending register,                   Address offset: 0x14 */
}EXTI_TypeDef;

#define EXTI				((EXTI_TypeDef*)(EXTI_BASE_ADDRESS))

#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */






