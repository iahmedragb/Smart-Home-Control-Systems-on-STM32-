/***************************************************************************************
 *************************** - NVIC_Private.h				 ***************************
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
#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_

#define NVIC_BASE_ADDRESS					0xE000E100

typedef struct
{
  volatile u32 ISER[8U];               /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
        u32 RESERVED0[24U];
   volatile u32 ICER[8U];               /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
        u32 RSERVED1[24U];
	volatile u32 ISPR[8U];               /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
        u32 RESERVED2[24U];
	volatile u32 ICPR[8U];               /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
		u32 RESERVED3[24U];
	volatile u32 IABR[8U];               /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
		u32 RESERVED4[56U];
	volatile u32 IP[240U];               /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
        u32 RESERVED5[644U];
	volatile  u32 STIR;                   /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
}  NVIC_TypeDef;

#define NVIC				((NVIC_TypeDef*)(NVIC_BASE_ADDRESS))
#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
