


#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include	"DIO_interface.h"
#include	"DIO_private.h"
#include	"DIO_config.h"



void MGPIO_voidSetPortDirection(u8 copy_u8PORT , u8 copy_u8Mode)
{
	u8 Pin_Num = 0 ;
	
	switch (copy_u8PORT)
	{
		case	GPIOA :
			for(Pin_Num = 0 ; Pin_Num <= 7 ; Pin_Num++)
			{
				GPIOA_CRL |= ((copy_u8Mode) << (Pin_Num*4)) ;
			}
			
			for(Pin_Num = 8 ; Pin_Num <= 15 ; Pin_Num++)
			{
				GPIOA_CRH |= ((copy_u8Mode) << (Pin_Num*4)) ;
			}
			break ;
			
		case	GPIOB :
			for(Pin_Num = 0 ; Pin_Num <= 7 ; Pin_Num++)
			{
				GPIOB_CRL |= ((copy_u8Mode) << (Pin_Num*4)) ;
			}
			
			for(Pin_Num = 8 ; Pin_Num <= 15 ; Pin_Num++)
			{
				GPIOB_CRH |= ((copy_u8Mode) << (Pin_Num*4)) ;
			}
			break ;
		
		case	GPIOC :
			for(Pin_Num = 0 ; Pin_Num <= 7 ; Pin_Num++)
			{
				GPIOC_CRL |= ((copy_u8Mode) << (Pin_Num*4)) ;
			}
			
			for(Pin_Num = 8 ; Pin_Num <= 15 ; Pin_Num++)
			{
				GPIOC_CRH |= ((copy_u8Mode) << (Pin_Num*4)) ;
			}
			break ;
			
		default		:
			break ;
	}
}


void MGPIO_voidSetPortValue(u8 copy_u8PORT , u8 copy_u8Value)
{
	switch (copy_u8PORT)
	{
		case	GPIOA :
			GPIOA_ODR = copy_u8Value ;
			break ;
			
		case	GPIOB :
			GPIOB_ODR = copy_u8Value ;
			break ;
		
		case	GPIOC :
			GPIOC_ODR = copy_u8Value ;
			break ;
			
		default		:
			break ;
	}
}


u8 	 MGPIO_u8GetPortValue(u8 copy_u8PORT)
{
	u8 LOC_u8Result = 0 ;
	
	switch (copy_u8PORT)
	{
		case	GPIOA :
			LOC_u8Result = GPIOA_IDR ;
			break ;
			
		case	GPIOB :
			LOC_u8Result = GPIOB_IDR ;
			break ;
		
		case	GPIOC :
			LOC_u8Result = GPIOC_IDR ;
			break ;
			
		default		:
			break ;
	}
	
	return LOC_u8Result ;
}


void MGPIO_voidSetPinDirection(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8Mode)
{
	switch (copy_u8PORT)
	{
		case	GPIOA :
			if(copy_u8PIN <= 7)
			{
				GPIOA_CRL &= ~((0b1111) << (copy_u8PIN*4)) ;
				GPIOA_CRL |= ((copy_u8Mode) << (copy_u8PIN*4)) ;
			}
			else if(copy_u8PIN <= 15)
			{
				copy_u8PIN = copy_u8PIN - 8 ;
				GPIOA_CRH &= ~((0b1111) << (copy_u8PIN*4)) ;
				GPIOA_CRH |= ((copy_u8Mode) << (copy_u8PIN*4)) ;
			}
			break ;
			
		case	GPIOB :
			if(copy_u8PIN <= 7)
			{
				GPIOB_CRL &= ~((0b1111) << (copy_u8PIN*4)) ;
				GPIOB_CRL |= ((copy_u8Mode) << (copy_u8PIN*4)) ;
			}
			else if(copy_u8PIN <= 15)
			{
				copy_u8PIN = copy_u8PIN - 8 ;
				GPIOB_CRH &= ~((0b1111) << (copy_u8PIN*4)) ;
				GPIOB_CRH |= ((copy_u8Mode) << (copy_u8PIN*4)) ;
			}
			break ;
		
		case	GPIOC :
			if(copy_u8PIN <= 7)
			{
				GPIOC_CRL &= ~((0b1111) << (copy_u8PIN*4)) ;
				GPIOC_CRL |= ((copy_u8Mode) << (copy_u8PIN*4)) ;
			}
			else if(copy_u8PIN <= 15)
			{
				copy_u8PIN = copy_u8PIN - 8 ;
				GPIOC_CRH &= ~((0b1111) << (copy_u8PIN*4)) ;
				GPIOC_CRH |= ((copy_u8Mode) << (copy_u8PIN*4)) ;
			}
			break ;
			
		default		:
			break ;
	}
}

void MGPIO_voidSetPinValue(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8Value)
{
	switch (copy_u8PORT)
	{
		case	GPIOA :
			if(copy_u8Value == GPIO_HIGH)
			{
				GPIOA_BSR = (1 << copy_u8PIN) ;
			}
			else if(copy_u8Value == GPIO_LOW)
			{
				GPIOA_BRR = (1 << copy_u8PIN) ;
			}
			break ;
			
		case	GPIOB :
			if(copy_u8Value == GPIO_HIGH)
			{
				GPIOB_BSR = (1 << copy_u8PIN) ;
			}
			else if(copy_u8Value == GPIO_LOW)
			{
				GPIOB_BRR = (1 << copy_u8PIN) ;
			}
			break ;
		
		case	GPIOC :
			if(copy_u8Value == GPIO_HIGH)
			{
				GPIOC_BSR = (1 << copy_u8PIN) ;
			}
			else if(copy_u8Value == GPIO_LOW)
			{
				GPIOC_BRR = (1 << copy_u8PIN) ;
			}
			break ;
			
		default		:
			break ;
	}
}


void MGPIO_voidTogglePinValue(u8 copy_u8PORT , u8 copy_u8PIN)
{
	switch (copy_u8PORT)
	{
		case	GPIOA :
			TOGGLE_BIT(GPIOA_ODR , copy_u8PIN) ;
			break ;
			
		case	GPIOB :
			TOGGLE_BIT(GPIOB_ODR , copy_u8PIN) ;
			break ;
		
		case	GPIOC :
			TOGGLE_BIT(GPIOC_ODR , copy_u8PIN) ;
			break ;
			
		default		:
			break ;
	}
}


u8 	 MGPIO_u8GetPinValue(u8 copy_u8PORT , u8 copy_u8PIN)
{
	u8 LOC_u8Result = 0 ;
	
	switch (copy_u8PORT)
	{
		case	GPIOA :
			LOC_u8Result = GET_BIT(GPIOA_IDR , copy_u8PIN) ;
			break ;
			
		case	GPIOB :
			LOC_u8Result = GET_BIT(GPIOB_IDR , copy_u8PIN) ;
			break ;
		
		case	GPIOC :
			LOC_u8Result = GET_BIT(GPIOC_IDR , copy_u8PIN) ;
			break ;
			
		default		:
			break ;
	}
	
	return LOC_u8Result ;
}


void MGPIO_voidLockPin(u8 copy_u8PORT , u8 copy_u8PIN)
{
	/* Set bit-16 (LCKK) */
	u32 LOCK_REG = 0x00010000 ;
	LOCK_REG |= (1 << copy_u8PIN) ;
	
	switch(copy_u8PORT)
	{
		case	GPIOA :
			/* LOCK Sequence */
			/* Set bit-16 (LCKK) */
			GPIOA_LCK = LOCK_REG ;
			/* Reset bit-16 (LCKK) */
			GPIOA_LCK = (1 << copy_u8PIN) ;
			/* set bit-16 (LCKK) */
			GPIOA_LCK = LOCK_REG ;
			/* Read bit-16 (LCKK) */
			LOCK_REG = GPIOA_LCK ;
			/* Read bit-16 (LCKK) */
			LOCK_REG = GPIOA_LCK ;
			break ;
			
		case	GPIOB :
			/* LOCK Sequence */
			/* Set bit-16 (LCKK) */
			GPIOB_LCK = LOCK_REG ;
			/* Reset bit-16 (LCKK) */
			GPIOB_LCK = (1 << copy_u8PIN) ;
			/* set bit-16 (LCKK) */
			GPIOB_LCK = LOCK_REG ;
			/* Read bit-16 (LCKK) */
			LOCK_REG = GPIOB_LCK ;
			/* Read bit-16 (LCKK) */
			LOCK_REG = GPIOB_LCK ;
			break ;
		
		case	GPIOC :
			/* LOCK Sequence */
			/* Set bit-16 (LCKK) */
			GPIOC_LCK = LOCK_REG ;
			/* Reset bit-16 (LCKK) */
			GPIOC_LCK = (1 << copy_u8PIN) ;
			/* set bit-16 (LCKK) */
			GPIOC_LCK = LOCK_REG ;
			/* Read bit-16 (LCKK) */
			LOCK_REG = GPIOC_LCK ;
			/* Read bit-16 (LCKK) */
			LOCK_REG = GPIOC_LCK ;
			break ;
			
		default		:
			break ;
	}
}