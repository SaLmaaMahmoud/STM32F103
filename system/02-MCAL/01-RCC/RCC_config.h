

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*	Options:	RCC_HSE_CRYSTAL
				RCC_HSE_RC
				RCC_HSI
				RCC_PLL			*/
#define RCC_CLOCK_TYPE	RCC_HSE_CRYSTAL


/*	Options:	RCC_PLL_IN_HSI_DIV_2
				RCC_PLL_IN_HSE_DIV_2
				RCC_PLL_IN_HSE		*/
/*  Note:		Select value only if you have PLL as input clock source	*/
#if	RCC_CLOCK_TYPE	==	RCC_PLL
#define	RCC_PLL_INPUT	RCC_PLL_IN_HSE_DIV_2
#endif


/* Options:  RCC_PLL_MUL_n (Choose n from 2 to 16) */
/* Note:	 Select value only if you have PLL as input clock source	*/
#if	RCC_CLOCK_TYPE	==	RCC_PLL
#define RCC_PLL_MUL_VAL		RCC_PLL_MUL_4
#endif	


#if RCC_CLOCK_TYPE == RCC_PLL
#if RCC_PLL_INPUT  == RCC_PLL_IN_HSE_DIV_2 || RCC_PLL_INPUT  == RCC_PLL_IN_HSE
/* Choose 1 to enable clock security system or 0 to disable */
#define RCC_CSSON	0
#endif
#endif


#endif