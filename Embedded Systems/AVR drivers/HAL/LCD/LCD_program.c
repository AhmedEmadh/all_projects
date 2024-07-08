/*
 * LCD_program.c
 *
 * Created: 7/24/2023 1:57:18 AM
 *  Author: Ahmed Emad Hassan
 */ 

/* include from lib */
#include "../../lib/std_types.h"
#include "../../lib/bit_math.h"
#include "../../lib/num_str_conv.h"
/* include from DIO */
#include "../../MCAL/DIO/DIO_interface.h"
/* include from LCD */
#include "LCD_private.h"
#include "LCD_config.h"
#include "LCD_interface.h"

/* define delay */
#ifndef F_CPU
#define F_CPU 1000000UL
#endif

#include "util/delay.h"

void LCD_voidInit(){
	/* wait more than 30ms */
	_delay_ms(35);
	 
	/* function set pattern */
	LCD_voidSendCmnd(0b00111000);
	/* wait more than 39us */
	_delay_us(50);
	 
	/* display on/off control */
	LCD_voidSendCmnd(0b00001100);
	/* wait for more than 39us */
	_delay_us(50);
	 
	/* display clear */
	LCD_voidSendCmnd(0b00000001);
	/* wait for more than 1.53ms */
	_delay_ms(2);
	 
	/* Entry Mode Set */
	LCD_voidSendCmnd(0b00000110);
	/* End of initialization */
	 
}
void LCD_voidSendCmnd(u8 Copy_u8Data){
	/* clear RS Pin to send command */
	DIO_u8SetPinValue(LCD_u8_RS_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);
	/* clear RW Pin to write */
	DIO_u8SetPinValue(LCD_u8_RW_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	/* write data port with cmnd*/
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Data);
	/* Set Enable Pin to HIGH */
	DIO_u8SetPinValue(LCD_u8_E_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	/* wait */
	 
	_delay_us(1);
	/* set enable pin to low */
	DIO_u8SetPinValue(LCD_u8_E_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
	 
}
void LCD_voidSendChar(u8 Copy_u8Data){
	/* set RS Pin to send character */
	DIO_u8SetPinValue(LCD_u8_RS_PORT,LCD_u8_RS_PIN,DIO_u8_HIGH);
	/* clear RW Pin to write */
	DIO_u8SetPinValue(LCD_u8_RW_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	/* write data port with character*/
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Data);
	/* Set Enable Pin to HIGH */
	DIO_u8SetPinValue(LCD_u8_E_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	/* wait */
	 
	_delay_us(1);
	/* set enable pin to low */
	DIO_u8SetPinValue(LCD_u8_E_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
	 
}

u8 LCD_u8SendString(u8 *Copy_pu8String){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pu8String != NULL){
		u8 counter = 0;
		while(Copy_pu8String[counter] != '\0'){
			LCD_voidSendChar(Copy_pu8String[counter]);
			counter++;
		}
	}else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
	
}
u8 LCD_u8SendString_const(const u8 *Copy_pu8String){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pu8String != NULL){
		u8 counter = 0;
		while(Copy_pu8String[counter] != '\0'){
			LCD_voidSendChar(Copy_pu8String[counter]);
			counter++;
		}
		}else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
	
}

void LCD_voidSendNum(s32 num){
	u8 Local_pu8String[20];
	if(num<0){
		/* print negative sign then turn num into positive to get the string and send it */
		LCD_voidSendChar('-');
		num *= -1;
	}
		numberPositiveToString(num,Local_pu8String);
		LCD_u8SendString(Local_pu8String);
}
u8 LCD_u8SetPos(u8 Copy_u8Line,u8 Copy_u8Position){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_u8Position<40){
		switch(Copy_u8Line){
			case LCD_u8_LINE1:
				LCD_voidSendCmnd(0b10000000+Copy_u8Position);
			break;
			case LCD_u8_LINE2:
				LCD_voidSendCmnd(0b11000000+Copy_u8Position);
			break;
			default:
				Local_u8ErrorState = STD_TYPES_NOK;
		}
	}else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

void LCD_voidClear(){
	LCD_voidSendCmnd(0x01);
	_delay_ms(2);
}