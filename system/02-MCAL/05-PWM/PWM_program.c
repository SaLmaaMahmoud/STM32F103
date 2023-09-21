

#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include	"PWM_interface.h"
#include	"PWM_private.h"
#include	"PWM_config.h"



void PWM_voidInitTim1PWM(void)
{
	/* Enable Auto-Reload Preload Register */
	SET_BIT(TIM1_CR1 , TIM1_CR1_ARPE) ;

	#if 	TIM1_PWM_MODE == TIM1_PWM_EDGE_ALIGNED
		CLR_BIT(TIM1_CR1 , TIM1_CR1_CMS0) ;
		CLR_BIT(TIM1_CR1 , TIM1_CR1_CMS1) ;
		
		#if		TIM1_COUNTING_MODE == TIM1_UPCOUNTING
			CLR_BIT(TIM1_CR1 , TIM1_CR1_DIR) ;			/* Select UpCounting mode */
		#elif	TIM1_COUNTING_MODE == TIM1_DOWNCOUNTING
			SET_BIT(TIM1_CR1 , TIM1_CR1_DIR) ;			/* Select DownCounting mode */
		#endif
		
	#elif	TIM1_PWM_MODE == TIM1_PWM_CENTER_ALIGNED
	
		#if		TIM1_COUNTING_MODE == TIM1_UPCOUNTING
			CLR_BIT(TIM1_CR1 , TIM1_CR1_CMS0) ;
			SET_BIT(TIM1_CR1 , TIM1_CR1_CMS1) ;
			
			CLR_BIT(TIM1_CR1 , TIM1_CR1_DIR) ;
			
		#elif	TIM1_COUNTING_MODE == TIM1_DOWNCOUNTING
			SET_BIT(TIM1_CR1 , TIM1_CR1_CMS0) ;
			CLR_BIT(TIM1_CR1 , TIM1_CR1_CMS1) ;
			
			SET_BIT(TIM1_CR1 , TIM1_CR1_DIR) ;
			
		#elif	TIM1_COUNTING_MODE == TIM1_UP_DOWN_COUNTING
			SET_BIT(TIM1_CR1 , TIM1_CR1_CMS0) ;
			SET_BIT(TIM1_CR1 , TIM1_CR1_CMS1) ;
			
			SET_BIT(TIM1_CR1 , TIM1_CR1_DIR) ;
		#endif
	#endif
	
	
	#if TIM1_INTERRUPT_MODE == ENABLE
		/* Enable Interruupt */
		SET_BIT(TIM1_DIER , TIM1_DIER_UIE) ;		
	#endif
	
	/* Setting Prescaler */
	/* Fpwm = Ftim / (PSC * ARR) */
	/* Fpwm = 50Hz , Ftim = 8MHZ */
	TIM1_PSC = TIM1_PRESCALER ;
	
	/* Setting Auto_Reload Register value */
	TIM1_ARR = TIM1_AUTO_RELOAD_VALUE ;
	
	/* Initialize all the registers */
	SET_BIT(TIM1_EGR , TIM1_EGR_UG) ;
	
	/* Enable Timer main output*/
	SET_BIT(TIM1_BDTR , TIM1_BDTR_MOE) ;
}


void PWM_voidSelectChannel(u8 copy_u8Channel)
{
	switch(copy_u8Channel)
	{
		case	CH1 :
			#if 	TIM1_PWM_CH1_MODEx == TIM1_PWM_MODE1
				CLR_BIT(TIM1_CCMR1 , TIM1_CCMR1_OC1M0) ;
				SET_BIT(TIM1_CCMR1 , TIM1_CCMR1_OC1M1) ;
				SET_BIT(TIM1_CCMR1 , TIM1_CCMR1_OC1M2) ;
			#elif	TIM1_PWM_CH1_MODEx == TIM1_PWM_MODE2
				SET_BIT(TIM1_CCMR1 , TIM1_CCMR1_OC1M0) ;
				SET_BIT(TIM1_CCMR1 , TIM1_CCMR1_OC1M1) ;
				SET_BIT(TIM1_CCMR1 , TIM1_CCMR1_OC1M2) ;
			#endif

			/* Disable Channel 1 */
			CLR_BIT(TIM1_CCER , TIM1_CCER_CC1E) ;

			/* Set Channel 1 as output */
			/* CC1S bits are writable only when the channel is OFF */
			CLR_BIT(TIM1_CCMR1 , TIM1_CCMR1_CC1S0) ;
			CLR_BIT(TIM1_CCMR1 , TIM1_CCMR1_CC1S1) ;

			/* Enable Preload Register for Channel 1 */
			SET_BIT(TIM1_CCMR1 , TIM1_CCMR1_OC1PE) ;

			/* Select output polarity for Channel 1 as HIGH */
			CLR_BIT(TIM1_CCER , TIM1_CCER_CC1P) ;

			/* Enable Channel 1 as output*/
			SET_BIT(TIM1_CCER , TIM1_CCER_CC1E) ;
			break ;

		case	CH2 :
			#if 	TIM1_PWM_CH2_MODEx == TIM1_PWM_MODE1
				CLR_BIT(TIM1_CCMR1 , TIM1_CCMR1_OC2M0) ;
				SET_BIT(TIM1_CCMR1 , TIM1_CCMR1_OC2M1) ;
				SET_BIT(TIM1_CCMR1 , TIM1_CCMR1_OC2M2) ;
			#elif	TIM1_PWM_CH2_MODEx == TIM1_PWM_MODE2
				SET_BIT(TIM1_CCMR1 , TIM1_CCMR1_OC2M0) ;
				SET_BIT(TIM1_CCMR1 , TIM1_CCMR1_OC2M1) ;
				SET_BIT(TIM1_CCMR1 , TIM1_CCMR1_OC2M2) ;
			#endif

			/* Disable Channel 2 */
			CLR_BIT(TIM1_CCER , TIM1_CCER_CC2E) ;

			/* Set Channel 2 as output */
			/* CC2S bits are writable only when the channel is OFF */
			CLR_BIT(TIM1_CCMR1 , TIM1_CCMR1_CC2S0) ;
			CLR_BIT(TIM1_CCMR1 , TIM1_CCMR1_CC2S1) ;

			/* Enable Preload Register for Channel 2 */
			SET_BIT(TIM1_CCMR1 , TIM1_CCMR1_OC2PE) ;

			/* Select output polarity for Channel 2 as HIGH */
			CLR_BIT(TIM1_CCER , TIM1_CCER_CC2P) ;

			/* Enable Channel 2 as output*/
			SET_BIT(TIM1_CCER , TIM1_CCER_CC2E) ;
			break ;

		case	CH3 :
			#if 	TIM1_PWM_CH3_MODEx == TIM1_PWM_MODE1
				CLR_BIT(TIM1_CCMR2 , TIM1_CCMR2_OC3M0) ;
				SET_BIT(TIM1_CCMR2 , TIM1_CCMR2_OC3M1) ;
				SET_BIT(TIM1_CCMR2 , TIM1_CCMR2_OC3M2) ;
			#elif	TIM1_PWM_CH3_MODEx == TIM1_PWM_MODE2
				SET_BIT(TIM1_CCMR2 , TIM1_CCMR2_OC3M0) ;
				SET_BIT(TIM1_CCMR2 , TIM1_CCMR2_OC3M1) ;
				SET_BIT(TIM1_CCMR2 , TIM1_CCMR2_OC3M2) ;
			#endif

			/* Disable Channel 3 */
			CLR_BIT(TIM1_CCER , TIM1_CCER_CC3E) ;

			/* Set Channel 3 as output */
			/* CC3S bits are writable only when the channel is OFF */
			CLR_BIT(TIM1_CCMR2 , TIM1_CCMR2_CC3S0) ;
			CLR_BIT(TIM1_CCMR2 , TIM1_CCMR2_CC3S1) ;

			/* Enable Preload Register for Channel 3 */
			SET_BIT(TIM1_CCMR2 , TIM1_CCMR2_OC3PE) ;

			/* Select output polarity for Channel 3 as HIGH */
			CLR_BIT(TIM1_CCER , TIM1_CCER_CC3P) ;

			/* Enable Channel 3 as output*/
			SET_BIT(TIM1_CCER , TIM1_CCER_CC3E) ;
			break ;

		case	CH4 :
			#if 	TIM1_PWM_CH4_MODEx == TIM1_PWM_MODE1
				CLR_BIT(TIM1_CCMR2 , TIM1_CCMR2_OC4M0) ;
				SET_BIT(TIM1_CCMR2 , TIM1_CCMR2_OC4M1) ;
				SET_BIT(TIM1_CCMR2 , TIM1_CCMR2_OC4M2) ;
			#elif	TIM1_PWM_CH4_MODEx == TIM1_PWM_MODE2
				SET_BIT(TIM1_CCMR2 , TIM1_CCMR2_OC4M0) ;
				SET_BIT(TIM1_CCMR2 , TIM1_CCMR2_OC4M1) ;
				SET_BIT(TIM1_CCMR2 , TIM1_CCMR2_OC4M2) ;
			#endif

			/* Disable Channel 4 */
			CLR_BIT(TIM1_CCER , TIM1_CCER_CC4E) ;

			/* Set Channel 4 as output */
			/* CC4S bits are writable only when the channel is OFF */
			CLR_BIT(TIM1_CCMR2 , TIM1_CCMR2_CC4S0) ;
			CLR_BIT(TIM1_CCMR2 , TIM1_CCMR2_CC4S1) ;

			/* Enable Preload Register for Channel 4 */
			SET_BIT(TIM1_CCMR2 , TIM1_CCMR2_OC4PE) ;

			/* Select output polarity for Channel 4 as HIGH */
			CLR_BIT(TIM1_CCER , TIM1_CCER_CC4P) ;

			/* Enable Channel 4 as output*/
			SET_BIT(TIM1_CCER , TIM1_CCER_CC4E) ;
			break ;

		default	  :
			/* Return Error */
			break ;
	}
}


void PWM_viodSetDutyCycle(u8 copy_u8Channel , u8 copy_u8DutyCycle)
{
	switch(copy_u8Channel)
	{
		case	CH1 :
			/* Setting Duty Cycle for Channel 1 */
			TIM1_CCR1 = (copy_u8DutyCycle * TIM1_ARR) / 100 ;
			break ;

		case	CH2 :
			/* Setting Duty Cycle for Channel 2 */
			TIM1_CCR2 = (copy_u8DutyCycle * TIM1_ARR) / 100 ;
			break ;

		case	CH3 :
			/* Setting Duty Cycle for Channel 3 */
			TIM1_CCR3 = (copy_u8DutyCycle * TIM1_ARR) / 100 ;
			break ;

		case	CH4 :
			/* Setting Duty Cycle for Channel 4 */
			TIM1_CCR4 = (copy_u8DutyCycle * TIM1_ARR) / 100 ;
			break ;
	}

}


void PWM_voidStartTim1PWM(void)
{
	/* Counter Enabled */
	SET_BIT(TIM1_CR1 , TIM1_CR1_CEN) ;
}

void PWM_voidSetCCRx(u8 copy_u8Channel , u8 copy_u8CCRxValue)
{
	switch(copy_u8Channel)
	{
		case	CH1 :
			TIM1_CCR1 = copy_u8CCRxValue ;
			break ;

		case	CH2 :
			TIM1_CCR2 = copy_u8CCRxValue ;
			break ;

		case	CH3 :
			TIM1_CCR3 = copy_u8CCRxValue ;
			break ;

		case	CH4 :
			TIM1_CCR4 = copy_u8CCRxValue ;
			break ;
	}
}