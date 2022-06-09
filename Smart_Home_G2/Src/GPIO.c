
/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "LIB/Std_Types.h"
		 #include "LIB/Bit_Math.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "MCAL/GPIO/GPIO_Private.h"
		#include "MCAL/GPIO/GPIO.h"
		#include "MCAL/GPIO/GPIO_Config.h"
/*======================================*/
/*===========  INCLUDE HAL   ===========*/


/*======================================*/

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/


/*====================================================   Start_FUNCTION   ====================================================*/

void GPIO_vSetMode(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin,GPIO_Mode	Copy_u8Mode)
{
	if((Copy_u8GPIOPortNum<=GPIO_H)&&(Copy_u8Pin<=Pin15)&&(Copy_u8Mode<=GPIO_Analog))
	{
		switch(Copy_u8GPIOPortNum)
		{
		case GPIO_A:
			GPIOA->MODER &=~(((u32)Copy_u8Mode)<<(2*Copy_u8Pin));
			GPIOA->MODER |=(((u32)Copy_u8Mode)<<(2*Copy_u8Pin));break;
		case GPIO_B:
			GPIOB->MODER &=~(((u32)Copy_u8Mode)<<(2*Copy_u8Pin));
			GPIOB->MODER |=(((u32)Copy_u8Mode)<<(2*Copy_u8Pin));break;
		case GPIO_C: GPIOC->MODER &=~(((u32)Copy_u8Mode)<<(2*Copy_u8Pin));
			GPIOC->MODER |=(((u32)Copy_u8Mode)<<(2*Copy_u8Pin));break;
		case GPIO_D: GPIOD->MODER &=~(((u32)Copy_u8Mode)<<(2*Copy_u8Pin));
		GPIOD->MODER |=(((u32)Copy_u8Mode)<<(2*Copy_u8Pin));break;
		case GPIO_E: GPIOE->MODER &=~(((u32)Copy_u8Mode)<<(2*Copy_u8Pin));
		GPIOE->MODER |=(((u32)Copy_u8Mode)<<(2*Copy_u8Pin));break;
		case GPIO_H: GPIOH->MODER &=~(((u32)Copy_u8Mode)<<(2*Copy_u8Pin));
		 GPIOH->MODER |=(((u32)Copy_u8Mode)<<(2*Copy_u8Pin));break;
		default: /*error*/;
		}
	}else
	{
		/*error*/
	}
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
void GPIO_vSetType(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin,GPIO_Output_Type	Copy_u8Type)
{
	if((Copy_u8GPIOPortNum<=GPIO_H)&&(Copy_u8Pin<=Pin15)&&(Copy_u8Type<=OpenDrain))
		{
			switch(Copy_u8GPIOPortNum)
			{
			case GPIO_A: GPIOA->OTYPER &=~(((u32)Copy_u8Type)<<(Copy_u8Pin));GPIOA->OTYPER |=(((u32)Copy_u8Type)<<(Copy_u8Pin));break;
			case GPIO_B: GPIOB->OTYPER &=~(((u32)Copy_u8Type)<<(Copy_u8Pin));GPIOB->OTYPER |=(((u32)Copy_u8Type)<<(Copy_u8Pin));break;
			case GPIO_C: GPIOC->OTYPER &=~(((u32)Copy_u8Type)<<(Copy_u8Pin));GPIOC->OTYPER |=(((u32)Copy_u8Type)<<(Copy_u8Pin));break;
			case GPIO_D: GPIOD->OTYPER &=~(((u32)Copy_u8Type)<<(Copy_u8Pin)); GPIOD->OTYPER |=(((u32)Copy_u8Type)<<(Copy_u8Pin));break;
			case GPIO_E: GPIOE->OTYPER &=~(((u32)Copy_u8Type)<<(Copy_u8Pin)); GPIOE->OTYPER |=(((u32)Copy_u8Type)<<(Copy_u8Pin));break;
			case GPIO_H: GPIOH->OTYPER &=~(((u32)Copy_u8Type)<<(Copy_u8Pin)); GPIOH->OTYPER |=(((u32)Copy_u8Type)<<(Copy_u8Pin));break;
			default: /*error*/;
			}
		}else
		{
			/*error*/
		}
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
void GPIO_vSetSpeed(GPIO_PortNum Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin,GPIO_Speed	Copy_u8Speed)
{
	if((Copy_u8GPIOPortNum<=GPIO_H)&&(Copy_u8Pin<=Pin15)&&(Copy_u8Speed<=VeryHighSpeed))
		{
			switch(Copy_u8GPIOPortNum)
			{
			case GPIO_A: GPIOA->OSPEEDR |=(((u32)Copy_u8Speed)<<(2*Copy_u8Pin));break;
			case GPIO_B: GPIOB->OSPEEDR |=(((u32)Copy_u8Speed)<<(2*Copy_u8Pin));break;
			case GPIO_C: GPIOC->OSPEEDR |=(((u32)Copy_u8Speed)<<(2*Copy_u8Pin));break;
			case GPIO_D: GPIOD->OSPEEDR |=(((u32)Copy_u8Speed)<<(2*Copy_u8Pin));break;
			case GPIO_E: GPIOE->OSPEEDR |=(((u32)Copy_u8Speed)<<(2*Copy_u8Pin));break;
			case GPIO_H: GPIOH->OSPEEDR |=(((u32)Copy_u8Speed)<<(2*Copy_u8Pin));break;
			default: /*error*/;
			}
		}else
		{
			/*error*/
		}
}

/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

void GPIO_vSetPullUpPullDown(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin,GPIO_PUPD	Copy_u8PullUpPullDown)
{
	if((Copy_u8GPIOPortNum<=GPIO_H)&&(Copy_u8Pin<=Pin15)&&(Copy_u8PullUpPullDown<=Pull_Down))
			{
				switch(Copy_u8GPIOPortNum)
				{
				case GPIO_A: GPIOA->PUPDR |=(((u32)Copy_u8PullUpPullDown)<<(2*Copy_u8Pin));break;
				case GPIO_B: GPIOB->PUPDR |=(((u32)Copy_u8PullUpPullDown)<<(2*Copy_u8Pin));break;
				case GPIO_C: GPIOC->PUPDR |=(((u32)Copy_u8PullUpPullDown)<<(2*Copy_u8Pin));break;
				case GPIO_D: GPIOD->PUPDR |=(((u32)Copy_u8PullUpPullDown)<<(2*Copy_u8Pin));break;
				case GPIO_E: GPIOE->PUPDR |=(((u32)Copy_u8PullUpPullDown)<<(2*Copy_u8Pin));break;
				case GPIO_H: GPIOH->PUPDR |=(((u32)Copy_u8PullUpPullDown)<<(2*Copy_u8Pin));break;
				default: /*error*/;
				}
			}else
			{
				/*error*/
			}
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
void GPIO_vSetAlternateFunction(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin,GPIO_AF	Copy_u8AF)
{
	if((Copy_u8GPIOPortNum<=GPIO_H)&&(Copy_u8Pin<=Pin15)&&(Copy_u8AF<=AF15))
	{
		switch(Copy_u8GPIOPortNum)
		{
		case GPIO_A: GPIOA->AFR[(Copy_u8Pin/8U)] &=~(((u32)Copy_u8AF)<<(4*(Copy_u8Pin%8U))); GPIOA->AFR[(Copy_u8Pin/8U)] |=(((u32)Copy_u8AF)<<(4*(Copy_u8Pin%8U)));break;
		case GPIO_B: GPIOB->AFR[(Copy_u8Pin/8U)] &=~(((u32)Copy_u8AF)<<(4*(Copy_u8Pin%8U))); GPIOB->AFR[(Copy_u8Pin/8U)] |=(((u32)Copy_u8AF)<<(4*(Copy_u8Pin%8U)));break;
		case GPIO_C: GPIOC->AFR[(Copy_u8Pin/8U)] &=~(((u32)Copy_u8AF)<<(4*(Copy_u8Pin%8U))); GPIOC->AFR[(Copy_u8Pin/8U)] |=(((u32)Copy_u8AF)<<(4*(Copy_u8Pin%8U)));break;
		case GPIO_D: GPIOD->AFR[(Copy_u8Pin/8U)] &=~(((u32)Copy_u8AF)<<(4*(Copy_u8Pin%8U))); GPIOD->AFR[(Copy_u8Pin/8U)] |=(((u32)Copy_u8AF)<<(4*(Copy_u8Pin%8U)));break;
		case GPIO_E: GPIOE->AFR[(Copy_u8Pin/8U)] &=~(((u32)Copy_u8AF)<<(4*(Copy_u8Pin%8U))); GPIOE->AFR[(Copy_u8Pin/8U)] |=(((u32)Copy_u8AF)<<(4*(Copy_u8Pin%8U)));break;
		case GPIO_H: GPIOH->AFR[(Copy_u8Pin/8U)] &=~(((u32)Copy_u8AF)<<(4*(Copy_u8Pin%8U))); GPIOH->AFR[(Copy_u8Pin/8U)] |=(((u32)Copy_u8AF)<<(4*(Copy_u8Pin%8U)));break;
		default: /*error*/;
		}
	}else
	{
		//error
	}
}
/*void GPIO_vSetAlternateFunction(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin,GPIO_AF	Copy_u8AF)
{
	if((Copy_u8GPIOPortNum<=GPIO_H)&&(Copy_u8Pin<=Pin15)&&(Copy_u8AF<=AF15))
	{
		if(Copy_u8Pin<=7)
		{
			switch(Copy_u8GPIOPortNum)
								{
								case GPIO_A: GPIOA->AFR[0] |=(((u32)Copy_u8AF)<<(4*Copy_u8Pin));break;
								case GPIO_B: GPIOB->AFR[0] |=(((u32)Copy_u8AF)<<(4*Copy_u8Pin));break;
								case GPIO_C: GPIOC->AFR[0] |=(((u32)Copy_u8AF)<<(4*Copy_u8Pin));break;
								case GPIO_D: GPIOD->AFR[0] |=(((u32)Copy_u8AF)<<(4*Copy_u8Pin));break;
								case GPIO_E: GPIOE->AFR[0] |=(((u32)Copy_u8AF)<<(4*Copy_u8Pin));break;
								case GPIO_H: GPIOH->AFR[0] |=(((u32)Copy_u8AF)<<(4*Copy_u8Pin));break;
								default: //error;
								}
		}else if(Copy_u8Pin<=15)
		{
			Copy_u8Pin %=8;
			switch(Copy_u8GPIOPortNum)
											{
											case GPIO_A: GPIOA->AFR[1] |=(((u32)Copy_u8AF)<<(4*Copy_u8Pin));break;
											case GPIO_B: GPIOB->AFR[1] |=(((u32)Copy_u8AF)<<(4*Copy_u8Pin));break;
											case GPIO_C: GPIOC->AFR[1] |=(((u32)Copy_u8AF)<<(4*Copy_u8Pin));break;
											case GPIO_D: GPIOD->AFR[1] |=(((u32)Copy_u8AF)<<(4*Copy_u8Pin));break;
											case GPIO_E: GPIOE->AFR[1] |=(((u32)Copy_u8AF)<<(4*Copy_u8Pin));break;
											case GPIO_H: GPIOH->AFR[1] |=(((u32)Copy_u8AF)<<(4*Copy_u8Pin));break;
											default: //error;
											}
		}
	}else
	{
		//error
	}
}
*/

/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void GPIO_vWritePinValue(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin,GPIO_State Copy_u8State)
{
	if((Copy_u8GPIOPortNum<=GPIO_H)&&(Copy_u8Pin<=Pin15)&&(Copy_u8State<=HighState))
	{
		switch(Copy_u8State)
		{
		case LowState:
			Copy_u8Pin +=16;
			switch(Copy_u8GPIOPortNum)
								{
								case GPIO_A: SET_BIT(GPIOA->BSRR,Copy_u8Pin);break;
								case GPIO_B: SET_BIT(GPIOB->BSRR,Copy_u8Pin);break;
								case GPIO_C: SET_BIT(GPIOC->BSRR,Copy_u8Pin);break;
								case GPIO_D: SET_BIT(GPIOD->BSRR,Copy_u8Pin);break;
								case GPIO_E: SET_BIT(GPIOE->BSRR,Copy_u8Pin);break;
								case GPIO_H: SET_BIT(GPIOH->BSRR,Copy_u8Pin);break;
								default: /*error*/;
								}
			break;
			case HighState:
				switch(Copy_u8GPIOPortNum)
									{
									case GPIO_A: SET_BIT(GPIOA->BSRR,Copy_u8Pin);break;
									case GPIO_B: SET_BIT(GPIOB->BSRR,Copy_u8Pin);break;
									case GPIO_C: SET_BIT(GPIOC->BSRR,Copy_u8Pin);break;
									case GPIO_D: SET_BIT(GPIOD->BSRR,Copy_u8Pin);break;
									case GPIO_E: SET_BIT(GPIOE->BSRR,Copy_u8Pin);break;
									case GPIO_H: SET_BIT(GPIOH->BSRR,Copy_u8Pin);break;
									default: /*error*/;
									}
				break;
				default: /*error*/;
		}
	}else
	{
		/*error*/
	}
}


/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/

void GPIO_vGetPinValue(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin,u8 *Copy_pu8ReadValue)
{
	if((Copy_u8GPIOPortNum<=GPIO_H)&&(Copy_u8Pin<=Pin15)&&(Copy_pu8ReadValue!=NULL))
			{
				switch(Copy_u8GPIOPortNum)
				{
				case GPIO_A: *Copy_pu8ReadValue=GET_BIT(GPIOA->IDR,Copy_u8Pin);break;
				case GPIO_B: *Copy_pu8ReadValue=GET_BIT(GPIOB->IDR,Copy_u8Pin);break;
				case GPIO_C: *Copy_pu8ReadValue=GET_BIT(GPIOC->IDR,Copy_u8Pin);break;
				case GPIO_D: *Copy_pu8ReadValue=GET_BIT(GPIOD->IDR,Copy_u8Pin);break;
				case GPIO_E: *Copy_pu8ReadValue=GET_BIT(GPIOE->IDR,Copy_u8Pin);break;
				case GPIO_H: *Copy_pu8ReadValue=GET_BIT(GPIOH->IDR,Copy_u8Pin);break;
				default: /*error*/;
				}
			}else
			{
				/*error*/
			}
}
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
void GPIO_vLockPin(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin)
{

}
void GPIO_vTogglePinValue(GPIO_PortNum	Copy_u8GPIOPortNum,GPIO_PinNum Copy_u8Pin)
{
	if((Copy_u8GPIOPortNum<=GPIO_H)&&(Copy_u8Pin<=Pin15))
		{
			switch(Copy_u8GPIOPortNum)
			{

							{
							case GPIO_A: TGL_BIT(GPIOA->ODR,Copy_u8Pin);break;
							case GPIO_B: TGL_BIT(GPIOB->ODR,Copy_u8Pin);break;
							case GPIO_C: TGL_BIT(GPIOC->ODR,Copy_u8Pin);break;
							case GPIO_D: TGL_BIT(GPIOD->ODR,Copy_u8Pin);break;
							case GPIO_E: TGL_BIT(GPIOE->ODR,Copy_u8Pin);break;
							case GPIO_H: TGL_BIT(GPIOH->ODR,Copy_u8Pin);break;
							default: /*error*/;
							}
			}
		}else
		{
			/*error*/
		}
}
/*====================================================   END_ FUNCTION   ====================================================*/
