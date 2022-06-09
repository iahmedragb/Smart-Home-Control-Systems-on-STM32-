
/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "LIB/Std_Types.h"
		 #include "LIB/Bit_Math.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "MCAL/ADC/ADC_Private.h"
		#include "MCAL/ADC/ADC.h"
		#include "MCAL/ADC/ADC_Config.h"
/*======================================*/
/*===========  INCLUDE HAL   ===========*/

		#include "HAL/LCD/LCD.h"

/*======================================*/

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/

static u8 *ADC_RequiredValue=NULL;
static u8 ADC_CurrentAppState;
static void (*ADC_pAppFunStart)(void)=NULL;
static void (*ADC_pAppFunStop)(void)=NULL;
u8 read;
u8 RequiredRegisterValue;
/*====================================================   Start_FUNCTION   ====================================================*/
void ADC_Init(void)
{
	ADC1->CR1 |= ADC_CR1_EOCIE;		//interrupt enable on end of conv.
	//ADC1->CR1 |= ADC_CR1_RES_12;	//Resolution
	//ADC1->CR2 |= (1U<<1); //Cont. Conv.
	ADC1->SQR1 = 0; //Sequence Length
	ADC1->SQR3 |=(1U<<0);	//channel 1 is first in sequence
	ADC1_COMMON->CCR |= (3U<<0);


}
void ADC_AdjustValue(u8 *RequiredValue,void(*pAppFunStart)(void),void(*pAppFunStop)(void))
{
	if((pAppFunStart!=NULL)&&(pAppFunStop!=NULL))
		{
			ADC_pAppFunStart=pAppFunStart;
			ADC_pAppFunStop=pAppFunStop;
			ADC_CurrentAppState=OFF_STATE;
			ADC_RequiredValue=RequiredValue;
		}else
		{
			//error
		}

}
void ADC_Start(void)
{
	ADC1->CR2 |= 1U ;	//adc ON
	ADC1->CR2 |= (1U<<30);//start
}
void ADC_Stop(void)
{
	ADC1->CR2 &=~ 1U ;	//adc off
}
u16 ADC_Read(void)
{
	ADC1->CR2 |= 1U ;	//adc ON
	ADC1->CR2 |= (1U<<30);//start
	while(!((ADC1->SR) & (1U<<1)));


	return (ADC1->DR);
}

void ADC_IRQHandler(void)
{
	read=(ADC1->DR)/8;

	RequiredRegisterValue = (*ADC_RequiredValue);
	if((read >RequiredRegisterValue) &&(ADC_CurrentAppState == OFF_STATE))
	{
		ADC_pAppFunStart();
		ADC_CurrentAppState = ON_STATE;
	}else if((read <= RequiredRegisterValue)&&(ADC_CurrentAppState == ON_STATE))
	{
		ADC_pAppFunStop();
		ADC_CurrentAppState = OFF_STATE;
	}
	ADC1->CR2 |= (1U<<30);//start

}
