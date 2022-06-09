/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "LIB/Std_Types.h"
		 #include "LIB/Bit_Math.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "MCAL/UART/UART_Private.h"
		#include "MCAL/UART/UART.h"
		#include "MCAL/UART/UART_Config.h"
/*======================================*/
/*===========  INCLUDE HAL   ===========*/
		#include "MCAL/GPIO/GPIO.h"
		#include "HAL/LCD/LCD.h"


/*======================================*/

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/
static volatile u8 * UART6_pAppParamter=NULL;
void UART6_vInit(void)
{
	UART6->CR1=0;

	/*Enable UART*/
	UART6->CR1 |= USART_CR1_UE;
	/*Baud Rate*/
		/*baurdrate = 16MHz /(9600*16)
		 * mantissa =104
		 * fraction =16*.1666667= 2.66667=3*/
		UART6->BRR = 0;
		UART6->BRR = (3<<0)| (104<<4);
		/*Enable Tx*/
		UART6->CR1|=USART_CR1_TE;
					/*Enable Rx*/	/*Enable Interrupt*/
		UART6->CR1|=(USART_CR1_RE|USART_CR1_RXNEIE);

	/*Mode*/
	/*Check Mode and apply Configuration*/
}
void UART6_Callback(u8 * pAppParamter)
{
	UART6_pAppParamter = pAppParamter;
}
u8 UART6_vSendReceive(u8 Copy_u8Data)
{
	u8 L_u16ReceiveData;
	/*Wait till the transmisson complete*/
		while(!(UART6->SR & USART_SR_TXE));
		UART6->DR = Copy_u8Data;

		/*Wait till the transmisson complete*/
			while(!(UART6->SR & USART_SR_RXNE));
			L_u16ReceiveData = UART6->DR;
			/*return data*/
			return L_u16ReceiveData;
}
u8 UART6_vReceive(void)
{
	u8 L_u16ReceiveData;

	/*Wait till the transmisson complete*/
		while(!(UART6->SR & USART_SR_RXNE));
		L_u16ReceiveData = UART6->DR;
		/*return data*/
		return L_u16ReceiveData;
}
void USART6_IRQHandler(void)
{
	//u16 read5ra=UART6->DR;
	//LCD_enuWriteData(('a'));

	/*return data*/
	*UART6_pAppParamter = UART6->DR;
	//LCD_enuWriteData(('b'));
	UART6->DR=(*UART6_pAppParamter);
	/*CLEAR FLAGS*/
	//UART6->SR = 0;
}
