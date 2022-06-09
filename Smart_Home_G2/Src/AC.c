
/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "LIB/Std_Types.h"
		 #include "LIB/Bit_Math.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "MCAL/ADC/ADC.h"
		#include "MCAL/GPIO/GPIO.h"
		#include "MCAL/RCC/RCC.h"
		#include "MCAL/NVIC/NVIC.h"
/*======================================*/
/*===========  INCLUDE HAL   ===========*/
		#include "HAL/AC/AC_Config.h"
		#include "HAL/AC/AC.h"


/*======================================*/

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/


/*====================================================   Start_FUNCTION   ====================================================*/
u8 AC_RequiredTemp;
void AC_Init(void)
{
	/*Enable Interrupt*/
	/*Enable Peripheral*/
	RCC_vEnableClock(APB2_BUS,PERIPHERAL_EN_ADC1 );
	/*ADC Channel*/
	GPIO_vSetMode(TEMPERATURE_SENSOR_PORT, TEMPERATURE_SENSOR_PIN, GPIO_Analog);
	/*Motor */
	GPIO_vSetMode(AIR_COND_MOTOR_PORT, AIR_COND_MOTOR_PIN, GPIO_Output);
	/*Initialize ADC*/
	ADC_Init();
	ADC_AdjustValue(&AC_RequiredTemp,AC_On, AC_Off);
	/*Systick Interval*/
	/*In this case stop continous conversion in ADC*/
	//STK_PeriodicCallBackMs(1000, AC_TempRead);
	NVIC_EnableIRQ(ADC_IRQn);
	ADC_Start();
}

void AC_On(void)
{
	/*Motor ON*/
	GPIO_vWritePinValue(AIR_COND_MOTOR_PORT, AIR_COND_MOTOR_PIN, HighState);
}
void AC_Off(void)
{
	/*Motor OFF*/
	GPIO_vWritePinValue(AIR_COND_MOTOR_PORT, AIR_COND_MOTOR_PIN, LowState);

}
void AC_AdjustTemperature(u8 RequiredTemp)
{
	/*Change Reference Temperature*/
	AC_RequiredTemp=RequiredTemp;
}
u16 AC_TempRead(void)
{
	u16 read = ADC_Read();
	read /=8;
	return read;
}
