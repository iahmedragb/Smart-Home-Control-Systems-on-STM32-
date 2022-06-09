/*
 * ADC_Private.h
 *
 *  Created on: Apr 20, 2022
 *      Author: Ahmed
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

#define ADC1_BASE_ADDRESS 				0x40012000
#define ADC1_COMMON_BASE_ADDRESS 		0x40012300
typedef struct
{
  volatile u32 SR;     /*!< ADC status register,                         Address offset: 0x00 */
  volatile u32 CR1;    /*!< ADC control register 1,                      Address offset: 0x04 */
  volatile u32 CR2;    /*!< ADC control register 2,                      Address offset: 0x08 */
  volatile u32 SMPR1;  /*!< ADC sample time register 1,                  Address offset: 0x0C */
  volatile u32 SMPR2;  /*!< ADC sample time register 2,                  Address offset: 0x10 */
  volatile u32 JOFR1;  /*!< ADC injected channel data offset register 1, Address offset: 0x14 */
  volatile u32 JOFR2;  /*!< ADC injected channel data offset register 2, Address offset: 0x18 */
  volatile u32 JOFR3;  /*!< ADC injected channel data offset register 3, Address offset: 0x1C */
  volatile u32 JOFR4;  /*!< ADC injected channel data offset register 4, Address offset: 0x20 */
  volatile u32 HTR;    /*!< ADC watchdog higher threshold register,      Address offset: 0x24 */
  volatile u32 LTR;    /*!< ADC watchdog lower threshold register,       Address offset: 0x28 */
  volatile u32 SQR1;   /*!< ADC regular sequence register 1,             Address offset: 0x2C */
  volatile u32 SQR2;   /*!< ADC regular sequence register 2,             Address offset: 0x30 */
  volatile u32 SQR3;   /*!< ADC regular sequence register 3,             Address offset: 0x34 */
  volatile u32 JSQR;   /*!< ADC injected sequence register,              Address offset: 0x38*/
  volatile u32 JDR1;   /*!< ADC injected data register 1,                Address offset: 0x3C */
  volatile u32 JDR2;   /*!< ADC injected data register 2,                Address offset: 0x40 */
  volatile u32 JDR3;   /*!< ADC injected data register 3,                Address offset: 0x44 */
  volatile u32 JDR4;   /*!< ADC injected data register 4,                Address offset: 0x48 */
  volatile u32 DR;     /*!< ADC regular data register,                   Address offset: 0x4C */
} ADC_TypeDef;
typedef struct
{
  volatile u32 CSR;    /*!< ADC Common status register,                  Address offset: ADC1 base address + 0x300 */
  volatile u32 CCR;    /*!< ADC common control register,                 Address offset: ADC1 base address + 0x304 */
  volatile u32 CDR;    /*!< ADC common regular data register for dual
                             AND triple modes,                            Address offset: ADC1 base address + 0x308 */
} ADC_Common_TypeDef;
#define ADC1			((ADC_TypeDef*)(ADC1_BASE_ADDRESS))
#define ADC1_COMMON			((ADC_Common_TypeDef*)(ADC1_COMMON_BASE_ADDRESS))
#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
