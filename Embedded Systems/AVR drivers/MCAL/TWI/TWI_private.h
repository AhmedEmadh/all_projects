/****************************************************************/
/******************* Name: Ahmed Emad Hassan ********************/
/******************* Date: 19/3/2024         ********************/
/******************* SWC: TWI                ********************/
/******************* Version: 1.0v           ********************/
/****************************************************************/

#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

/* Defining Registers */
#define TWI_u8_TWBR_REG		*((volatile u8*)0x20)
#define TWI_u8_TWSR_REG		*((volatile u8*)0x21)
#define TWI_u8_TWAR_REG		*((volatile u8*)0x22)
#define TWI_u8_TWDR_REG		*((volatile u8*)0x23)
#define TWI_u8_TWCR_REG		*((volatile u8*)0x56)

/* TWI_u8_TWBR_REG */
#define TWBR0	0
#define TWBR1	1
#define TWBR2	2
#define TWBR3	3
#define TWBR4	4
#define TWBR5	5
#define TWBR6	6
#define TWBR7	7
/* TWI_u8_TWSR_REG */
#define TWPS0	0
#define TWPS1	1
//Reserved
#define TWS3	3
#define TWS4	4
#define TWS5	5
#define TWS6	6
#define TWS7	7
/* TWI_u8_TWAR_REG */
#define TWGCE	0
#define TWA0	1
#define TWA1	2
#define TWA2	3
#define TWA3	4
#define TWA4	5
#define TWA5	6
#define TWA6	7
/* TWI_u8_TWDR_REG */
#define TWD0	0
#define TWD1	1
#define TWD2	2
#define TWD3	3
#define TWD4	4
#define TWD5	5
#define TWD6	6
#define TWD7	7
/* TWI_u8_TWCR_REG */
#define TWIE	0
//Reserved
#define TWEN	2
#define TWWC	3
#define TWSTO	4
#define TWSTA	5
#define TWEA	6
#define TWINT	7

/* Status Code */
#define TWI_u8_STATUS_START_TRANSMITTED									0x08
#define TWI_u8_STATUS_REPEATED_START_TRANSMITTED						0x10
#define TWI_u8_STATUS_SLAVE_ADDRESS_TRANSMITTED_ACK_RECIEVED			0x18
#define TWI_u8_STATUS_SLAVE_ADDRESS_TRANSMITTED_NO_ACK_RECIEVED			0x20
#define TWI_u8_STATUS_DATA_TRANSMITTED_ACK_RECIEVED						0x28
#define TWI_u8_STATUS_DATA_TRANSMITTED_NO_ACK_RECIEVED					0x28
#define TWI_u8_STATUS_ARBITRATION_LOST									0x28
/* Arbitration lost in slave address or data bytes*/

#define TWL_u8_ACKNOWLEDGEMENT_ENABLE		1
#define TWL_u8_ACKNOWLEDGEMENT_DISABLE		0

#define TWL_u8_PODCAST_ENABLE			1
#define TWL_u8_PODCAST_DISABLE			0

#endif