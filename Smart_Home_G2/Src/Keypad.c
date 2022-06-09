
/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "LIB/Std_Types.h"
		 #include "LIB/Bit_Math.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "MCAL/GPIO/GPIO_Config.h"
		#include "MCAL/GPIO/GPIO.h"
		#include "MCAL/STK/STK_Config.h"
		#include "MCAL/STK/STK.h"
/*======================================*/
/*===========  INCLUDE HAL   ===========*/

#include "HAL/Keypad/Keypad_Config.h"
#include "HAL/Keypad/Keypad.h"

/*===========  INCLUDE HAL   ===========*/
void KEYPAD_enuInit(void)
{
	GPIO_vSetMode(KEYPAD_C1_GPIO_PORT, KEYPAD_C1_GPIO_PIN, GPIO_Output);
	GPIO_vSetMode(KEYPAD_C2_GPIO_PORT, KEYPAD_C2_GPIO_PIN, GPIO_Output);
	GPIO_vSetMode(KEYPAD_C3_GPIO_PORT, KEYPAD_C3_GPIO_PIN, GPIO_Output);
	GPIO_vSetMode(KEYPAD_C4_GPIO_PORT, KEYPAD_C4_GPIO_PIN, GPIO_Output);
	GPIO_vWritePinValue(KEYPAD_C1_GPIO_PORT, KEYPAD_C1_GPIO_PIN, HighState);
	GPIO_vWritePinValue(KEYPAD_C2_GPIO_PORT, KEYPAD_C2_GPIO_PIN, HighState);
	GPIO_vWritePinValue(KEYPAD_C3_GPIO_PORT, KEYPAD_C3_GPIO_PIN, HighState);
	GPIO_vWritePinValue(KEYPAD_C4_GPIO_PORT, KEYPAD_C4_GPIO_PIN, HighState);


	GPIO_vSetMode(KEYPAD_R1_GPIO_PORT, KEYPAD_R1_GPIO_PIN, GPIO_Input);
	GPIO_vSetMode(KEYPAD_R2_GPIO_PORT, KEYPAD_R2_GPIO_PIN, GPIO_Input);
	GPIO_vSetMode(KEYPAD_R3_GPIO_PORT, KEYPAD_R3_GPIO_PIN, GPIO_Input);
	GPIO_vSetMode(KEYPAD_R4_GPIO_PORT, KEYPAD_R4_GPIO_PIN, GPIO_Input);
	/*Pull Up*/
	GPIO_vSetPullUpPullDown(KEYPAD_R1_GPIO_PORT, KEYPAD_R1_GPIO_PIN, Pull_Up);
	GPIO_vSetPullUpPullDown(KEYPAD_R2_GPIO_PORT, KEYPAD_R2_GPIO_PIN, Pull_Up);
	GPIO_vSetPullUpPullDown(KEYPAD_R3_GPIO_PORT, KEYPAD_R3_GPIO_PIN, Pull_Up);
	GPIO_vSetPullUpPullDown(KEYPAD_R4_GPIO_PORT, KEYPAD_R4_GPIO_PIN, Pull_Up);

}

void Keypad_GetPressedKey(u8 * Copy_pu8KeyValue)
{
	u8 Local_u8RowIter = 0;
	u8 Local_u8ColIter = 0;

	u8 Local_Au8R_Port[]={KEYPAD_R1_GPIO_PORT,KEYPAD_R2_GPIO_PORT,KEYPAD_R3_GPIO_PORT,KEYPAD_R4_GPIO_PORT};
	u8 Local_Au8R_Pin[]={KEYPAD_R1_GPIO_PIN,KEYPAD_R2_GPIO_PIN,KEYPAD_R3_GPIO_PIN,KEYPAD_R4_GPIO_PIN};

	u8 Local_Au8C_Port[]={KEYPAD_C1_GPIO_PORT,KEYPAD_C2_GPIO_PORT,KEYPAD_C3_GPIO_PORT,KEYPAD_C4_GPIO_PORT};
	u8 Local_Au8C_Pin[]={KEYPAD_C1_GPIO_PIN,KEYPAD_C2_GPIO_PIN,KEYPAD_C3_GPIO_PIN,KEYPAD_C4_GPIO_PIN};


	u8 Local_u8RowValue=KEY_NOT_PRESSED , Local_u8Flag=0;

	for (;Local_u8ColIter < Col ; Local_u8ColIter++ )
	{
		GPIO_vWritePinValue(Local_Au8C_Port[Local_u8ColIter], Local_Au8C_Pin[Local_u8ColIter], LowState);

		for (Local_u8RowIter=0; Local_u8RowIter<Row; Local_u8RowIter++)
		{
			GPIO_vGetPinValue(Local_Au8R_Port[Local_u8RowIter], Local_Au8R_Pin[Local_u8RowIter], &Local_u8RowValue);
			if (! Local_u8RowValue)
			{
				STK_DelayMs(10);
				GPIO_vGetPinValue(Local_Au8R_Port[Local_u8RowIter], Local_Au8R_Pin[Local_u8RowIter], &Local_u8RowValue);

				if (! Local_u8RowValue)
				{
					while (! Local_u8RowValue)
						GPIO_vGetPinValue(Local_Au8R_Port[Local_u8RowIter], Local_Au8R_Pin[Local_u8RowIter], &Local_u8RowValue);

					u8 Local_Au8KeyValues[Row][Col] =KEYS_VALUES;
					*Copy_pu8KeyValue = Local_Au8KeyValues[Local_u8RowIter][Local_u8ColIter];
					Local_u8Flag =1;
				}
			}
		}
		GPIO_vWritePinValue(Local_Au8C_Port[Local_u8ColIter], Local_Au8C_Pin[Local_u8ColIter], HighState);
	}
	if (! Local_u8Flag)
	{
		//*Copy_pu8KeyValue = KEY_NOT_PRESSED;
	}
}
