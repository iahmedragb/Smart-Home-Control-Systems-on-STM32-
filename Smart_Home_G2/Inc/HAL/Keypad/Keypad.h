/*
 * Keypad.h
 *
 *  Created on: Apr 22, 2022
 *      Author: Ahmed
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

#define KEY_NOT_PRESSED			199

void KEYPAD_enuInit(void);
void Keypad_GetPressedKey(u8 * Copy_pu8KeyValue);



#endif /* HAL_KEYPAD_KEYPAD_H_ */
