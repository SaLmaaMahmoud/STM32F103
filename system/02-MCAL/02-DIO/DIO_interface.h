

#ifndef		DIO_INTERFACE_H
#define		DIO_INTERFACE_H

/******************** PUBPLIC REGISTERS ********************/
/* PIN STATES */
#define		GPIO_HIGH	1
#define		GPIO_LOW	0

/* PORTS Macros */
#define		GPIOA		0
#define		GPIOB		1
#define		GPIOC		2

/* PINS Macros */
#define		PIN0		0
#define		PIN1		1
#define		PIN2		2
#define		PIN3		3
#define		PIN4		4
#define		PIN5		5
#define		PIN6		6
#define		PIN7		7
#define		PIN8		8
#define		PIN9		9
#define		PIN10		10
#define		PIN11		11
#define		PIN12		12
#define		PIN13		13
#define		PIN14		14
#define		PIN15		15

/******* GPIO MODE DEFINITION *******/
/* INPUT MODES */
#define		INPUT_ANALOG				0b0000
#define		INPUT_FLOATING				0b0100
#define		INPUT_PULL_UP_DOWN			0b1000

/*** OUTPUT MODES ***/
/* For speed 10 */
#define		OUTPUT_SPEED_10MHZ_PP		0b0001
#define		OUTPUT_SPEED_10MHZ_OD		0b0101
#define		OUTPUT_SPEED_10MHZ_AFPP		0b1001
#define		OUTPUT_SPEED_10MHZ_AFOD		0b1101

/* For speed 2 */
#define		OUTPUT_SPEED_2MHZ_PP		0b0010
#define		OUTPUT_SPEED_2MHZ_OD		0b0110
#define		OUTPUT_SPEED_2MHZ_AFPP		0b1010
#define		OUTPUT_SPEED_2MHZ_AFOD		0b1110

/* For speed 50 */
#define		OUTPUT_SPEED_50MHZ_PP		0b0011
#define		OUTPUT_SPEED_50MHZ_OD		0b0111
#define		OUTPUT_SPEED_50MHZ_AFPP		0b1101
#define		OUTPUT_SPEED_50MHZ_AFOD		0b1111
/***********************************************************/


/******************** PUBPLIC FUNCTIONS ********************/
/***********************************************************/
/*	Description : Set PORT Direction
	Parameters  : PORT->(A,B,C)	, Mode 
	Return      : None */
/***********************************************************/
void MGPIO_voidSetPortDirection(u8 copy_u8PORT , u8 copy_u8Mode) ;

/***********************************************************/
/*	Description : Set PORT Value
	Parameters  : PORT->(A,B,C)	, Value->(0X00 - 0XFF) 
	Return      : None */
/***********************************************************/
void MGPIO_voidSetPortValue(u8 copy_u8PORT , u8 copy_u8Value) ;

/***********************************************************/
/*	Description : Get PORT Value
	Parameters  : PORT->(A,B,C)
	Return      : PORT Value */
/***********************************************************/
u8 	 MGPIO_u8GetPortValue(u8 cpy_u8PORT) ;

/***********************************************************/
/*	Description : Set Pin Direction
	Parameters  : PORT->(A,B,C)	, PIN->(0 - 15)	, Mode 
	Return      : None */
/***********************************************************/
void MGPIO_voidSetPinDirection(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8Mode) ;

/***********************************************************/
/*	Description : Set Pin Value
	Parameters  : PORT->(A,B,C)	, PIN->(0 - 15)	, Value->(HIGH , LOW) 
	Return      : None */
/***********************************************************/
void MGPIO_voidSetPinValue(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8Value) ;

/***********************************************************/
/*	Description : Toggle Pin Value
	Parameters  : PORT->(A,B,C)	, PIN->(0 - 15)
	Return      : None */
/***********************************************************/
void MGPIO_voidTogglePinValue(u8 copy_u8PORT , u8 copy_u8PIN) ;

/***********************************************************/
/*	Description : Get Pin Value
	Parameters  : PORT->(A,B,C)	, PIN->(0 - 15)
	Return      : Pin Value */
/***********************************************************/
u8 	 MGPIO_u8GetPinValue(u8 cpy_u8PORT , u8 copy_u8PIN) ;

/***********************************************************/
/*	Description : Lock Pin 
	Parameters  : PORT->(A,B,C)	, PIN->(0 - 15)
	Return      : void */
/***********************************************************/
void MGPIO_voidLockPin(u8 cpy_u8PORT , u8 copy_u8PIN) ;

/***********************************************************/


#endif
