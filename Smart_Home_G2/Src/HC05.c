
/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "LIB/Std_Types.h"
		 #include "LIB/Bit_Math.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "MCAL/UART/UART.h"
		#include "MCAL/GPIO/GPIO.h"
		#include "MCAL/RCC/RCC.h"
		#include "MCAL/NVIC/NVIC.h"
/*======================================*/
/*===========  INCLUDE HAL   ===========*/
		#include "HAL/HC05/HC05_Config.h"
		#include "HAL/HC05/HC05.h"


/*======================================*/

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/


/*====================================================   Start_FUNCTION   ====================================================*/
volatile u8 * HC05_read=NULL;
void HC05_Init(void)
{
	RCC_vEnableClock(APB2_BUS, HC05_CONNCETED_USART_PERIPHERAL);

	GPIO_vSetMode(HC05_TX_PORT, HC05_TX_PIN, GPIO_ALF);
	GPIO_vSetMode(HC05_RX_PORT, HC05_RX_PIN, GPIO_ALF);
	GPIO_vSetAlternateFunction(HC05_TX_PORT, HC05_TX_PIN, HC05_CONNCETED_USART_TX);
	GPIO_vSetAlternateFunction(HC05_RX_PORT, HC05_RX_PIN, HC05_CONNCETED_USART_RX);
	UART6_vInit();
	UART6_Callback(HC05_read);
	NVIC_EnableIRQ(HC05_CONNCETED_IRQn);
}

void HC05_SetInputReading(u8 *pAppParameter)
{
	HC05_read = pAppParameter;
}
u8 HC05_SendReceive(u8 Data)
{
	u8 receiveData=0;
		receiveData = UART6_vSendReceive(Data);
		return receiveData;
}
u8 HC05_Receive(void)
{
	u8 receiveData=0;
	receiveData = UART6_vReceive();
	return receiveData;
}

