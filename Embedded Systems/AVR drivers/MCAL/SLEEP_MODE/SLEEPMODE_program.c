/*
 * SLEEPMODE_program.c
 *
 * Created: 6/15/2023 5:08:58 PM
 *  Author: Ahmed Emad Hassan
 */ 
#include "../../lib/std_types.h"
#include "../../lib/bit_math.h"
#include "SLEEP_MODE_private.h"
#include "SLEEP_MODE_config.h"
#include "SLEEP_MODE_interface.h"
/**/


void SLEEP_MODE_voidEnable(void){
	SET_BIT(SLEEP_MODE_MCUCR_REG,7);
}
void SLEEP_MODE_voidDisable(void){
	CLR_BIT(SLEEP_MODE_MCUCR_REG,7);
}



u8 SLEEP_MODE_u8SetMode(u8 copy_u8Mode){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	switch (Local_u8ErrorState)
	{
		case SLEEP_MODE_u8_IDLE_MODE:
			CLR_BIT(SLEEP_MODE_MCUCR_REG,2);
			CLR_BIT(SLEEP_MODE_MCUCR_REG,1);
			CLR_BIT(SLEEP_MODE_MCUCR_REG,0);
			break;
		case SLEEP_MODE_u8_ADC_NOISE_REDUCTION_MODE: 
			CLR_BIT(SLEEP_MODE_MCUCR_REG,2);
			CLR_BIT(SLEEP_MODE_MCUCR_REG,1);
			SET_BIT(SLEEP_MODE_MCUCR_REG,0);
			break;
		case SLEEP_MODE_u8_POWER_DOWN_MODE:
			CLR_BIT(SLEEP_MODE_MCUCR_REG,2);
			SET_BIT(SLEEP_MODE_MCUCR_REG,1);
			CLR_BIT(SLEEP_MODE_MCUCR_REG,0);
			break;
		case SLEEP_MODE_u8_POWER_SAVE_MODE:
			CLR_BIT(SLEEP_MODE_MCUCR_REG,2);
			SET_BIT(SLEEP_MODE_MCUCR_REG,1);
			SET_BIT(SLEEP_MODE_MCUCR_REG,0);
			break;
		case SLEEP_MODE_u8_STANDBY_MODE:
			SET_BIT(SLEEP_MODE_MCUCR_REG,2);
			SET_BIT(SLEEP_MODE_MCUCR_REG,1);
			CLR_BIT(SLEEP_MODE_MCUCR_REG,0);
			break;
		case SLEEP_MODE_u8_EXTENDED_STANDBY_MODE:
			SET_BIT(SLEEP_MODE_MCUCR_REG,2);
			SET_BIT(SLEEP_MODE_MCUCR_REG,1);
			SET_BIT(SLEEP_MODE_MCUCR_REG,0);
			break;
		default:
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
