/*
 * ADC_private.h
 *
 * Created: 6/19/2023 4:02:07 PM
 *  Author: Ahmed Emad Hassan
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_
/* ADMUX: REFS1 REFS0 ADLAR MUX4 MUX3 MUX2 MUX1 MUX0 */

/* REF 00 => internal Vref Turned off
** REF 01 => AVCC with external capacitor at AREF pin
** REF 10 => reserved
** REF 11 => internal 2.56V reference with external capacitor at AREF
**
** ADLAR 0 => right adjust reading of 10 bits
** ADLAR 1 => left adjust reading of 10 bits
**
** MUX => select channels
*/
#define ADC_u8_ADMUX_REG			*((volatile u8*)0x27)
#define ADC_u8_ADCSRA_REG			*((volatile u8*)0x26)
#define ADC_u8_ADCH_REG				*((volatile u8*)0x25)
#define ADC_u8_ADCL_REG				*((volatile u8*)0x24)

#define ADC_u16_ADC_REG				*((volatile u16*)0x24)

#define ADC_u8_SFIOR_REG			*((volatile u8*)0x50)

#define ADC_u8_EXTERNAL_REF				0
#define ADC_u8_INTERNAL_VCC_REF			1
#define ADC_u8_INTERNAL_2_56_V_REF		3

#define ADC_u8_RIGHT_ADJUST				0
#define ADC_u8_LEFT_ADJUST				1

#define ADC_u8_AUTO_TRIGGER_ENABLE		1
#define ADC_u8_AUTO_TRIGGER_DISABLE		0

#define ADC_u8_CLK_DIV_2				0
#define ADC_u8_CLK_DIV_2_				1
#define ADC_u8_CLK_DIV_4				2				
#define ADC_u8_CLK_DIV_8				3
#define ADC_u8_CLK_DIV_16				4
#define ADC_u8_CLK_DIV_32				5
#define ADC_u8_CLK_DIV_64				6
#define ADC_u8_CLK_DIV_128				7

#define ADC_u8_ENABLE					1
#define ADC_u8_DISABLE					0




#endif /* ADC_PRIVATE_H_ */