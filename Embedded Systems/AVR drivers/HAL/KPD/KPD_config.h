/*
 * KPD_config.h
 *
 * Created: 7/14/2023 2:03:25 AM
 *  Author: Ahmed Emad Hassan
 */ 


#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define KPD_u8_PORT		DIO_u8_PortB

#define KPD_u8_R1_PIN	DIO_u8_Pin0
#define KPD_u8_R2_PIN	DIO_u8_Pin1
#define KPD_u8_R3_PIN	DIO_u8_Pin2
#define KPD_u8_R4_PIN	DIO_u8_Pin3


#define KPD_u8_C1_PIN	DIO_u8_Pin4
#define KPD_u8_C2_PIN	DIO_u8_Pin5
#define KPD_u8_C3_PIN	DIO_u8_Pin6
#define KPD_u8_C4_PIN	DIO_u8_Pin7

#define KPD_u8_NUMBER_OF_ROWS	4
#define KPD_u8_NUMBER_OF_COLS	4

#define KPD_MATRIX		{	{'7','8','9','/'},				\
							{'4','5','6','*'},				\
							{'1','2','3','-'},				\
							{'c','0','=','+'}				\
						}									
						
#define KPD_ROWS		{KPD_u8_R1_PIN,KPD_u8_R2_PIN,KPD_u8_R3_PIN,KPD_u8_R4_PIN}

#define KPD_COLS		{KPD_u8_C1_PIN,KPD_u8_C2_PIN,KPD_u8_C3_PIN,KPD_u8_C4_PIN}

#endif /* KPD_CONFIG_H_ */