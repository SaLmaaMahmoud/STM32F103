

#ifndef		PWM_INTERFACE_H
#define		PWM_INTERFACE_H

/********************** GLOBAL MACROS **********************/
/***********************************************************/
/* PWM CHANNELS */
#define		CH1			1
#define		CH2			2
#define		CH3			3
#define		CH4			4
/***********************************************************/

/***********************************************************/
/* STATE */
#define		DISABLE		0
#define		ENABLE		1
/***********************************************************/


/******************** PUBPLIC FUNCTIONS ********************/
/***********************************************************/
/*	Description : Initialize PWM
	Parameters  : void
	Return      : None */
/***********************************************************/
void PWM_voidInitTim1PWM(void) ;


/***********************************************************/
/*	Description : Select PWM Channel
	Parameters  : Channel
	Return      : None */
/***********************************************************/
void PWM_voidSelectChannel(u8 copy_u8Channel) ;


/***********************************************************/
/*	Description : Select PWM Duty Cycle for each Channel
	Parameters  : Channel , DutyCycle
	Return      : None */
/***********************************************************/
void PWM_viodSetDutyCycle(u8 copy_u8Channel , u8 copy_u8DutyCycle) ;


/***********************************************************/
/*	Description : Start PWM
	Parameters  : void
	Return      : None */
/***********************************************************/
void PWM_voidStartTim1PWM(void) ;


/***********************************************************/
/*	Description : Select CCRx Value for each Channel
	Parameters  : Channel , CCRx_Value
	Return      : None */
/***********************************************************/
void PWM_voidSetCCRx(u8 copy_u8Channel , u8 copy_u8CCRxValue) ;


#endif
