/*
 * EXTI_program.c
 *
 * Created: 6/17/2023 10:47:58 AM
 *  Author: Ahmed Emad Hassan
 */ 
#include "../../lib/std_types.h"
#include "../../lib/bit_math.h"

#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"

static void (*EXTI_ApfEXTI[3]) (void) = {NULL,NULL,NULL};

/* GICR : (INT1) (INT0) (INT2) _ _ _ IVSEL IVCE */
/* MCUCR : SE SM2 SM1 SM0 (ISC11) (ISC10) (ISC01) (ISC00) */
/* MCUCSR : JTD (ISC2) _ JTRF WDRF BORF EXTRF PORF */
/* GIFR : (INTF1) (INTF0) (INTF2) _ _ _ _ _ */
u8 EXTI_u8Enable(u8 Copy_u8InterruptIndex,u8 Copy_u8InterruptEdge){
	u8 local_u8ErrorState = STD_TYPES_OK;
	switch(Copy_u8InterruptIndex){
		case EXTI_u8_INTERRUPT_0:
			switch(Copy_u8InterruptEdge){
				case EXTI_u8_INTERRUPT_LOW_LEVEL:
					/*enable interrupt 0*/
					SET_BIT(EXTI_u8_GICR_REG,6);
					/*option select bits*/
					CLR_BIT(EXTI_u8_MCUCR_REG,0);
					CLR_BIT(EXTI_u8_MCUCR_REG,1);
					break;
				case EXTI_u8_INTERRUPT_LOGICAL_CHANGE:
					/*enable interrupt 0*/
					SET_BIT(EXTI_u8_GICR_REG,6);
					/*option select bits*/
					SET_BIT(EXTI_u8_MCUCR_REG,0);
					CLR_BIT(EXTI_u8_MCUCR_REG,1);
					break;
				case EXTI_u8_INTERRUPT_FALLING_EDGE:
					/*enable interrupt 0*/
					SET_BIT(EXTI_u8_GICR_REG,6);
					/*option select bits*/
					CLR_BIT(EXTI_u8_MCUCR_REG,0);
					SET_BIT(EXTI_u8_MCUCR_REG,1);
					break;
				case EXTI_u8_INTERRUPT_RISING_EDGE:
					/*enable interrupt 0*/
					SET_BIT(EXTI_u8_GICR_REG,6);
					/*option select bits*/
					SET_BIT(EXTI_u8_MCUCR_REG,0);
					SET_BIT(EXTI_u8_MCUCR_REG,1);
					break;
				default:
					local_u8ErrorState = STD_TYPES_NOK;
			}
			break;
		case EXTI_u8_INTERRUPT_1:
			switch(Copy_u8InterruptEdge){
				case EXTI_u8_INTERRUPT_LOW_LEVEL:
				/*enable interrupt 1*/
				SET_BIT(EXTI_u8_GICR_REG,7);
				/*option select bits*/
				CLR_BIT(EXTI_u8_MCUCR_REG,2);
				CLR_BIT(EXTI_u8_MCUCR_REG,3);
				break;
				case EXTI_u8_INTERRUPT_LOGICAL_CHANGE:
				/*enable interrupt 1*/
				SET_BIT(EXTI_u8_GICR_REG,7);
				/*option select bits*/
				SET_BIT(EXTI_u8_MCUCR_REG,2);
				CLR_BIT(EXTI_u8_MCUCR_REG,3);
				break;
				case EXTI_u8_INTERRUPT_FALLING_EDGE:
				/*enable interrupt 1*/
				SET_BIT(EXTI_u8_GICR_REG,7);
				/*option select bits*/
				CLR_BIT(EXTI_u8_MCUCR_REG,2);
				SET_BIT(EXTI_u8_MCUCR_REG,3);
				break;
				case EXTI_u8_INTERRUPT_RISING_EDGE:
				/*enable interrupt 1*/
				SET_BIT(EXTI_u8_GICR_REG,7);
				/*option select bits*/
				SET_BIT(EXTI_u8_MCUCR_REG,2);
				SET_BIT(EXTI_u8_MCUCR_REG,3);
				break;
				default:
				local_u8ErrorState = STD_TYPES_NOK;
			}
			break;
		case EXTI_u8_INTERRUPT_2:
			switch(Copy_u8InterruptEdge){
				case EXTI_u8_INTERRUPT_FALLING_EDGE:
					/*enable interrupt 2*/
					SET_BIT(EXTI_u8_GICR_REG,5);
					/*option select bits*/
					CLR_BIT(EXTI_u8_MCUCSR_REG,6);
					break;
				case EXTI_u8_INTERRUPT_RISING_EDGE:
					/*enable interrupt 2*/
					SET_BIT(EXTI_u8_GICR_REG,5);
					/*option select bits*/
					SET_BIT(EXTI_u8_MCUCSR_REG,6);
					break;
				default:
					local_u8ErrorState = STD_TYPES_NOK;
			}
			break;
		default:
			local_u8ErrorState = STD_TYPES_NOK;
	}
	return local_u8ErrorState;
}

u8 EXTI_u8Disable(u8 Copy_u8InterruptIndex){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	switch (Copy_u8InterruptIndex)
	{
		case EXTI_u8_INTERRUPT_0:
			CLR_BIT(EXTI_u8_GICR_REG,6);
			break;
		case EXTI_u8_INTERRUPT_1:
			CLR_BIT(EXTI_u8_GICR_REG,7);
			break;
		case EXTI_u8_INTERRUPT_2:
			CLR_BIT(EXTI_u8_GICR_REG,5);
			break;
		default:
			Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
u8 EXTI_u8SetCallBack(u8 Copy_u8Index, void (*Copy_pf)(void)){
	u8 local_u8ErrorState = STD_TYPES_OK;
	if((Copy_u8Index<3)&&(EXTI_ApfEXTI != NULL)){
		EXTI_ApfEXTI[Copy_u8Index] = Copy_pf;
	}else{
		local_u8ErrorState = STD_TYPES_NOK;
	}
	return local_u8ErrorState;
}

void __vector_1 (void){
	if(EXTI_ApfEXTI[0] != NULL){
		EXTI_ApfEXTI[0]();
	}
}

void __vector_2 (void){
	if(EXTI_ApfEXTI[1] != NULL){
		EXTI_ApfEXTI[1]();
		
	}
}

void __vector_3 (void){
	if(EXTI_ApfEXTI[2] != NULL){
		EXTI_ApfEXTI[2]();
	}
}