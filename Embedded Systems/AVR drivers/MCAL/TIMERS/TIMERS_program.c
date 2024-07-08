/*
 * TIMERS_program.c
 *
 * Created: 6/20/2023 11:17:07 PM
 *  Author: Ahmed Emad Hassan
 */ 
#include "../../lib/std_types.h"
#include "../../lib/bit_math.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"
#include "TIMERS_interface.h"

/*Global Pointer to Function of Timer0 OVF*/
static void (*TIMERS_pfTimer0OVF)(void) = NULL;
void TIMERS_voidTimer0Init(void){
	/* select mode => Normal Mode*/
	switch (TIMER0_u8_MODE){
		case TIMERS_u8_NORMAL_MODE :
			CLR_BIT(TIMERS_u8_TCCR0_REG,6); /* WGM00 */
			CLR_BIT(TIMERS_u8_TCCR0_REG,3);	/* WGM01 */
			break;
		case TIMERS_u8_PWM_PHASE_CORRECT_MODE:
			SET_BIT(TIMERS_u8_TCCR0_REG,6); /* WGM00 */
			CLR_BIT(TIMERS_u8_TCCR0_REG,3);	/* WGM01 */
			break;
		case TIMERS_u8_CTC_MODE:
			CLR_BIT(TIMERS_u8_TCCR0_REG,6); /* WGM00 */
			SET_BIT(TIMERS_u8_TCCR0_REG,3);	/* WGM01 */
			break;
		case TIMERS_u8_FAST_PWM_MODE:
			SET_BIT(TIMERS_u8_TCCR0_REG,6); /* WGM00 */
			SET_BIT(TIMERS_u8_TCCR0_REG,3);	/* WGM01 */
			break;
	}
	
	/*enable OVF Interrupt*/
	switch(TIMER0_u8_OVF_INTTURUPT){
		case TIMERS_u8_OVF_INTTURUPT_ENABLE:
			SET_BIT(TIMERS_u8_TIMSK_REG,0);
			break;
		case TIMERS_u8_OVF_INTTURUPT_DISABLE:
			CLR_BIT(TIMERS_u8_TIMSK_REG,0);
			break;
	}
	/*select options in mode*/
	switch(TIMER0_u8_MODE_OPTION){
		case 0:
			CLR_BIT(TIMERS_u8_TCCR0_REG,4);
			CLR_BIT(TIMERS_u8_TCCR0_REG,5);
			break;
		case 1:
			SET_BIT(TIMERS_u8_TCCR0_REG,4);
			CLR_BIT(TIMERS_u8_TCCR0_REG,5);
			break;
		case 2:
			CLR_BIT(TIMERS_u8_TCCR0_REG,4);
			SET_BIT(TIMERS_u8_TCCR0_REG,5);
			break;
		case 3:
			SET_BIT(TIMERS_u8_TCCR0_REG,4);
			SET_BIT(TIMERS_u8_TCCR0_REG,5);
			break;
	}
	
	/* toggle led every 1 sec */
	/* preload value = 192 and 3906.25 Overflows*/
	/*set preload value*/
	TIMERS_u8_TCNT0_REG = TIMER0_u8_PRELOAD_VALUE;
	/* Set Prescaler Value CLK/n */
	switch(TIMER0_u8_CLK_PRESCALER){
		case TIMER0_u8_CLK_PRESCALER_NO_CLK:
			CLR_BIT(TIMERS_u8_TCCR0_REG,0);
			CLR_BIT(TIMERS_u8_TCCR0_REG,1);
			CLR_BIT(TIMERS_u8_TCCR0_REG,2);

			break;
		case TIMER0_u8_CLK_PRESCALER_CLK_DIV_1:
			SET_BIT(TIMERS_u8_TCCR0_REG,0);
			CLR_BIT(TIMERS_u8_TCCR0_REG,1);
			CLR_BIT(TIMERS_u8_TCCR0_REG,2);

		break;
		case TIMER0_u8_CLK_PRESCALER_CLK_DIV_8:
			CLR_BIT(TIMERS_u8_TCCR0_REG,0);
			SET_BIT(TIMERS_u8_TCCR0_REG,1);
			CLR_BIT(TIMERS_u8_TCCR0_REG,2);

		break;
		case TIMER0_u8_CLK_PRESCALER_CLK_DIV_64:
			SET_BIT(TIMERS_u8_TCCR0_REG,0);
			SET_BIT(TIMERS_u8_TCCR0_REG,1);
			CLR_BIT(TIMERS_u8_TCCR0_REG,2);

		break;
		case TIMER0_u8_CLK_PRESCALER_CLK_DIV_256:
			CLR_BIT(TIMERS_u8_TCCR0_REG,0);
			CLR_BIT(TIMERS_u8_TCCR0_REG,1);
			SET_BIT(TIMERS_u8_TCCR0_REG,2);

		break;
		case TIMER0_u8_CLK_PRESCALER_CLK_DIV_1024:
			SET_BIT(TIMERS_u8_TCCR0_REG,0);
			CLR_BIT(TIMERS_u8_TCCR0_REG,1);
			SET_BIT(TIMERS_u8_TCCR0_REG,2);
		break;
		case TIMER0_u8_CLK_PRESCALER_CLK_EXTERNAL_T0_ON_FALLING_EDGE:
			CLR_BIT(TIMERS_u8_TCCR0_REG,0);
			SET_BIT(TIMERS_u8_TCCR0_REG,1);
			SET_BIT(TIMERS_u8_TCCR0_REG,2);
		break;
		case TIMER0_u8_CLK_PRESCALER_CLK_EXTERNAL_T0_ON_RISING_EDGE:
			SET_BIT(TIMERS_u8_TCCR0_REG,0);
			SET_BIT(TIMERS_u8_TCCR0_REG,1);
			SET_BIT(TIMERS_u8_TCCR0_REG,2);
		break;
	}
	
		/* prescaler the last step */
	
}
void TIMERS_voidTimer1Init(void){
	/* select timer1 mode => mode 14*/
	CLR_BIT(TIMERS_u8_TCCR1A_REG,0);
	SET_BIT(TIMERS_u8_TCCR1A_REG,1);
	SET_BIT(TIMERS_u8_TCCR1B_REG,3);
	SET_BIT(TIMERS_u8_TCCR1B_REG,4);
	
	/* select clear on compare match and set on top (Non inverting mode) */
	CLR_BIT(TIMERS_u8_TCCR1A_REG,6);
	SET_BIT(TIMERS_u8_TCCR1A_REG,7);
	
	/* set top value in ICR1 (setting value) */
	TIMERS_u16_ICR1_REG = 19999;
	
	/* set angle of servo motor => 1000 uS => angle 0 deg (clearing value)*/
	TIMERS_u16_OCR1A_REG = 1499;
	
	/* set prescaler */
	SET_BIT(TIMERS_u8_TCCR1B_REG,0);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,1);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,2);
}
void set_angle(u8 Copy_u8Angle){
	TIMERS_u16_OCR1A_REG = (u16)(((Copy_u8Angle/180.0)*2000) + 499);
	
}


u8 TIMERS_u8Timer0SetCallBack(void(*Copy_pf)(void)){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pf != NULL){
		TIMERS_pfTimer0OVF = Copy_pf;
	}else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

void TIMERS_voidTimer0SetCompareMatchValue(u8 Copy_u8OCR0Value){
	TIMERS_u8_OCR0_REG = Copy_u8OCR0Value;
}


void TIMERS_voidTimer1SetCompareMatchValueA(u16 Copy_u16OCRValue){
	TIMERS_u16_OCR1A_REG = Copy_u16OCRValue;
}



void __vector_11 (void) __attribute__((signal));
void __vector_11 (void){
	static u16 Local_u16CounterOVF = 0;
	Local_u16CounterOVF++;
	if(Local_u16CounterOVF == TIMER0_u8_NUMBER_OF_OVERFLOWS){
		/*update preload value*/
		TIMERS_u8_TCNT0_REG = TIMER0_u8_PRELOAD_VALUE;
		/* clear the OVF counter */
		Local_u16CounterOVF = 0;
		/*call App function*/
		if(TIMERS_pfTimer0OVF != NULL){
			TIMERS_pfTimer0OVF();
		}
		
	}
}