

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidInitSysClock(void)
{
	#if 	RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		SET_BIT(RCC_CR 	 , RCC_CR_HSEON) ;			/* Enable HSE with no Bypass */
		
		/* Choose HSE */
		SET_BIT(RCC_CFGR , RCC_CFGR_SW0) ;			
		CLR_BIT(RCC_CFGR , RCC_CFGR_SW1) ;
		
		#if RCC_CSSON == 1
			SET_BIT(RCC_CR , RCC_CR_CSSON)	;		/* Enable clock security system */
		#endif
		
	#elif 	RCC_CLOCK_TYPE == RCC_HSE_RC
		SET_BIT(RCC_CR , RCC_CR_HSEON)	 ;			/* Enable HSE */
		SET_BIT(RCC_CR , RCC_CR_HSEBYP)	 ;			/* Enable Bypass */
		
		/* Choose HSE */
		SET_BIT(RCC_CFGR , RCC_CFGR_SW0) ;					
		CLR_BIT(RCC_CFGR , RCC_CFGR_SW1) ;
		
		#if RCC_CSSON == 1
			SET_BIT(RCC_CR , RCC_CR_CSSON)	;		/* Enable clock security system */
		#endif
		
	#elif 	RCC_CLOCK_TYPE == RCC_HSI
		SET_BIT(RCC_CR , RCC_CR_HSION) 	  ;			/* Enable HSI */
		SET_BIT(RCC_CR , RCC_CR_HSITRIM0) ;			/* Enable Trimming 0 */
		
		/* Choose HSI */
		CLR_BIT(RCC_CFGR , RCC_CFGR_SW0)  ;			
		CLR_BIT(RCC_CFGR , RCC_CFGR_SW1)  ;
		
	#elif	RCC_CLOCK_TYPE == RCC_PLL
		CLR_BIT(RCC_CR , RCC_CR_PLLON) ;			/* Disable PLL */
		
		/* These bits can be written only when PLL is disabled */
		RCC_CFGR &= ~(15 << RCC_CFGR_PLLMUL0) ;
		RCC_CFGR |= RCC_PLL_MUL_VAL ;
		
		#if 	RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
			SET_BIT(RCC_CR , RCC_CR_HSION)   ;		/* Enable HSI */
			CLR_BIT(RCC_CFGR , RCC_CFGR_SW0) ;		/* Choose HSI DIV 2 as PLL input clock */
			
		#elif 	RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
			SET_BIT(RCC_CR , RCC_CR_HSEON) ;		/* Enable HSE with no bypass */
			SET_BIT(RCC_CFGR , RCC_CFGR_PLLXTPRE);	/* Choose HSE DIV 2 as PLL input clock */
			
		#elif 	RCC_PLL_INPUT == RCC_PLL_IN_HSE
			SET_BIT(RCC_CR , RCC_CR_HSEON) ;		/* Enable HSE with no bypass */
			CLR_BIT(RCC_CFGR , RCC_CFGR_PLLXTPRE);	/* Choose HSE as PLL input clock */
			
		#endif
		
		SET_BIT(RCC_CR , RCC_CR_PLLON) ;			/* Enable PLL */
		
		/* Choose PLL */
		CLR_BIT(RCC_CFGR , RCC_CFGR_SW0) ;
		SET_BIT(RCC_CFGR , RCC_CFGR_SW1) ;
		
	#else
		#error("You chosed wrong Clock type")
	#endif
}

void RCC_voidEnableClock(u8 copy_u8BusId, u8 copy_u8PerId)
{
	if (copy_u8PerId <= 31)
	{
		switch (copy_u8BusId)
		{
			case RCC_AHB	: 
				SET_BIT(RCC_AHBENR , copy_u8PerId) ;		
				break ;
				
			case RCC_APB1   : 
				SET_BIT(RCC_APB1ENR , copy_u8PerId) ;		
				break ;
			case RCC_APB2   : 
				SET_BIT(RCC_APB2ENR , copy_u8PerId) ;		
				break ;
				
			default			: 
				/* Return Error */					
				break;
		}
	}
	else
	{
		/* Return Error */
	}
}

void RCC_voidDisableClock(u8 copy_u8BusId, u8 copy_u8PerId)
{
	if (copy_u8PerId <= 31)
	{
		switch (copy_u8BusId)
		{
			case RCC_AHB    : 
				CLR_BIT(RCC_AHBENR , copy_u8PerId) ;		
				break ;
				
			case RCC_APB1   : 
				CLR_BIT(RCC_APB1ENR , copy_u8PerId) ;		
				break ;
				
			case RCC_APB2   : 
				CLR_BIT(RCC_APB2ENR , copy_u8PerId) ;		
				break ;
				
			default			: 
				/* Return Error */					
				break;
		}
	}
	else
	{
		/* Return Error */
	}
}