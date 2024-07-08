/*
 * SPI_interface.h
 *
 * Created: 6/30/2023 6:23:30 PM
 *  Author: Ahmed Emad Hassan
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_voidInit(void);

u8   SPI_u8TransRecieve(u8 Copy_u8TransmitterdByte,u8 *Copy_pu8RecievedByte);

void SPI_voidSendByte(u8 Copy_u8DataByte);

u8   SPI_u8RecByte(u8 *Copy_pu8RecByte);

#endif /* SPI_INTERFACE_H_ */