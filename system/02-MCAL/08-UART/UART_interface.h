#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H


/********************** GLOBAL MACROS **********************/
/***********************************************************/
/* UART Channels */
#define	UART_1	0
#define	UART_2	1
/***********************************************************/


/******************** PUBPLIC FUNCTIONS ********************/
/***********************************************************/
/*	Description : Initialize UART protocol
	Parameters  : void
	Return      : None */
/***********************************************************/
void UART_voidInit(u8 cpy_u8CH) ;


/***********************************************************/
/*	Description : Transmit data to a paticular channel
	Parameters  : UART channel (1, 2, 3)
	Return      : None */
/***********************************************************/
void UART_voidTransimit(u8 cpy_u8CH , u8* arr) ;


/***********************************************************/
/*	Description : Receive data from a paticular channel
	Parameters  : UART channel (1, 2, 3)
	Return      : Data */
/***********************************************************/
u8 UART_u8Receive(u8 cpy_u8CH) ;


#endif
