/*
 * RTO_program.c
 *
 * Created: 7/6/2023 2:19:38 PM
 *  Author: Ahmed Emad Hassan
 */ 

/* LIB */

#include "../../lib/std_types.h"
#include "../../lib/bit_math.h"

/* MCAL */
#include "../../MCAL/TIMERS/TIMERS_interface.h"

/* RTO */
#include "RTO_private.h"
#include "RTO_config.h"
#include "RTO_interface.h"

/* Array of TCBs */
RTO_TCB RTO_AstrTasks[RTO_u8_MAX_NUMBER_OF_TASKS];

void RTO_voidInit(void){
	
	/* TIMER0 CTC MODE */
	/* start timer */
	TIMERS_voidTimer0Init();
	TIMERS_u8Timer0SetCallBack(&RTO_voidScheduler);
}

u8 RTO_u8CreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicty, u16 Copy_u16FirstDelay, void (*Copy_pf)(void)){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((Copy_u8Priority<RTO_u8_MAX_NUMBER_OF_TASKS)&&(Copy_pf != NULL)){
		RTO_AstrTasks[Copy_u8Priority].FirstDelay = Copy_u16FirstDelay;
		RTO_AstrTasks[Copy_u8Priority].periodicity = Copy_u16Periodicty;
		RTO_AstrTasks[Copy_u8Priority].pf = Copy_pf;
	}else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

static void RTO_voidScheduler(void){
	u8 Local_u8Counter;
	/* For loop to loop on the ready Tasks */
	for(Local_u8Counter = 0;Local_u8Counter< RTO_u8_MAX_NUMBER_OF_TASKS; Local_u8Counter++){
		if(RTO_AstrTasks[Local_u8Counter].FirstDelay == 0){
			/* Call Task */
			RTO_AstrTasks[Local_u8Counter].pf();
			/* update for the first delay value using periodicity */
			RTO_AstrTasks[Local_u8Counter].FirstDelay = RTO_AstrTasks[Local_u8Counter].periodicity - 1;
		}else{
			RTO_AstrTasks[Local_u8Counter].FirstDelay--;
		}
	}
}
