#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "FPEC_interface.h"
#include "FPEC_private.h"
#include "FPEC_config.h"



void FPEC_voidEraseAppArea(void)
{
	u8 page;
	
	for (page=4 ; page<64 ; page++)
	{
		FPEC_voidFlashPageErase(page);
	}
}

	
void FPEC_voidFlashPageErase(u8 Copy_u8PageNumber)
{
	/* Check that no main Flash memory operation is ongoing */
	while (GET_BIT(FPEC->SR , FPEC_SR_BSY) == 1);

	/* Check if FPEC is locked or not */
	if (GET_BIT(FPEC->CR , FPEC_CR_LOCK) == 1)
	{
		/* Perform unlock sequency */
		FPEC -> KEYR = 0x45670123;
		FPEC -> KEYR = 0xCDEF89AB;
	}
	
	/* Page Erase Operation */
	SET_BIT(FPEC->CR , FPEC_CR_PER);

	/* Write Page address to be selected to earse */
	FPEC->AR = (u32)(Copy_u8PageNumber * 1024) + 0x08000000 ;

	/* Start operation */
	SET_BIT(FPEC->CR , FPEC_CR_STRT);

	/* Wait Busy Flag */
	while (GET_BIT(FPEC->SR , FPEC_SR_BSY) == 1);

	/* Indicate the end of the program */
	SET_BIT(FPEC->SR , FPEC_SR_EOP);
	CLR_BIT(FPEC->CR , FPEC_CR_PER);
}


void FPEC_voidFlashWrite(u32 Copy_u32Address, u16* Copy_u16Data, u8 Copy_u8Length)
{
	u8 LOC_u8Length;
	volatile u16 Temp;

	/* Check that no main Flash memory operation is ongoing */
	while (GET_BIT(FPEC->SR , FPEC_SR_BSY) == 1);

	/* Check if FPEC is locked or not */
	if (GET_BIT(FPEC->CR , FPEC_CR_LOCK) == 1 )
	{
		/* Perform unlock sequency */
		FPEC -> KEYR = 0x45670123;
		FPEC -> KEYR = 0xCDEF89AB;
	}
	
	
	for (LOC_u8Length = 0; LOC_u8Length < Copy_u8Length; LOC_u8Length++)
	{
		/* Write Flash Programming */
		SET_BIT(FPEC->CR , FPEC_CR_PG);

		/* Half word operation */
		Temp = Copy_u16Data[LOC_u8Length];
		*((volatile u16*) Copy_u32Address) = Copy_u16Data[LOC_u8Length];
		Copy_u32Address += 2 ;

		/* Wait Busy Flag */
		while (GET_BIT(FPEC->SR , FPEC_SR_BSY) == 1);
	
		/* Indicate the end of the program */
		SET_BIT(FPEC->SR , FPEC_SR_EOP);
		CLR_BIT(FPEC->CR , FPEC_CR_PG);
	}
}