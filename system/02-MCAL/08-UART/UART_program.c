#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"


void UART_voidInit(u8 cpy_u8CH)
{
	
	switch(cpy_u8CH)
	{
		case UART_1 :
			/* Configure word length */
			#if 	UART1_WORD_LENGTH	==	DATA_8BIT
				CLR_BIT((UART1-> CR1), M);
			#elif 	UART1_WORD_LENGTH	==	DATA_9BIT
				SET_BIT((UART1-> CR1), M);
			#endif	
			
			/* Configure parity mode */
			#if		UART1_PARITY_MODE	==	EVEN_PARITY
				/* Enable parity control */
				SET_BIT((UART1-> CR1),PCE);
				
				/* Choose even parity */
				CLR_BIT((UART1-> CR1),PS);
			#elif	UART1_PARITY_MODE	==	ODD_PARITY
				/* Enable parity control */
				SET_BIT((UART1-> CR1),PCE);
				
				/* Choose odd parity */
				SET_BIT(UART1-> CR1),PS);
			#elif	UART1_PARITY_MODE	==	NO_PARITY
				/* Disable parity control */
				CLR_BIT((UART1-> CR1),PCE);
			#endif		
				
			/* Configure Rx / Tx enable and disable */
			#if		UART1_RX_TX_ENABLE	==	ENABLE_RX
				SET_BIT((UART1-> CR1),RE);
			#elif	UART1_RX_TX_ENABLE	==	ENABLE_TX
				SET_BIT((UART1-> CR1),TE);
			#elif	UART1_RX_TX_ENABLE	==	ENABLE_BOTH
				SET_BIT((UART1-> CR1),RE);
				SET_BIT((UART1-> CR1),TE);
			#endif	
		
			/*Configure buad rate (9600) */
			UART1 -> BRR = 0x341;
			
			/*Enable UASRT*/
			SET_BIT((UART1-> CR1), UE);
			
			/* Intialize status rigeter */
			UART1 -> SR = 0;
			break;
			
		case UART_2 :
			/*Configure Word Length*/
			#if 	UART2_WORD_LENGTH	==	DATA_8BIT
				CLR_BIT((UART2-> CR1), M);
			#elif 	UART2_WORD_LENGTH	==	DATA_9BIT
				SET_BIT((UART2-> CR1), M);
			#endif	
			
			/* Configure parity mode */
			#if		UART2_PARITY_MODE	==	EVEN_PARITY
				SET_BIT((UART2-> CR1),PCE);  //enable parity control
				CLR_BIT((UART2-> CR1),PS);  //choose even parity
			#elif	UART2_PARITY_MODE	==	ODD_PARITY
				SET_BIT((UART2-> CR1),PCE);  //enable parity control
				SET_BIT(UART2-> CR1),PS);  	//choose odd parity	
			#elif	UART2_PARITY_MODE	==	NO_PARITY
				CLR_BIT((UART2-> CR1),PCE);  //disable parity control
			#endif		
				
			/* Configure Rx / Tx enable and disable */
			#if		UART2_RX_TX_ENABLE	==	ENABLE_RX
				SET_BIT((UART2-> CR1),RE);
			#elif	UART2_RX_TX_ENABLE	==	ENABLE_TX
				SET_BIT((UART2-> CR1),TE);
			#elif	UART2_RX_TX_ENABLE	==	ENABLE_BOTH
				SET_BIT((UART2-> CR1),RE);
				SET_BIT((UART2-> CR1),TE);
			#endif	
		
			/*Configure buad rate (115200) */
			UART2 -> BRR = 0x45;
			
			/*Enable UASRT*/
			SET_BIT((UART2-> CR1), UE);
			
			/* Intialize status rigeter */
			UART2 -> SR = 0;
			break;
			
		default:
			break;
	}	
}

void UART_voidTransimit(u8 cpy_u8CH , u8* arr)
{
	u8 i=0;
	switch(cpy_u8CH)
	{
		case UART_1 :
			while(arr[i] != '\0')
			{
				UART1->DR = arr[i];
				
				/* Wait until transimit Data */
				while((GET_BIT(UART1 -> SR , 6)) == 0);
				i++;
			}
			break;
		
		case UART_2 :
			while(arr[i] != '\0')
			{
				UART2->DR = arr[i];
				
				/* Wait until transimit Data */
				while((GET_BIT(UART2 -> SR , 6)) == 0);
				i++;
			}
			break;	

		default:
			break;
	}
	
}

u8 UART_u8Receive(u8 cpy_u8CH)
{
	u8 Loc_u8ReceivedData[2] ;
	
	switch(cpy_u8CH)
	{
		case UART_1 :
			while((GET_BIT((UART1 -> SR), 5)) == 0);
			MGPIO_voidSetPinValue(GPIOA,PIN5,GPIO_HIGH);
			Loc_u8ReceivedData[UART_1] = UART1 -> DR;
			break;
			
		case UART_2 :
			while((GET_BIT((UART2 -> SR), 5)) == 0);
			Loc_u8ReceivedData[UART_2] = UART2 -> DR;
			break;
		
		default:
			break;
	}
	
	return (Loc_u8ReceivedData[cpy_u8CH]);
}
