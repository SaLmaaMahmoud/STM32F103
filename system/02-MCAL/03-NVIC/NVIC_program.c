#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		NVIC_ISER0 = (1 << Copy_u8IntNumber) ;
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32 ;
		NVIC_ISER1 = (1 << Copy_u8IntNumber) ;
	}
	else
	{
		/* Return Error */
	}
}


void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		NVIC_ICER0 = (1 << Copy_u8IntNumber) ;
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32 ;
		NVIC_ICER1 = (1 << Copy_u8IntNumber) ;
	}
	else
	{
		/* Return Error */
	}
}


void MNVIC_voidSetPendingFlag (u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		NVIC_ISPR0 = (1 << Copy_u8IntNumber) ;
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32 ;
		NVIC_ISPR1 = (1 << Copy_u8IntNumber) ;
	}
	else
	{
		/* Return Error */
	}
}


void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		NVIC_ICPR0 = (1 << Copy_u8IntNumber) ;
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32 ;
		NVIC_ICPR0 = (1 << Copy_u8IntNumber) ;
	}
	else
	{
		/* Return Error */
	}
}


u8 MNVIC_u8GetActiveFlag (u8 Copy_u8IntNumber)
{
	u8 Local_u8ActiveState ;
	
	if (Copy_u8IntNumber <= 31)
	{
		Local_u8ActiveState = GET_BIT(NVIC_IABR0 , Copy_u8IntNumber) ;
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32 ;
		Local_u8ActiveState = GET_BIT(NVIC_IABR0 , Copy_u8IntNumber) ;
	}
	else
	{
		/* Return Error */
	}
	
	return Local_u8ActiveState;
}


void MNVIC_voidSetPriority (s8 copy_s8IntID, u8 copy_u8GroupPriority, u8 copy_u8SubPriority, u32 copy_u32Group)
{
	u8 Local_u8Priority = copy_u8SubPriority | (copy_u8GroupPriority << ((copy_u32Group - 0x05FA0300) / 256)) ;
	
	/* External peripheral */
	if (copy_s8IntID >= 0)
	{
		IPR[copy_s8IntID] = Local_u8Priority << 4 ;
	}
	
	SCB_AIRCR = copy_u32Group ;
}