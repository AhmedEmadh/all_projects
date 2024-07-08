/*
 * UART_private.h
 *
 * Created: 6/25/2023 3:33:12 AM
 *  Author: Ahmed Emad Hassan
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_
 
#define UART_u8_UBRRH_REG		*((volatile u8*)0X40)
#define UART_u8_UCSRC_REG		*((volatile u8*)0X40)

#define UART_u8_UDR_REG			*((volatile u8*)0X2C)
#define UART_u8_UCSRA_REG		*((volatile u8*)0X2B)
#define UART_u8_UCSRB_REG		*((volatile u8*)0X2A)

#define UART_u8_UBRRL_REG		*((volatile u8*)0X29)
#endif /* UART_PRIVATE_H_ */