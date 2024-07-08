/*
 * SPI_private.h
 *
 * Created: 6/30/2023 6:22:28 PM
 *  Author: Ahmed Emad Hassan
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

/* SPDR: Data Resgister - 8 bits */
#define SPI_u8_SPDR_REG		*((volatile u8*)0x2F)
/* SPSR: SPIF WCOL _ _ _ _ _ SPI2X */
#define SPI_u8_SPSR_REG		*((volatile u8*)0x2E)
/* SPCR: SPIE SPE DORD MSTR CPOL CPHA SPR1 SPR0 */
#define SPI_u8_SPCR_REG		*((volatile u8*)0x2D)



/* CONFIG OPTIONS */

#define  SPI_u8_MASTER_MODE				1
#define  SPI_u8_SLAVE_MODE				2



#endif /* SPI_PRIVATE_H_ */