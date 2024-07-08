/*
 * TIMERS_private.h
 *
 * Created: 6/20/2023 11:16:21 PM
 *  Author: Ahmed Emad Hassan
 */ 


#ifndef TIMERS_PRIVATE_H_
#define TIMERS_PRIVATE_H_
/*definition of registers*/

/* TIMSK: OCIE2 TOIE2 TICIE1 OCIE1A OCIE1B TOIE1 OCIE0 TOIE0 */
#define TIMERS_u8_TIMSK_REG			*((volatile u8*)0X59)
/* TIFR: OCF2 TOV2 ICF1 OCF1A OCF1B TOV1 OCF0 TOV0 */
#define TIMERS_u8_TIFR_REG			*((volatile u8*)0X58)
/* TCCR0: FOC0 WGM00 COM01 COM00 WGM01 CS02 CS01 CS00 */
#define TIMERS_u8_TCCR0_REG			*((volatile u8*)0X53)
/* TCNT0: TIMER/COUNTER0-8bits */
#define TIMERS_u8_TCNT0_REG			*((volatile u8*)0X52)
/* OCR0: TIMER/COUNTER0-8bits-output-compare */
#define TIMERS_u8_OCR0_REG			*((volatile u8*)0X5C)

#define TIMERS_u8_TCCR1A_REG		*((volatile u8*)0X4F)			
#define TIMERS_u8_TCCR1B_REG		*((volatile u8*)0X4E)			
#define TIMERS_u8_TCNT1H_REG		*((volatile u8*)0X4D)			
#define TIMERS_u8_TCNT1L_REG		*((volatile u8*)0X4C)			

#define TIMERS_u16_TCNT1_REG		*((volatile u16*)0X4C)			

#define TIMERS_u8_OCR1AH_REG		*((volatile u16*)0x4B)
#define TIMERS_u8_OCR1AL_REG		*((volatile u16*)0x4A)

#define TIMERS_u16_OCR1A_REG		*((volatile u16*)0x4A)


#define TIMERS_u8_ICR1H_REG			*((volatile u8*) 0X47)
#define TIMERS_u8_ICR1L_REG			*((volatile u8*) 0X46)
									
#define TIMERS_u16_ICR1_REG			*((volatile u16*)0x46)





#define TIMERS_u8_NORMAL_MODE																				0
#define TIMERS_u8_PWM_PHASE_CORRECT_MODE																	1
#define TIMERS_u8_CTC_MODE																					2
#define TIMERS_u8_FAST_PWM_MODE																				3

#define TIMERS_u8_OVF_INTTURUPT_DISABLE																		0
#define TIMERS_u8_OVF_INTTURUPT_ENABLE																		1

#define TIMER0_u8_CLK_PRESCALER_NO_CLK																		0
#define TIMER0_u8_CLK_PRESCALER_CLK_DIV_1																	1
#define TIMER0_u8_CLK_PRESCALER_CLK_DIV_8																	2
#define TIMER0_u8_CLK_PRESCALER_CLK_DIV_64																	3
#define TIMER0_u8_CLK_PRESCALER_CLK_DIV_256																	4
#define TIMER0_u8_CLK_PRESCALER_CLK_DIV_1024																5
#define TIMER0_u8_CLK_PRESCALER_CLK_EXTERNAL_T0_ON_FALLING_EDGE												6
#define TIMER0_u8_CLK_PRESCALER_CLK_EXTERNAL_T0_ON_RISING_EDGE												7

/* options for normal mode and clear on compare mode */
#define TIMER0_u8_NON_PWM_MODE_OPTION_OC0_PIN_DISCONNECTED													0
#define TIMER0_u8_NON_PWM_MODE_OPTION_OC0_PIN_TOGGLE_ON_COMPARE_MATCH										1
#define TIMER0_u8_NON_PWM_MODE_OPTION_OC0_PIN_CLR_ON_COMPARE_MATCH											2
#define TIMER0_u8_NON_PWM_MODE_OPTION_OC0_PIN_SET_ON_COMPARE_MATCH											3

/* options for fast PWM mode */
#define TIMER0_u8_FAST_PWM_MODE_OPTION_OC_PIN_DISCONNECTED													0
#define TIMER0_u8_FAST_PWM_MODE_OPTION_OC_PIN_NON_INVERTING_MODE											2
#define TIMER0_u8_FAST_PWM_MODE_OPTION_OC_PIN_INVERTING_MODE												3

/* options on Phase correct PWM Mode */
#define TIMER0_u8_PWM_PHASE_CORRECT_MODE_OPTION_OC_PIN_DISCONNECTED											0
#define TIMER0_u8_PWM_PHASE_CORRECT_MODE_OPTION_OC_PIN_CLR_COMPARE_UP_SET_DOWN								2
#define TIMER0_u8_PWM_PHASE_CORRECT_MODE_OPTION_OC_PIN_SET_COMPARE_UP_CLR_DOWN								3




#endif /* TIMERS_PRIVATE_H_ */