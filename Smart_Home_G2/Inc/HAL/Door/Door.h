/*
 * Door.h
 *
 *  Created on: Apr 27, 2022
 *      Author: Ahmed
 */

#ifndef HAL_DOOR_DOOR_H_
#define HAL_DOOR_DOOR_H_
#define ENTER	25
#define LOCK	75
#define EXIT	125
void Door_Init(void);
void Door_Control(u8 Door_State);/*Use CLOSE ENTER EXIT*/
void pwm(void);

#endif /* HAL_DOOR_DOOR_H_ */
