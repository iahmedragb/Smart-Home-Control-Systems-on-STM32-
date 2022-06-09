/*
 * HC05_Config.h
 *
 *  Created on: Apr 28, 2022
 *      Author: Ahmed
 */

#ifndef HAL_HC05_HC05_CONFIG_H_
#define HAL_HC05_HC05_CONFIG_H_

#define HC05_CONNCETED_USART_PERIPHERAL		PERIPHERAL_EN_USART6
#define HC05_CONNCETED_USART_TX				AF8
#define HC05_CONNCETED_USART_RX				AF8
#define HC05_CONNCETED_IRQn					USART6_IRQn
#define HC05_TX_PORT						GPIO_A
#define HC05_RX_PORT						GPIO_A
#define HC05_TX_PIN							Pin11
#define HC05_RX_PIN							Pin12

#endif /* HAL_HC05_HC05_CONFIG_H_ */
