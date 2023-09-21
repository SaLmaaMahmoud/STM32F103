

#ifndef		PWM_PRIVATE_H
#define		PWM_PRIVATE_H


/******************** REGISTERS DEFINITION ********************/
/* REGISTERS BASE ADDRESSES */
#define		TIM1_BASE_ADDRESS		0x40012C00

/* REGISTERS ADDRESSES FOR TIM1 */
#define		TIM1_CR1				*((u32 *)(TIM1_BASE_ADDRESS + 0x00))
#define		TIM1_CR2				*((u32 *)(TIM1_BASE_ADDRESS + 0x04))
#define		TIM1_SMCR				*((u32 *)(TIM1_BASE_ADDRESS + 0x08))
#define		TIM1_DIER				*((u32 *)(TIM1_BASE_ADDRESS + 0x0C))
#define		TIM1_SR					*((u32 *)(TIM1_BASE_ADDRESS + 0x10))
#define		TIM1_EGR				*((u32 *)(TIM1_BASE_ADDRESS + 0x14))
#define		TIM1_CCMR1				*((u32 *)(TIM1_BASE_ADDRESS + 0x18))
#define		TIM1_CCMR2				*((u32 *)(TIM1_BASE_ADDRESS + 0x1C))
#define		TIM1_CCER				*((u32 *)(TIM1_BASE_ADDRESS + 0x20))
#define		TIM1_CNT				*((u32 *)(TIM1_BASE_ADDRESS + 0x24))
#define		TIM1_PSC				*((u32 *)(TIM1_BASE_ADDRESS + 0x28))
#define		TIM1_ARR				*((u32 *)(TIM1_BASE_ADDRESS + 0x2C))
#define		TIM1_RCR				*((u32 *)(TIM1_BASE_ADDRESS + 0x30))
#define		TIM1_CCR1				*((u32 *)(TIM1_BASE_ADDRESS + 0x34))
#define		TIM1_CCR2				*((u32 *)(TIM1_BASE_ADDRESS + 0x38))
#define		TIM1_CCR3				*((u32 *)(TIM1_BASE_ADDRESS + 0x3C))
#define		TIM1_CCR4				*((u32 *)(TIM1_BASE_ADDRESS + 0x40))
#define		TIM1_BDTR				*((u32 *)(TIM1_BASE_ADDRESS + 0x44))
#define		TIM1_DCR				*((u32 *)(TIM1_BASE_ADDRESS + 0x48))
#define		TIM1_DMAR				*((u32 *)(TIM1_BASE_ADDRESS + 0x4C))


/* CONTROL REGISTER 1 */
#define		TIM1_CR1_CEN				0
#define		TIM1_CR1_UDIS				1
#define		TIM1_CR1_URS				2
#define		TIM1_CR1_OPM				3
#define		TIM1_CR1_DIR				4
#define		TIM1_CR1_CMS0				5
#define		TIM1_CR1_CMS1				6
#define		TIM1_CR1_ARPE				7
#define		TIM1_CR1_CKD0				8
#define		TIM1_CR1_CKD1				9


/* DMA/INTERRUPT ENABLE REGISTER */
#define		TIM1_DIER_UIE				0
#define		TIM1_DIER_CC1IE				1
#define		TIM1_DIER_CC2IE				2
#define		TIM1_DIER_CC3IE				3
#define		TIM1_DIER_CC4IE				4
#define		TIM1_DIER_COMIE				5
#define		TIM1_DIER_TIE				6
#define		TIM1_DIER_BIE				7
#define		TIM1_DIER_UDE				8
#define		TIM1_DIER_CC1DE				9
#define		TIM1_DIER_CC2DE				10
#define		TIM1_DIER_CC3DE				11
#define		TIM1_DIER_CC4DE				12
#define		TIM1_DIER_COMDE				13
#define		TIM1_DIER_TDE				14


/* CAPTURE/COMPARE MODE REGISTER 1 */
#define		TIM1_CCMR1_CC1S0			0
#define		TIM1_CCMR1_CC1S1			1
#define		TIM1_CCMR1_OC1FE			2
#define		TIM1_CCMR1_OC1PE			3
#define		TIM1_CCMR1_OC1M0			4
#define		TIM1_CCMR1_OC1M1			5
#define		TIM1_CCMR1_OC1M2			6
#define		TIM1_CCMR1_OC1CE			7
#define		TIM1_CCMR1_CC2S0			8
#define		TIM1_CCMR1_CC2S1			9
#define		TIM1_CCMR1_OC2FE			10
#define		TIM1_CCMR1_OC2PE			11
#define		TIM1_CCMR1_OC2M0			12
#define		TIM1_CCMR1_OC2M1			13
#define		TIM1_CCMR1_OC2M2			14
#define		TIM1_CCMR1_OC2CE			15


/* CAPTURE/COMPARE MODE REGISTER 2 */
#define		TIM1_CCMR2_CC3S0			0
#define		TIM1_CCMR2_CC3S1			1
#define		TIM1_CCMR2_OC3FE			2
#define		TIM1_CCMR2_OC3PE			3
#define		TIM1_CCMR2_OC3M0			4
#define		TIM1_CCMR2_OC3M1			5
#define		TIM1_CCMR2_OC3M2			6
#define		TIM1_CCMR2_OC3CE			7
#define		TIM1_CCMR2_CC4S0			8
#define		TIM1_CCMR2_CC4S1			9
#define		TIM1_CCMR2_OC4FE			10
#define		TIM1_CCMR2_OC4PE			11
#define		TIM1_CCMR2_OC4M0			12
#define		TIM1_CCMR2_OC4M1			13
#define		TIM1_CCMR2_OC4M2			14
#define		TIM1_CCMR2_OC4CE			15


/* CAPTURE/COMPARE ENABLE REGISTER */
#define		TIM1_CCER_CC1E				0
#define		TIM1_CCER_CC1P				1
#define		TIM1_CCER_CC1NE				2
#define		TIM1_CCER_CC1NP				3
#define		TIM1_CCER_CC2E				4
#define		TIM1_CCER_CC2P				5
#define		TIM1_CCER_CC2NE				6
#define		TIM1_CCER_CC2NP				7
#define		TIM1_CCER_CC3E				8
#define		TIM1_CCER_CC3P				9
#define		TIM1_CCER_CC3NE				10
#define		TIM1_CCER_CC3NP				11
#define		TIM1_CCER_CC4E				12
#define		TIM1_CCER_CC4P				13


/* EVENT GENERATION REGISTER */
#define		TIM1_EGR_UG					0
#define		TIM1_EGR_TG					6
#define		TIM1_EGR_BG					7


/* BREAK AND DEAD-TIME REGISTER */
#define		TIM1_BDTR_BKE				12
#define		TIM1_BDTR_BKP				13
#define		TIM1_BDTR_AOE				14
#define		TIM1_BDTR_MOE				15
/**************************************************************/

/* PWM MODES */
#define		TIM1_PWM_EDGE_ALIGNED		0
#define		TIM1_PWM_CENTER_ALIGNED		1


/* TIMER COUNTING MODES */
#define		TIM1_UPCOUNTING				0
#define		TIM1_DOWNCOUNTING			1
#define		TIM1_UP_DOWN_COUNTING		2
	
	
/* PWM MODEx */	
#define		TIM1_PWM_MODE1				0
#define		TIM1_PWM_MODE2				1

#endif
