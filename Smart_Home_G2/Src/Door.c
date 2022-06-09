/*
 * Door.c
 *
 *  Created on: Apr 27, 2022
 *      Author: Ahmed
 */

/*===========   INCLUDE LIB   ===========*/
		 #include "LIB/Std_Types.h"
		 #include "LIB/Bit_Math.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "MCAL/GPIO/GPIO.h"
		#include "MCAL/STK/STK.h"
/*======================================*/
/*===========  INCLUDE HAL   ===========*/
		#include "HAL/Door/Door_Config.h"
		#include "HAL/Door/Door.h"


/*======================================*/

/*===========  INCLUDE HAL   ===========*/

void Door_Init(void)
{
	GPIO_vSetMode(DOOR_PORT,DOOR_PIN, GPIO_Output);
}

void Door_Control(u8 Door_State)
{
	STK_PWM(50, Door_State, pwm);

}
void pwm(void)
{
	static u32 counter;
	counter++;
	GPIO_vTogglePinValue(DOOR_PORT, DOOR_PIN);
	if(counter==2)
	{
		STK_Stop();
		//GPIO_vTogglePinValue(DOOR_PORT, DOOR_PIN);
	}
}
