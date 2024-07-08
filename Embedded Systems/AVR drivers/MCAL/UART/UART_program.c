/*
 * UART_program.c
 *
 * Created: 6/25/2023 3:32:36 AM
 *  Author: Ahmed Emad Hassan
 */ 

#include "../../lib/std_types.h"
#include "../../lib/bit_math.h"

#include "UART_private.h"
#include "UART_interface.h"
#include "UART_config.h"


void UART_voidInit(void){
	
	u8 Local_u16BaudRate = 51;
	u8 local_u8UCSRCValue = 0b10000000;
	/* Normal Speed */
	CLR_BIT(UART_u8_UCSRA_REG,1);
	/* Disable PWM */
	CLR_BIT(UART_u8_UCSRA_REG,0);
	/* Enable Rx, Tx */
	SET_BIT(UART_u8_UCSRB_REG,3);
	SET_BIT(UART_u8_UCSRB_REG,4);
	/* Select 8 bit data */
	CLR_BIT(UART_u8_UCSRB_REG,2);
	SET_BIT(local_u8UCSRCValue,2);
	SET_BIT(local_u8UCSRCValue,1);
	/* Select Asynch mode */
	CLR_BIT(local_u8UCSRCValue,6);
	/* No Parity bit */
	CLR_BIT(local_u8UCSRCValue,5);
	CLR_BIT(local_u8UCSRCValue,4);
	/* Enable 2 stop bits */
	SET_BIT(local_u8UCSRCValue,3);
	/* Update UCSRC reg */
	UART_u8_UCSRC_REG = local_u8UCSRCValue;
	/* baud rate = 9600 */
	UART_u8_UBRRL_REG = (u8)Local_u16BaudRate;
	UART_u8_UBRRH_REG = (u8)(Local_u16BaudRate >> 8);
}

void UART_voidSendByte(u8 Copy_u8DataByte){
	/* wait util the transmit register is empty */
	while(READ_BIT(UART_u8_UCSRA_REG,5) == 0);
	/*  send data byte */
	UART_u8_UDR_REG = Copy_u8DataByte;
}

u8 UART_u8RecieveByte(u8 * Copy_pu8RecByte){
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if(Copy_pu8RecByte != NULL){
		/* wait until the data is recieved */
		while(READ_BIT(UART_u8_UCSRA_REG,7) == 0);
		/* Read Data */
		*Copy_pu8RecByte = UART_u8_UDR_REG;
		
		Local_u8ErrorState = STD_TYPES_OK;
	}
	return Local_u8ErrorState;
}

u8 UART_u8SendStringSynch (u8 *Copy_pu8String){
	u8 counter=0;
	while(Copy_pu8String[counter] != '/0'){
		UART_u8_UDR_REG = Copy_pu8String[counter];
		/* check that the Tx is completed + Timeout */
		counter++;
	}
	return STD_TYPES_NOK;
}

u8 UART_u8RecieveStringSynch( u8 *Copy_pu8Recieve, u8 Copy_u8MessageSize){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 counter = 0;
	if(Copy_pu8Recieve != NULL){
		while(counter < Copy_u8MessageSize)	{
			Copy_pu8Recieve[counter] = UART_u8_UDR_REG;
			counter++;
		}	
	}else{
		u8 Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 UART_u8RecieveStringAsync(u8 *Copy_pu8String, void (* notificationfun)(void),u8 Copy_u8MessageSize){
	/* Enable Interrupt */
	/* tx is empty */
	/* set global pointer to function with the notification function */
	/* global pointer to u8 to hold the address of the recieved func */
	/* update global variable with the message size */
	/* check if the flag = 1 */
	/* enable Rx Interrupt */
	
	return STD_TYPES_NOK;
}
#if 0
void ISR(RXCOMPLETE){
	if(counter < global_variable){
		globalPointer[counter] = UDR;
		counter++;
	}
	else{
		/*  */
	}
}
#endif