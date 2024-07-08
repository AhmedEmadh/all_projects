/*
 * DCM_program.c
 *
 * Created: 7/26/2023 5:13:34 AM
 *  Author: Ahmed Emad Hassan
 */ 

/* lib */
#include "../../lib/std_types.h"
#include "../../lib/bit_math.h"
/* DIO */
#include "../../MCAL/DIO/DIO_interface.h"
/* DCM */
#include "DCM_private.h"
#include "DCM_config.h"
#include "DCM_interface.h"

void DCM_voidTurnRight(){
	DIO_u8SetPinValue(DCM_u8_PORT,DCM_u8_IN1_PIN,DIO_u8_HIGH);
	DIO_u8SetPinValue(DCM_u8_PORT,DCM_u8_IN2_PIN,DIO_u8_LOW);
}
void DCM_voidTurnLeft(){
	DIO_u8SetPinValue(DCM_u8_PORT,DCM_u8_IN1_PIN,DIO_u8_LOW);
	DIO_u8SetPinValue(DCM_u8_PORT,DCM_u8_IN2_PIN,DIO_u8_HIGH);
}
void DCM_voidTurnOff(){
	DIO_u8SetPinValue(DCM_u8_PORT,DCM_u8_IN1_PIN,DIO_u8_LOW);
	DIO_u8SetPinValue(DCM_u8_PORT,DCM_u8_IN2_PIN,DIO_u8_LOW);
}


