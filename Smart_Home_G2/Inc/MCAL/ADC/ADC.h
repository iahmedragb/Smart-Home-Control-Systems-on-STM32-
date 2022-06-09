/*
 * ADC.h
 *
 *  Created on: Apr 20, 2022
 *      Author: Ahmed
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

#define ON_STATE	1
#define OFF_STATE	0
#define ADC_SR_EOC						(1U<<1)

#define ADC_CR1_EOCIE					(1U<<5)
#define ADC_CR1_RES_12						(0U<<24)
#define ADC_CR1_RES_10						(1U<<24)
#define ADC_CR1_RES_8						(2U<<24)
#define ADC_CR1_RES_6						(3U<<24)
#define ADC_CR2_ADON						(1U<<0)
#define ADC_CR2_CONT						(1U<<1)
#define ADC_CR2_SWSTART						(1U<<30)
#define ADC_SQ1_ADC_L_1						(0<<20)


void ADC_Init(void);
u16 ADC_Read(void);
void ADC_AdjustValue(u8 *RequiredValue,void(*pAppFunStart)(void),void(*pAppFunStop)(void));
void ADC_Stop(void);
void ADC_Start(void);
#endif /* MCAL_ADC_ADC_H_ */
