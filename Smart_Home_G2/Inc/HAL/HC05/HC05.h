/*
 * HC05.h
 *
 *  Created on: Apr 28, 2022
 *      Author: Ahmed
 */

#ifndef HAL_HC05_HC05_H_
#define HAL_HC05_HC05_H_

void HC05_Init(void);
void HC05_SetInputReading(u8 *pAppParameter);
u8 HC05_SendReceive(u8 Data);
u8 HC05_Receive(void);

#endif /* HAL_HC05_HC05_H_ */
