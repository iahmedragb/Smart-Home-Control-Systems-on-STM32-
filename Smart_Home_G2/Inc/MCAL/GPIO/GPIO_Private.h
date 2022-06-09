/***************************************************************************************
 *************************** - GPIO_Private.h				 ***************************
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
#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_

#define GPIOA_BASE_ADDRESS					0x40020000
#define GPIOB_BASE_ADDRESS					0x40020400
#define GPIOC_BASE_ADDRESS					0x40020800
#define GPIOD_BASE_ADDRESS					0x40020C00
#define GPIOE_BASE_ADDRESS					0x40021000
#define GPIOH_BASE_ADDRESS					0x40021C00

typedef struct
{
	volatile u32 MODER   ;         /*!< GPIO port mode register,               Address offset: 0x00      */
	volatile u32 OTYPER  ;         /*!< GPIO port output type register,        Address offset: 0x04      */
	volatile u32 OSPEEDR ;         /*!< GPIO port output speed register,       Address offset: 0x08      */
	volatile u32 PUPDR   ;         /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
	volatile u32 IDR     ;         /*!< GPIO port input data register,         Address offset: 0x10      */
	volatile u32 ODR     ;         /*!< GPIO port output data register,        Address offset: 0x14      */
	volatile u32 BSRR    ;         /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
	volatile u32 LCKR    ;         /*!< GPIO port configuration lock register, Address offset: 0x1C      */
	volatile u32 AFR[2]  ;         /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
}GPIO_TypeDef;

#define GPIOA								((GPIO_TypeDef*)(GPIOA_BASE_ADDRESS))
#define GPIOB								((GPIO_TypeDef*)(GPIOB_BASE_ADDRESS))
#define GPIOC								((GPIO_TypeDef*)(GPIOC_BASE_ADDRESS))
#define GPIOD								((GPIO_TypeDef*)(GPIOD_BASE_ADDRESS))
#define GPIOE								((GPIO_TypeDef*)(GPIOE_BASE_ADDRESS))
#define GPIOH								((GPIO_TypeDef*)(GPIOH_BASE_ADDRESS))
#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
