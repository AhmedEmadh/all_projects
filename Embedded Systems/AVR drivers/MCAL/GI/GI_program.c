/*
 * GI_program.c
 *
 * Created: 6/17/2023 12:49:54 PM
 *  Author: Ahmed Emad Hassan
 */ 
#include "../../lib/std_types.h"
#include "../../lib/bit_math.h"

#include "GI_private.h"
#include "GI_interface.h"
#include "GI_config.h"

void GI_voidEnable(void){
	SET_BIT(GI_SREG_REG,7);
}
void GI_voidDisable(void){
	CLR_BIT(GI_SREG_REG,7);
}