/****************************************************************/
/******************* Name: Ahmed Emad Hassan ********************/
/******************* Date: 19/3/2024         ********************/
/******************* SWC: TWI                ********************/
/******************* Version: 1.0v           ********************/
/****************************************************************/
#ifndef TWI_CONFIG_H_
#define TWI_CONFIG_H_

/* Configurations */

// Equation : SCL_freq = CPU_CLK / (16 + 2 * (TWBR) * 4^(TWPS))
#define TWBR_u8_Value		0	
#define TWL_u8_TWPS_VALUE	0


#define TWL_u8_PODCAST			TWL_u8_PODCAST_ENABLE			

#define TWL_u8_ACKNOWLEDGEMENT	TWL_u8_ACKNOWLEDGEMENT_ENABLE

#endif