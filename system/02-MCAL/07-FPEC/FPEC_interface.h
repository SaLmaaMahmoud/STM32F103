#ifndef FPEC_INTERFACE_H
#define FPEC_INTERFACE_H


/******************** PUBPLIC REGISTERS ********************/
/* SR register */
#define FPEC_SR_BSY		0
#define FPEC_SR_EOP		5

/* CR register */
#define FPEC_CR_PG		0
#define FPEC_CR_PER		1
#define FPEC_CR_MER		2
#define FPEC_CR_OPTER	5
#define FPEC_CR_STRT	6
#define FPEC_CR_LOCK	7



/******************** PUBPLIC FUNCTIONS ********************/
void FPEC_voidEraseAppArea(void);
	
void FPEC_voidFlashPageErase(u8 Copy_u8PageNumber);

void FPEC_voidFlashWrite(u32 Copy_u32Address, u16* Copy_u16Data, u8 Copy_u8Length);


#endif
