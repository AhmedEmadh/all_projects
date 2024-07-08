/*
 * UART_interface.h
 *
 * Created: 6/25/2023 3:32:54 AM
 *  Author: Ahmed Emad Hassan
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_voidInit(void);

u8 UART_u8SendStringSynch (u8 *Copy_pu8String);

void UART_voidSendByte(u8 Copy_u8DataByte);

u8 UART_u8RecieveByte(u8 * Copy_pu8RecByte);

#endif /* UART_INTERFACE_H_ */