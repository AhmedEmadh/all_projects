/*
 * WDT_program.c
 *
 * Created: 6/23/2023 8:34:24 PM
 *  Author: Ahmed Emad Hassan
 */ 
#include "../../lib/std_types.h"
#include "../../lib/bit_math.h"

#include "WDT_private.h"
#include "WDT_interface.h"

#define WDT_voidEnable(void){
	/* Enable WDT for 2.1 sec */
	WDT_WDTCR_REG = 0b00001111;
	
}
#define WDT_voidDisable(void){
	WDT_WDTCR_REG = (1<<4)|(1<<3);
	
	WDT_WDTCR_REG = 0x00;
}