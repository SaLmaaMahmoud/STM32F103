#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


#define	GROUP3		0x05FA0300	// 4 bits for group
#define	GROUP4		0x05FA0400	// 3 bits for group and 1 bit for sub
#define	GROUP5		0x05FA0500	// 2 bits for group and 2 bit for sub
#define	GROUP6		0x05FA0600	// 1 bits for group and 3 bit for sub
#define	GROUP7		0x05FA0700	// 0 bits for group and 4 bit for sub


/******************** PUBPLIC FUNCTIONS ********************/
/***********************************************************/
/*	Description : Enable Interrupt
	Parameters  : Interrupt Number
	Return      : None */
/***********************************************************/
void MNVIC_voidEnableInterrupt  (u8 Copy_u8IntNumber);


/***********************************************************/
/*	Description : Disable Interrupt
	Parameters  : Interrupt Number
	Return      : None */
/***********************************************************/
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber);


/***********************************************************/
/*	Description : Set Interrupt into Pending state
	Parameters  : Interrupt Number
	Return      : None */
/***********************************************************/
void MNVIC_voidSetPendingFlag   (u8 Copy_u8IntNumber);


/***********************************************************/
/*	Description : Remove the pending state from Interrupt
	Parameters  : Interrupt Number
	Return      : None */
/***********************************************************/
void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber);


/***********************************************************/
/*	Description : Check if Interrupt is active or not
	Parameters  : Interrupt Number
	Return      : Interrupt status */
/***********************************************************/
u8 MNVIC_u8GetActiveFlag (u8 Copy_u8IntNumber);


/***********************************************************/
/*	Description : Set Priority of Interrupt
	Parameters  : Interrupt Number, Gruop Priority, SubGroup Priority, Group Number
	Return      : None */
/***********************************************************/
void MNVIC_voidSetPriority (s8 copy_s8IntID, u8 copy_u8GroupPriority, u8 copy_u8SubPriority, u32 copy_u32Group);

/***********************************************************/



#endif