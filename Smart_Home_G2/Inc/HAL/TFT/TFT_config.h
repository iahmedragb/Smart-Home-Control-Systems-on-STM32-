/*
 * TFT_config.h
 *
 *  Created on: April 25, 2022
 *  Author    : Abdelhai Tahoon
 *  Version   : 1.0
 */

#ifndef TFT_CONFIG_H
#define TFT_CONFIG_H


#define TFT_SPI_CLK_PIN 		GPIO_B,Pin10
#define TFT_SPI_MOSI_PIN		GPIO_B,Pin15
/*	set for sending data clear for sending command */
#define  TFT_DC_PIN			GPIO_B,Pin9
/*
	SPI_Config_TFT :
			config of SPI 
			MSPI1_t-> CR1 = 0x0347 ;
			Clock Ideal High `	   -------	Clock Polarity = 1
			With full Master Write -------	Clock Phase    = 1
			Need Mosst Significant -------  LSB Frist      = 0
			BR		---------------------------------	   = 000

*/
#define TFT_RESET_PIN		GPIO_B,Pin1




#endif //TFT_CONFIG_H
