/*
 * Keypad_Config.h
 *
 *  Created on: Apr 22, 2022
 *      Author: Ahmed
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

#define Col					4
#define Row					4

#define KEYPAD_R1_GPIO_PORT					GPIO_D
#define KEYPAD_R2_GPIO_PORT					GPIO_D
#define KEYPAD_R3_GPIO_PORT					GPIO_D
#define KEYPAD_R4_GPIO_PORT					GPIO_D
#define KEYPAD_C1_GPIO_PORT					GPIO_D
#define KEYPAD_C2_GPIO_PORT					GPIO_D
#define KEYPAD_C3_GPIO_PORT					GPIO_D
#define KEYPAD_C4_GPIO_PORT					GPIO_D

#define KEYPAD_R1_GPIO_PIN					Pin0
#define KEYPAD_R2_GPIO_PIN					Pin1
#define KEYPAD_R3_GPIO_PIN					Pin2
#define KEYPAD_R4_GPIO_PIN					Pin3
#define KEYPAD_C1_GPIO_PIN					Pin4
#define KEYPAD_C2_GPIO_PIN					Pin5
#define KEYPAD_C3_GPIO_PIN					Pin6
#define KEYPAD_C4_GPIO_PIN					Pin7

#define KEYS_VALUES			{{'7','8','9','/'},\
							{'4','5','6','x'},\
							{'1','2','3','-'},\
							{'C','0','=','+'}}


#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
