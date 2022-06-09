/*=======================================================================================
============================   - RCC_Program.c				 ============================
============================   - Created: 4/8/2022			 ============================
============================   - Author: Ragab			     ============================
============================   - Version : _1_				 ============================
============================   - Note :
									     *-
									     *-
=======================================================================================*/


/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "LIB/Std_Types.h"
		 #include "LIB/Bit_Math.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "MCAL/RCC/RCC_Private.h"
		#include "MCAL/RCC/RCC.h"
		#include "MCAL/RCC/RCC_Config.h"
/*======================================*/
/*===========  INCLUDE HAL   ===========*/


/*======================================*/

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
void RCC_vInitSystemCLK(void)
{
	#if 	CLKSRC	==	HSI
		SET_BIT(RCC->CR,0);
		while((GET_BIT(RCC->CR,1))==0);
		CLR_BIT(RCC->CFGR,0);
		CLR_BIT(RCC->CFGR,1);

	#elif 	CLKSRC	==	HSE
		#if 	HSE_SRC	== 	USER_RC
		SET_BIT(RCC->CR,18);
		#elif	HSE_SRC	==	CRYSTAL_CERAMIC
		CLR_BIT(RCC->CR,18);
		#else
			#error "Invalid High Speed External (HSE) Signal Source"
		#endif
		/*CSSON
		SET_BIT(RCC->CR,19);*/
		SET_BIT(RCC->CR,16);
		while((GET_BIT(RCC->CR,17))==0);
		SET_BIT(RCC->CFGR,0);
		CLR_BIT(RCC->CFGR,1);
	#elif	CLKSRC	==	PLL
		#if 	PLL_SRC	== 	HSI_PLL
		SET_BIT(RCC->CR,0);
		while((GET_BIT(RCC->CR,1))==0);
		#elif	PLL_SRC	==	HSE_PLL
			#if 	HSE_SRC	== 	USER_RC
			SET_BIT(RCC->CR,18);
			#elif	HSE_SRC	==	CRYSTAL_CERAMIC
			CLR_BIT(RCC->CR,18);
			#else
				#error "Invalid High Speed External (HSE) Signal Source"
			#endif
			/*CSSON
			SET_BIT(RCC->CR,19);*/
			SET_BIT(RCC->CR,16);
			while((GET_BIT(RCC->CR,17))==0);
		#else
			#error "Invalid Phased Locked Loop (PLL) Signal Source"
		#endif
		SET_BIT(RCC->CR,24);
		while((GET_BIT(RCC->CR,25))==0);
		CLR_BIT(RCC->CFGR,0);
		SET_BIT(RCC->CFGR,1);
	#else
		#error	"Invalid System Clock Source"
	#endif
}

/*====================================================   END_ FUNCTION   ====================================================*/
void RCC_vEnableClock(BusName_t BusName , u8 Copy_u8PerNum )
{
	if((BusName <=3)&&(Copy_u8PerNum <=31))
	{
		switch(BusName)
		{
			case AHB1_BUS:  SET_BIT(RCC->AHB1ENR,Copy_u8PerNum );         break ;
			case AHB2_BUS:  SET_BIT(RCC->AHB2ENR,Copy_u8PerNum );         break ;
			case APB1_BUS:  SET_BIT(RCC->APB1ENR,Copy_u8PerNum );         break ;
			case APB2_BUS:  SET_BIT(RCC->APB2ENR,Copy_u8PerNum );         break ;
			default :     /*   ERROR   */          break ;

		}
	}
}

/*====================================================   Start_FUNCTION   ====================================================*/

void RCC_vDisableClock(BusName_t BusName , u8 Copy_u8PerNum )
{
	if((BusName <=3)&&(Copy_u8PerNum <=31))
	{
		switch(BusName)
		{
			case AHB1_BUS:  CLR_BIT(RCC->AHB1ENR,Copy_u8PerNum );         break ;
			case AHB2_BUS:  CLR_BIT(RCC->AHB2ENR,Copy_u8PerNum );         break ;
			case APB1_BUS:  CLR_BIT(RCC->APB1ENR,Copy_u8PerNum );         break ;
			case APB2_BUS:  CLR_BIT(RCC->APB2ENR,Copy_u8PerNum );         break ;
			default :     /*   ERROR   */          break ;

		}
	}
}
/*====================================================   END_ FUNCTION   ====================================================*/
void RCC_vEnableSecuritySystem(void)
{
	SET_BIT(RCC->CR,19);
}

/*====================================================   Start_FUNCTION   ====================================================*/
void RCC_vDisableSecuritySystem(void)
{
	CLR_BIT(RCC->CR,19);
}

/*====================================================   END_ FUNCTION   ====================================================*/


/*====================================================   Start_FUNCTION   ====================================================*/


/*====================================================   END_ FUNCTION   ====================================================*/


/*====================================================   Start_FUNCTION   ====================================================*/


/*====================================================   END_ FUNCTION   ====================================================*/


/*====================================================   Start_FUNCTION   ====================================================*/


/*====================================================   END_ FUNCTION   ====================================================*/


/*====================================================   Start_FUNCTION   ====================================================*/


/*====================================================   END_ FUNCTION   ====================================================*/
