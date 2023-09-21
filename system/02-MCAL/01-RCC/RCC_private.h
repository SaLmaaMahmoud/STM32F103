

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/******************** REGISTERS DEFINITION ********************/
#define	RCC_CR			*((u32*)0x40021000)
#define RCC_CFGR		*((u32*)0x40021004)
#define RCC_CIR			*((u32*)0x40021008)
#define RCC_APB2RSTR	*((u32*)0x4002100C)
#define RCC_APB1RSTR	*((u32*)0x40021010)
#define RCC_AHBENR		*((u32*)0x40021014)
#define RCC_APB2ENR		*((u32*)0x40021018)
#define RCC_APB1ENR		*((u32*)0x4002101C)
#define RCC_BDCR		*((u32*)0x40021020)
#define RCC_CSR			*((u32*)0x40021024)
/**************************************************************/


/* Clock Types */
#define RCC_HSE_CRYSTAL			0
#define RCC_HSE_RC				1
#define RCC_HSI					2
#define RCC_PLL					3


/* PLL Options */
#define	RCC_PLL_IN_HSI_DIV_2	0
#define	RCC_PLL_IN_HSE_DIV_2	1
#define	RCC_PLL_IN_HSE			2


/* PLL Multiplyer */
#define RCC_PLL_MUL_2			0x00000000
#define RCC_PLL_MUL_3			0x00040000
#define RCC_PLL_MUL_4			0x00080000
#define RCC_PLL_MUL_5			0x000C0000
#define RCC_PLL_MUL_6			0x00100000
#define RCC_PLL_MUL_7			0x00140000
#define RCC_PLL_MUL_8			0x00180000
#define RCC_PLL_MUL_9			0x001C0000
#define RCC_PLL_MUL_10			0x00200000
#define RCC_PLL_MUL_11			0x00240000
#define RCC_PLL_MUL_12			0x00280000
#define RCC_PLL_MUL_13			0x002C0000
#define RCC_PLL_MUL_14			0x00300000
#define RCC_PLL_MUL_15			0x00340000
#define RCC_PLL_MUL_16			0x00380000


/* CLOCK CONTROL REGISTER */
#define RCC_CR_HSION		0
#define RCC_CR_HSIRDY		1
#define RCC_CR_HSITRIM0		3
#define RCC_CR_HSITRIM1		4
#define RCC_CR_HSITRIM2		5
#define RCC_CR_HSITRIM3		6
#define RCC_CR_HSITRIM4		7
#define RCC_CR_HSICAL0		8
#define RCC_CR_HSICAL1		9
#define RCC_CR_HSICAL2		10
#define RCC_CR_HSICAL3		11
#define RCC_CR_HSICAL4		12
#define RCC_CR_HSICAL5		13
#define RCC_CR_HSICAL6		14
#define RCC_CR_HSICAL7		15
#define RCC_CR_HSEON		16
#define RCC_CR_HSERDY		17
#define RCC_CR_HSEBYP		18
#define RCC_CR_CSSON    	19
#define RCC_CR_PLLON		24
#define RCC_CR_PLLRDY		25


/* CLOCK CONFIGURATION REGISTER */
#define RCC_CFGR_SW0		0
#define RCC_CFGR_SW1		1
#define RCC_CFGR_SWS0		2
#define RCC_CFGR_SWS1		3
#define RCC_CFGR_HPRE0		4
#define RCC_CFGR_HPRE1		5
#define RCC_CFGR_HPRE2		6
#define RCC_CFGR_HPRE3		7
#define RCC_CFGR_PPRE1_0	8
#define RCC_CFGR_PPRE1_1	9
#define RCC_CFGR_PPRE1_2	10
#define RCC_CFGR_PPRE2_0	11
#define RCC_CFGR_PPRE2_1	12
#define RCC_CFGR_PPRE2_2	13
#define RCC_CFGR_ADCPRE0	14
#define RCC_CFGR_ADCPRE1	15
#define RCC_CFGR_PLLSRC		16
#define RCC_CFGR_PLLXTPRE	17
#define RCC_CFGR_PLLMUL0	18
#define RCC_CFGR_PLLMUL1	19
#define RCC_CFGR_PLLMUL2	20
#define RCC_CFGR_PLLMUL3	21
#define RCC_CFGR_USDPRE		22
#define RCC_CFGR_MCO0		24
#define RCC_CFGR_MCO1		25
#define RCC_CFGR_MCO2		26


#endif