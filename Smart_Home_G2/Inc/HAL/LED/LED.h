/*
 * LED.h
 *
 *  Created on: Apr 21, 2022
 *      Author: Ahmed
 */

#ifndef HAL_LED_H_
#define HAL_LED_H_
#include "HAL/LED/LED_Config.h"

typedef struct
{
	GPIO_PortNum LED_Port;
	GPIO_PinNum LED_Pin;
}LED_t;

extern u8 LED_u8LEDNum;
extern LED_t LED[LED_NUM];

void LED_Init(void);
void LED_On(LED_t *pstrLED_Info);
void LED_Off(LED_t *pstrLED_Info);


#endif /* HAL_LED_H_ */
