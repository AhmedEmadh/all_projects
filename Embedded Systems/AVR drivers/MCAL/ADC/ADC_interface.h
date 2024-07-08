/*
 * ADC_interface.h
 *
 * Created: 6/19/2023 4:01:46 PM
 *  Author: Ahmed Emad Hassan
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_voidInit(void);
u8 ADC_u8GetDigitalValueSynchBlocking(u8 Copy_u8ChannelNum, u16* Copy_pu16DigitalValue);
u8 ADC_u8GetDigitalValueAsynch(u8 Copy_u8ChannelNum,void (*Copy_pfNotification)(u16));
u8 ADC_u8GetADCRegValue(u16 *Copy_pu16ADCValue);
#define ADC_u8_CHANNEL_0	0
#define ADC_u8_CHANNEL_1	1
#define ADC_u8_CHANNEL_2	2
#define ADC_u8_CHANNEL_3	3
#define ADC_u8_CHANNEL_4	4
#define ADC_u8_CHANNEL_5	5
#define ADC_u8_CHANNEL_6	6
#define ADC_u8_CHANNEL_7	7

#endif /* ADC_INTERFACE_H_ */