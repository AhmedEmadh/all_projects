/*
 * ADC_program.c
 *
 * Created: 6/19/2023 4:01:28 PM
 *  Author: Ahmed Emad Hassan
 */ 
#include "../../lib/std_types.h"
#include "../../lib/bit_math.h"

#include "ADC_private.h"
#include "ADC_interface.h"
#include "ADC_config.h"
/*ADC busy flag*/
static u8 ADC_u8_busy_flag = 0;

static void (*ADC_pfNotification)(u16) = NULL;

void ADC_voidInit(void){
	/*	1- select Vref = AVCC
	**	2- select right adjust
	**	3- Disable auto trigger
	**	4- select clock 50KHz -> 200 KHz
	**	5- Enable ADC
	*/
	/*select External Voltage*/
	ADC_u8_ADMUX_REG &= 0b00111111;
	ADC_u8_ADMUX_REG |= (ADC_u8_REF << 6);
	/*disable left adjust*/
	/*for reading the value from the left
	  then the right*/
	ADC_u8_ADMUX_REG &= 0b11011111;
	ADC_u8_ADMUX_REG |= (ADC_u8_ADJUST<<5);
	/*disable auto triggering*/
	ADC_u8_ADCSRA_REG &= 0b11011111;
	ADC_u8_ADCSRA_REG |= (ADC_u8_AUTO_TRIGGER_STATE<<5);
	/*set CLK to div 8*/
	ADC_u8_ADCSRA_REG &= 0b11111000;
	ADC_u8_ADCSRA_REG |= ADC_u8_CLK_DIV;
	/*Enable ADC*/
	ADC_u8_ADCSRA_REG &= 0b01111111;
	ADC_u8_ADCSRA_REG |= (ADC_u8_STATUS<<7);
	
}
u8 ADC_u8GetDigitalValueSynchBlocking(u8 Copy_u8ChannelNum, u16* Copy_pu16DigitalValue){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u32 Local_u32TimeOutCounter = 0;
	/*for single ended*/
	if((Copy_u8ChannelNum<=ADC_u8_CHANNEL_7)&&(Copy_pu16DigitalValue != NULL)){
		/*ADC set busy flag*/
		ADC_u8_busy_flag = 1;
		/*clearing selection*/
		ADC_u8_ADMUX_REG &= 0b11100000;
		/*select channel*/
		ADC_u8_ADMUX_REG |= Copy_u8ChannelNum;
		/*start conversion*/
		SET_BIT(ADC_u8_ADCSRA_REG,6);
		/*wait until flag = 1*/
		while((READ_BIT(ADC_u8_ADCSRA_REG,4) == 0)&&(Local_u32TimeOutCounter<50000)){
			Local_u32TimeOutCounter++;
		}
		if(READ_BIT(ADC_u8_ADCSRA_REG,4) != 0){
			/*clear flag*/
			CLR_BIT(ADC_u8_ADCSRA_REG,4);
			/*read the digital value*/
			*Copy_pu16DigitalValue = ADC_u16_ADC_REG;
			/*ADC clear busy flag*/
			ADC_u8_busy_flag = 0;
		}else{
			Local_u8ErrorState = STD_TYPES_NOK;
		}
		
	}else{
		Local_u8ErrorState = STD_TYPES_NOK;
		
	}
	return Local_u8ErrorState;
}

u8 ADC_u8GetDigitalValueAsynch(u8 Copy_u8ChannelNum,void (*Copy_pfNotification)(u16)){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((Copy_u8ChannelNum<=ADC_u8_CHANNEL_7)&&(Copy_pfNotification != NULL)&&(ADC_u8_busy_flag == 0)){
		/*set flag to make ADC busy*/
		ADC_u8_busy_flag = 1;
		/*update global pointer to a function*/
		ADC_pfNotification = Copy_pfNotification;
		/*clearing selection*/
		ADC_u8_ADMUX_REG &= 0b11100000;
		/*enable ADC Interrupt*/
		SET_BIT(ADC_u8_ADCSRA_REG,3);
		/*select channel*/
		ADC_u8_ADMUX_REG |= Copy_u8ChannelNum;
		/*start conversion*/
		SET_BIT(ADC_u8_ADCSRA_REG,6);
	}else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

/*prototype of ISR*/
void __vector_16 (void) __attribute__((signal));
/*implementation of ISR*/
void __vector_16(void){
	if(ADC_pfNotification != NULL){
		/*clear busy flag*/
		ADC_u8_busy_flag = 0;
		/*disable interrupt of ADC*/
		CLR_BIT(ADC_u8_ADCSRA_REG,3);
		/*calling notification function*/
		ADC_pfNotification(ADC_u16_ADC_REG);
	}
}