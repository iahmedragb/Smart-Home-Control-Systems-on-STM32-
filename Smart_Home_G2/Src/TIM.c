
/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "LIB/Std_Types.h"
		 #include "LIB/Bit_Math.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "MCAL/TIM/TIM_Private.h"
		#include "MCAL/TIM/TIM.h"
		#include "MCAL/TIM/TIM_Config.h"
/*======================================*/
/*===========  INCLUDE HAL   ===========*/


/*======================================*/

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/


/*====================================================   Start_FUNCTION   ====================================================*/

void TIM1_Init(void)
{

	/*Internal Clk 16MHZ*/
	TIM1->PSC = 16-1;
	/*to make sure ccr1 represents the duty cycle*/
	TIM1->ARR = 100-1;
	/*duty*/
	TIM1->CCR1 = 50;
	/*APRE*/
	TIM1->CR1 |=(1U<<7);
	/*non inverted mode*/
	TIM1->CCMR1 |= (0b110<<4)|(1U<<3);
	/*Update Event Generation*/
	TIM1->EGR |= (1U<<0);

	TIM1->CCER = (1U<<0)|(1U<<2);

	/*Enable*/
	TIM1->BDTR = (1U<<15)|(1U<<14);//|(1U<<11);




}
void TIM2_Init(void)
{
	/*Internal Clk 16MHZ*/
	TIM2->PSC = 8-1;
	/*to make sure ccr1 represents the duty cycle*/
	TIM2->ARR = 100-1;
	/*duty*/
	TIM2->CCR1 = 50;
	/**/
	/*prelaod enable + PWM mode 1*/
		TIM2->CCMR1 = (1U<<3)|(6U<<4);
		//TIM2->RCR = 100;
	TIM2->CCER = (1U<<0);
	//TIM2->CR1 =(1U<<7);

	/*Update Generation UG*/
	//TIM2->EGR = (1U<<0);
	/*Counter enable CEN + auto reload enable ARPE*/
	TIM2->CR1 = (1U<<0)	;
}
void TIM3_Init(void)
{

}
