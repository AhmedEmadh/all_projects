/****************************************************************/
/******************* Name: Ahmed Emad Hassan ********************/
/******************* Date: 19/3/2024         ********************/
/******************* SWC: TWI                ********************/
/******************* Version: 1.0v           ********************/
/****************************************************************/

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

void TWI_voidMasterInit(void);
u8 TWI_u8SlaveInit(u8 Copy_u8Address);
u8 TWI_u8SendStartCondition(void);
u8 TWI_u8SendRepeatedStartCondition(void);
u8 TWI_u8SendStopCondition(void);
u8 TWI_u8SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);
u8 TWI_u8SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);
u8 TWI_u8SendDataByte(u8 Copy_u8DataByte);
u8 TWI_u8ReadDataByte(u8 * Copy_pu8ReturnedDataByte);

#endif