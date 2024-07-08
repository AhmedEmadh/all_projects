/****************************************************************/
/******************* Name: Ahmed Emad Hassan ********************/
/******************* Date: 19/3/2024         ********************/
/******************* SWC: TWI                ********************/
/******************* Version: 1.0v           ********************/
/****************************************************************/

/* include LIB */
#include "STD_Types.h"
#include "BIT_MATH.h"
/* include TWI */
#include "TWI_private.h"
#include "TWI_interface.h"
#include "TWI_config.h"
/* Implement functions */
void TWI_voidMasterInit(void)
{
	/* Set Prescaler Value */
	TWI_u8_TWSR_REG |= TWL_u8_TWPS_VALUE;
	/* Set TWBR with the Value => 200KHZ */
	TWI_u8_TWBR_REG = TWBR_u8_Value;
	/* Enable ACK */
	if(TWL_u8_ACKNOWLEDGEMENT == TWL_u8_ACKNOWLEDGEMENT_ENABLE){
		SET_BIT(TWI_u8_TWCR_REG,TWEA);
	}else{
		CLR_BIT(TWI_u8_TWCR_REG,TWEA);
	}
	/* Enable I2C */
	SET_BIT(TWI_u8_TWCR_REG,TWEN);
}
u8 TWI_u8SlaveInit(u8 Copy_u8Address)
{
	u8 Local_ErrorState = STD_TYPES_OK; 
	/* Set Slave Address in TWAR*/
	TWI_u8_TWAR_REG = Copy_u8Address<<1;
	/* Enable Prodcast */
	if(TWL_u8_PODCAST == TWL_u8_PODCAST_ENABLE){
		SET_BIT(TWI_u8_TWAR_REG,TWGCE);
	}else{
		CLR_BIT(TWI_u8_TWAR_REG,TWGCE);
	}
	/* Enable ACK */
	if(TWL_u8_ACKNOWLEDGEMENT == TWL_u8_ACKNOWLEDGEMENT_ENABLE){
		SET_BIT(TWI_u8_TWCR_REG,TWEA);
	}else{
		CLR_BIT(TWI_u8_TWCR_REG,TWEA);
	}
	/* Enable I2C */
	SET_BIT(TWI_u8_TWCR_REG,TWEN);
	return Local_ErrorState;
}
u8 TWI_u8SendStartCondition(void)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	/* Clear Flag + Start Condition */
	SET_BIT(TWI_u8_TWCR_REG,TWSTA);
	SET_BIT(TWI_u8_TWCR_REG,TWINT);
	/* wait for the flag to be 1 */
	while(!READ_BIT(TWI_u8_TWCR_REG,TWINT));
	/* Check the status code */
	if((TWI_u8_TWSR_REG & 0xF8)== TWI_u8_STATUS_START_TRANSMITTED){
		// stay Ok
	}else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	/* Clear Start Condition Bit */
	CLR_BIT(TWI_u8_TWCR_REG,TWSTA);
	return Local_u8ErrorState;
}
u8 TWI_u8SendRepeatedStartCondition(void)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	/* Clear Flag + Start Condition */
	SET_BIT(TWI_u8_TWCR_REG,TWSTA);
	SET_BIT(TWI_u8_TWCR_REG,TWINT);
	/* wait for the flag to be 1 */
		while(!READ_BIT(TWI_u8_TWCR_REG,TWINT));
	/* Check the status code = Repeated Start Condition */
	if((TWI_u8_TWSR_REG & 0xF8)== TWI_u8_STATUS_REPEATED_START_TRANSMITTED){
		//stay Ok
	}else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	/* Clear Start Condition Bit */
	CLR_BIT(TWI_u8_TWCR_REG,TWSTA);
	return Local_u8ErrorState;
}
u8 TWI_u8SendStopCondition(void)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	/* Clear Flag + Stop Condition */
	SET_BIT(TWI_u8_TWCR_REG,TWSTO);
	SET_BIT(TWI_u8_TWCR_REG,TWINT);
	return Local_u8ErrorState;
}
u8 TWI_u8SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	/* Write Slave Address + 0 in TWDR */
	TWI_u8_TWDR_REG = Copy_u8SlaveAddress<<1;
	CLR_BIT(TWI_u8_TWDR_REG,TWD0);
	/* Clear Flag */
	SET_BIT(TWI_u8_TWCR_REG,TWINT);
	/* wait for the flag to be 1 */
	while(!READ_BIT(TWI_u8_TWCR_REG,TWINT));
	/* Check The Status code  = SLA+W */
	if((TWI_u8_TWSR_REG & 0xF8)== TWI_u8_STATUS_SLAVE_ADDRESS_TRANSMITTED_ACK_RECIEVED){
		//stay Ok
	}else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
}
u8 TWI_u8SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	/* Write Slave Address + 1 in TWDR */
	TWI_u8_TWDR_REG = Copy_u8SlaveAddress<<1;
	SET_BIT(TWI_u8_TWDR_REG,TWD0);
	/* Clear Flag */
	SET_BIT(TWI_u8_TWCR_REG,TWINT);
	
	/* Wait for the Flag to be 1 */
		while(!READ_BIT(TWI_u8_TWCR_REG,TWINT));
	/* Check The Status code  = SLA+R */
	if((TWI_u8_TWSR_REG & 0xF8)== TWI_u8_STATUS_SLAVE_ADDRESS_TRANSMITTED_ACK_RECIEVED){
		//stay Ok
	}else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
u8 TWI_u8SendDataByte(u8 Copy_u8DataByte)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	/* Write Data in TWDR */
	TWI_u8_TWDR_REG = Copy_u8DataByte;
	/* Clear Flag */
	SET_BIT(TWI_u8_TWCR_REG,TWINT);
	/* Wait for the Flag to be 1 */
	while(!READ_BIT(TWI_u8_TWCR_REG,TWINT));
	/* Check The Status code  = MASTERSendData */
		if((TWI_u8_TWSR_REG & 0xF8)== TWI_u8_STATUS_DATA_TRANSMITTED_ACK_RECIEVED){
			//stay Ok
			}else{
			Local_u8ErrorState = STD_TYPES_NOK;
		}
}
u8 TWI_u8ReadDataByte(u8 * Copy_pu8ReturnedDataByte)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	/* Check Pointer */
	if(Copy_pu8ReturnedDataByte != NULL){
		/* Clear Flag */
		SET_BIT(TWI_u8_TWCR_REG,TWINT);
		/* Wait for the Flag to be 1 */
			while(!READ_BIT(TWI_u8_TWCR_REG,TWINT));
		/* Check The Status code  = MasterRecievedData */
		if((TWI_u8_TWSR_REG & 0xF8)== 0x50){
			//stay Ok
			/* Read Data in the Pointer */
			*Copy_pu8ReturnedDataByte = TWI_u8_TWDR_REG;
			}else{
			Local_u8ErrorState = STD_TYPES_NOK;
		}


	}


}
