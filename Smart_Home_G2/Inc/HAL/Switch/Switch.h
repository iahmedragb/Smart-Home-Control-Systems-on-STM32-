/*
 * Switch.h
 *
 *  Created on: Apr 21, 2022
 *      Author: Ahmed
 */

#ifndef HAL_SWITCH_SWITCH_H_
#define HAL_SWITCH_SWITCH_H_

#include "HAL/Switch/Switch_Config.h"

typedef struct
{
	GPIO_PortNum Switch_Port;
	GPIO_PinNum Switch_Pin;
	GPIO_PUPD Switch_Input_type;

}Switch_t;

extern u8 Switch_u8SwitchNum;
extern Switch_t Switch[SWITCH_NUM];
#define NOT_PRESSED			'!'
void Switch_Init(void);
u8 Switch_Read(Switch_t *pstrSwitch_Info);


#endif /* HAL_SWITCH_SWITCH_H_ */
