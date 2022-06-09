/**
 ******************************************************************************
 * @file           : main.c
 * @author         : NTI_GROUP_2
 * @brief          : Main program of "Smart home project"
 *
 ******************************************************************************
 */

#include "APP/main.h"

/***************** Global Variables initialization *****************/
u8 wanted_Temp = START_TEMP;
u8 key = NOT_PRESSED;


/**************************** Main Function ************************/
int main(void)
{
/******************* MCAL Initialization ********************/
	/* RCC initialization */
	RCC_vInitSystemCLK();
	RCC_vEnableClock(AHB1_BUS,PERIPHERAL_EN_GPIOA );
	RCC_vEnableClock(AHB1_BUS,PERIPHERAL_EN_GPIOD );
	RCC_vEnableClock(AHB1_BUS,PERIPHERAL_EN_GPIOB );					//enable GPIOB and SPI (tft)
	RCC_vEnableClock(APB1_BUS, PERIPHERAL_EN_SPI2);						//Enable SPI peripheral
	/* Systic initialization */
	STK_Init(STK_CLK_SRC_HCLK);

	/* SPi initialization */
	MSPI_VidInit();						//SPI INIT

/******************* HAL Initialization ********************/
	/* LCD display initialization */
	LCD_enuInit();
	LCD_enuWriteCommand(0x0C); //Disable cursor

	/*TFT display init*/
	TFT_voidInit();

	/* Keypad initialization */
	KEYPAD_enuInit();

	/* Door initialization */
	Door_Init();

	/* Air conditioner initialization */
	AC_AdjustTemperature(wanted_Temp);
	AC_Init();
	GPIO_vSetMode(GPIO_A, Pin9, GPIO_Output);
	GPIO_vWritePinValue(GPIO_A, Pin9, LowState);  //initial state

	/* Bluetooth initialization */
	HC05_SetInputReading(&key);
	HC05_Init();						//HC05

	/* Leds initialization */
	//LED1
	GPIO_vSetMode(GPIO_A, Pin5, GPIO_Output);
	GPIO_vWritePinValue(GPIO_A, Pin5, LowState);  //initial state
	//LED2
	GPIO_vSetMode(GPIO_A, Pin6, GPIO_Output);
	GPIO_vWritePinValue(GPIO_A, Pin6, LowState);  //initial state
	//LED3
	GPIO_vSetMode(GPIO_A, Pin7, GPIO_Output);
	GPIO_vWritePinValue(GPIO_A, Pin7, LowState);  //initial state
	//LED4
	GPIO_vSetMode(GPIO_A, Pin8, GPIO_Output);
	GPIO_vWritePinValue(GPIO_A, Pin8, LowState);  //initial state

	/* Alert initialization */
	//Buzzer
	GPIO_vSetMode(GPIO_A, Pin4, GPIO_Output);
	GPIO_vWritePinValue(GPIO_A, Pin4, LowState);  //initial state

/******************************************************************************/
/***************** main Variables ***********************/
	//password saving
	s8 RightPassword[MAX_PASS_NUM]= "010";
	s8 MasterPassword[MAX_PASS_NUM]="010" ;

/* initial display */
	LCD_enuWriteCommand(1);
	LCD_enuWriteString((u8*)"Enter Password:");
	LCD_enuGoToPosition(2,1);
	TFT_vPasswordPanel();

	while(1)
	{
		PasswordTap(RightPassword, MasterPassword );
	}
	return 0;

}
/***************************End of main function *******************************/


/**************************** PasswordTap Function ************************/
void PasswordTap(s8* RightPassword,s8* MasterPassword )
{

	s8 static Loc_s8StrItrr=0 ; 								/*String Iterator for Each Password index */
	s8 static EnteredPassword[MAX_PASS_NUM]={0} ;				/*User Entered Password */
	u8 static wrongInputRemain = WRONG_INPUTS_ALLOWED;  		//number of wrong inputs //save it in EEPROM
	key = NOT_PRESSED;											/*Storing Input value*/

	STK_DelayMs(1);												/*for protues Simulation */
	Keypad_GetPressedKey(&key);									/*store keypad input*/

	if (key != NOT_PRESSED)
	{
		if(key >= '0' && key <='9')
		{
			BeebSound();
			LCD_enuWriteData('*');
			TFT_vDrawPassword(Loc_s8StrItrr +1);
			EnteredPassword[Loc_s8StrItrr] = key;
			Loc_s8StrItrr++;
		}
		else if('=' == key)
		{
			BeebSound();

			if((strEqual(EnteredPassword , RightPassword ) == STR_EQL) ||
					(strEqual(EnteredPassword , MasterPassword )== STR_EQL))
			{
				WelcomeTap(RightPassword);
				wrongInputRemain = WRONG_INPUTS_ALLOWED;
			}
			else
			{
				WrongTap(&wrongInputRemain);
			}

			/*reset Enter Password array for Next Iteration*/
			for(Loc_s8StrItrr = 0 ; Loc_s8StrItrr<MAX_PASS_NUM ; Loc_s8StrItrr++)
			{
				EnteredPassword[Loc_s8StrItrr] = 0;
			}
			Loc_s8StrItrr =0; /*reset String Iterator to zero for next iteration */

			/*Display Password Tap for User*/
			LCD_enuWriteCommand(1);
			LCD_enuWriteString("Enter Password:");
			LCD_enuGoToPosition(2,1);
			TFT_vPasswordPanel();
		}
	}

}
/***************************End of PasswordTap  function *******************************/


/**************************** WelcomeTap  Function ***********************************/
void WelcomeTap(s8* Copy_ps8RightPassword)
{
	u8 strItrr=0;									/*String Iterator for Each Password index */
	u8 static DimmerLedVal = 0;						/*Variable for Brightness Values*/
	u8 static PasswordIndex = 1;

	LCD_enuWriteCommand(1);				//clear screen
	LCD_enuGoToPosition(1,5);
	LCD_enuWriteString("Welcome!!");    //print on TFT
	TFT_vUserPanel();								/*open user panel */

	while(1)
	{
		key = NOT_PRESSED;
		TFT_vDrawTempValue(wanted_Temp);
		Keypad_GetPressedKey(&key);
		if (key != NOT_PRESSED)
		{
			if(LED_1_BUTTON==key || LED_2_BUTTON==key || LED_3_BUTTON==key || LED_4_BUTTON==key)
			{
				//LED control
				switch(key)
				{
				case LED_1_BUTTON: GPIO_vTogglePinValue(GPIO_A, Pin5);
				TFT_vToggle(1);
				break;
				case LED_2_BUTTON: GPIO_vTogglePinValue(GPIO_A, Pin6);
				TFT_vToggle(2);
				break;
				case LED_3_BUTTON: GPIO_vTogglePinValue(GPIO_A, Pin7);
				TFT_vToggle(3);
				break;
				case LED_4_BUTTON: GPIO_vTogglePinValue(GPIO_A, Pin8);
				TFT_vToggle(4);
				break;
				default:/*MESRA*/
					break;
				}
			}

			if(BRIGHTNESS_UP==key || BRIGHTNESS_DOWN==key)
			{
				//Brightness Dimmer control
				switch(key)
				{
				case BRIGHTNESS_UP: 	 //Brightness Up

					if(DimmerLedVal < 250)
					{
						DimmerLedVal +=50;
					}
					break;
				case BRIGHTNESS_DOWN:  	//Brightness Down
					if(DimmerLedVal > 0)
					{
						DimmerLedVal -=50;
					}
					break;
				default:/*MESRA*/
					break;
				}
				TFT_vControlDimmerLed(DimmerLedVal);
			}
			if(DOOR_OPEN ==key || DOOR_CLOSE==key)
			{
				//Door control
				switch(key)
				{
				case DOOR_OPEN :  //Open
					Door_Control(ENTER);
					TFT_vDoorOpened();
					break;
				case DOOR_CLOSE:  //Close
					Door_Control(EXIT);
					TFT_vDoorClosed();
					break;
				default:/*MESRA*/
					break;
				}
			}
			if(TEMP_UP==key || TEMP_DOWN==key)
			{
				//AC control
				switch(key)
				{
				case TEMP_UP:  //tempUp
					//Display_temp(wanted_Temp);
					wanted_Temp++;
					break;
				case TEMP_DOWN:  //tempDown
					wanted_Temp--;
					break;
				default:/*MESRA*/
					break;
				}

				/*print Wanted Temperature after updating */
				AC_AdjustTemperature(wanted_Temp);
				TFT_vDrawTempValue(wanted_Temp);

			}
			if(SYS_LOCK==key) //Lock the locker key
			{
				BeebSound();
				break;//back to main()
			}
			if(PASS_CHANGE==key) //change password key
			{
				BeebSound();
				//reset all RightPassword to zero
				for(strItrr = 0 ; strItrr<MAX_PASS_NUM ; strItrr++)
				{
					Copy_ps8RightPassword[strItrr] = 0;
				}
				strItrr = 0;
				/*************************/
				LCD_enuWriteCommand(1);
				LCD_enuGoToPosition(1,1);
				LCD_enuWriteString("New Password is:");
				LCD_enuGoToPosition(2,1);
				TFT_vChangePasswordPanel();     //New password Tap
				while(1)
				{
					key = NOT_PRESSED;
					Keypad_GetPressedKey(&key);
					if (key != NOT_PRESSED)
					{
						if(key >= '0' && key <='9')
						{
							BeebSound();
							LCD_enuWriteData('*');
							TFT_vDrawPassword(PasswordIndex);
							Copy_ps8RightPassword[strItrr] = key;
							strItrr++;
							PasswordIndex++;
						}
						else if('=' == key)
						{
							BeebSound();
							PasswordIndex = 1;
							break;
						}
					}
				}
				break; //back to main()
			}
		}
	}
}

void WrongTap(u8* Copy_ps8wrongInputRemain)
{
	if(*Copy_ps8wrongInputRemain  > 1)
	{
		*Copy_ps8wrongInputRemain -=1;
		LCD_enuWriteCommand(1);
		LCD_enuGoToPosition(1,5);
		LCD_enuWriteString("Wrong!!");
		LCD_enuGoToPosition(2,1);
		LCD_enuWriteIntegerNum(*Copy_ps8wrongInputRemain);
		LCD_enuWriteString(" trial left!!");
		TFT_vTrialLeft(*Copy_ps8wrongInputRemain);
		STK_DelayMs(500);
	}
	else{
		LCD_enuWriteCommand(1);
		LCD_enuWriteString("Calling Police...");
		TFT_vPolicePanel();
		Buzzer_TOG();
	}
}

u8 strEqual(s8* Copy_ps8str1 , s8 * Copy_ps8str2)
{
	while(*Copy_ps8str1 != 0 || *Copy_ps8str2 != 0)
	{
		STK_DelayMs(5);
		if(*Copy_ps8str1 == *Copy_ps8str2){
			Copy_ps8str1++;
			Copy_ps8str2++;
		}
		else{
			return STR_NEQL;
		}
	}
	return STR_EQL;
}

void BeebSound(void)
{
	GPIO_vWritePinValue(GPIO_A, Pin4, HighState);
	STK_DelayMs(100);
	GPIO_vWritePinValue(GPIO_A, Pin4, LowState);
}
void Buzzer_TOG( void )
{
	//BUZZER Waiting B0
	while(1)
	{
		GPIO_vTogglePinValue(GPIO_A, Pin4);
		STK_DelayMs(500);
	}
}


