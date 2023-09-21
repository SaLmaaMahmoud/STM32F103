#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H


/******************** REGISTERS DEFINITION ********************/
/***********************************************************/
typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
	
}UART_t;


#define	UART1  ((volatile UART_t*)0x40013800)
#define	UART2  ((volatile UART_t*)0x40004400)


/* CONTROL REGISTER 1 */
#define    SBK      	0
#define    RWU      	1
#define    RE       	2
#define    TE       	3
#define    IDLEIE   	4
#define    RXNEIE   	5
#define    TCIE     	6
#define    TXEIE    	7
#define    PEIE     	8
#define    PS       	9
#define    PCE      	10
#define    WAKE     	11
#define    M        	12
#define    UE       	13

/* CONTROL REGISTER 2 */
#define    ADD0     	0
#define    LBDL     	5
#define    LBCL     	8
#define    CPHA     	9
#define    CPOL     	10
#define    CLKEN    	11
#define    STOP     	12
#define    LINEN    	13

/* CONTROL REGISTER 3 */
#define    EIE     		0
#define    IREN    		1
#define    IRLP    		2
#define    HDSEL   		3
#define    NACK    		4
#define    SCEN    		5
#define    DMAR    		6
#define    DMAT    		7
#define    RTSE    		8
#define    CTSE    		9
#define    CTSIE   		10
/**************************************************************/


/*Word Length*/
#define 	DATA_8BIT 		0
#define 	DATA_9BIT 		1


/* Parity Mode */
#define 	EVEN_PARITY		0
#define 	ODD_PARITY		1
#define 	NO_PARITY		2	

/* Configure Rx / Tx enable and disable */
#define 	ENABLE_RX		0
#define 	ENABLE_TX		1
#define 	ENABLE_BOTH		2


#endif
