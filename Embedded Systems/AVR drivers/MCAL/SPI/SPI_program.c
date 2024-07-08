/*
 * SPI_program.c
 *
 * Created: 6/30/2023 6:22:07 PM
 *  Author: Ahmed Emad Hassan
 */ 

#include "../../lib/std_types.h"
#include "../../lib/bit_math.h"

#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_interface.h"

/* SPDR: Data Register - 8 bits */
/* SPSR: SPIF WCOL _ _ _ _ _ SPI2X */
/* SPCR: SPIE SPE DORD MSTR CPOL CPHA SPR1 SPR0 */

void SPI_voidInit(void){
	#if (SPI_u8_MODE == SPI_u8_MASTER_MODE)
		/* select Master Mode */
		SET_BIT(SPI_u8_SPCR_REG,4);
		/* clk choose polarity and phase => falling, rising / setup,sample */
		SET_BIT(SPI_u8_SPCR_REG,2);
		SET_BIT(SPI_u8_SPCR_REG,3);
		
	#elif (SPI_u8_MODE == SPI_u8_SLAVE_MODE)
		/* select Slave Mode */
		CLR_BIT(SPI_u8_SPCR_REG,4);
	#endif
	
	/* the following done in master and slave */
	/* Data Order = MSB First */
	CLR_BIT(SPI_u8_SPCR_REG,5);
	
	
	/* select clk => Fosc/64 */
	SET_BIT(SPI_u8_SPCR_REG,1);
	CLR_BIT(SPI_u8_SPCR_REG,0);
	/* Enable SPI */
	SET_BIT(SPI_u8_SPCR_REG,6);
	
}
u8 SPI_u8TransRecieve(u8 Copy_u8TransmitterdByte,u8 *Copy_pu8RecievedByte){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pu8RecievedByte != NULL){
		/* send byte */
		SPI_u8_SPDR_REG = Copy_u8TransmitterdByte;
		/* check if the transmission is completed */
		/* wait for transmission to complete */
		while(READ_BIT(SPI_u8_SPSR_REG,7) == 0);
		/* Read Byte */
		*Copy_pu8RecievedByte = SPI_u8_SPDR_REG;
	} else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

void SPI_voidSlaveSendByte(u8 Copy_u8DataByte){
	SPI_u8_SPDR_REG = Copy_u8DataByte;
	/* wait for transmission to complete */
	//while(READ_BIT(SPI_u8_SPSR_REG,7) == 0);
}

u8   SPI_u8RecByte(u8 *Copy_pu8RecByte){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pu8RecByte != NULL){
		/* check if the transmission is complete */
		while(READ_BIT(SPI_u8_SPSR_REG,7));
		/* Read Byte */
		*Copy_pu8RecByte = SPI_u8_SPDR_REG;
			
	}else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
