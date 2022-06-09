/*
 * AC.h
 *
 *  Created on: Apr 24, 2022
 *      Author: Ahmed
 */

#ifndef HAL_AC_AC_H_
#define HAL_AC_AC_H_

void AC_Init(void);
void AC_AdjustTemperature(u8 RequiredTemp);
void AC_On(void);
void AC_Off(void);
u16 AC_TempRead(void);

#endif /* HAL_AC_AC_H_ */
