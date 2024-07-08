/*
 * TIMERS_config.h
 *
 * Created: 6/20/2023 11:16:47 PM
 *  Author: Ahmed Emad Hassan
 */ 


#ifndef TIMERS_CONFIG_H_
#define TIMERS_CONFIG_H_

#define TIMER0_u8_MODE						TIMERS_u8_CTC_MODE

#define TIMER0_u8_OVF_INTTURUPT				TIMERS_u8_OVF_INTTURUPT_ENABLE

#define TIMER0_u8_CLK_PRESCALER				TIMER0_u8_CLK_PRESCALER_CLK_DIV_1

#define TIMER0_u8_MODE_OPTION				TIMER0_u8_PWM_PHASE_CORRECT_MODE_OPTION_OC_PIN_CLR_COMPARE_UP_SET_DOWN

#define TIMER0_u8_PRELOAD_VALUE				199
#define TIMER0_u8_NUMBER_OF_OVERFLOWS		5

#endif /* TIMERS_CONFIG_H_ */