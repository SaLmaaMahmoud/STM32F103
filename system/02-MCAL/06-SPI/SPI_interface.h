#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H


/******************** PUBPLIC FUNCTIONS ********************/
/***********************************************************/
/*	Description : Initialize SPI communication protocol
	Parameters  : void
	Return      : None */
/***********************************************************/
void MSPI1_voidInit(void);


/***********************************************************/
/*	Description : Send and Receive in Synchronous mode
	Parameters  : Tansmitted and Received Data
	Return      : None */
/***********************************************************/
void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceive);


/***********************************************************/
/*	Description : Send and Receive in Asynchronous mode
	Parameters  : Tansmitted Data
	Return      : None */
/***********************************************************/
void MSPI1_voidSendReceiveAsynch(u8 Copy_u8DataToTransmit, void (*CallBack)(u8));



#endif
