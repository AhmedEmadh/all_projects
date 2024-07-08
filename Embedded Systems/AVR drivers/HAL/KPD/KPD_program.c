/*
 * KPD_program.c
 *
 * Created: 7/14/2023 2:01:02 AM
 *  Author: Ahmed Emad Hassan
 */ 

#include "../../lib/std_types.h"
#include "../../lib/bit_math.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "KPD_private.h"
#include "KPD_config.h"
#include "KPD_interface.h"

u8 KPD_Au8keys[KPD_u8_NUMBER_OF_ROWS][KPD_u8_NUMBER_OF_COLS] = KPD_MATRIX;


/* Output rows pins */
u8 KPD_Au8Rows[KPD_u8_NUMBER_OF_ROWS] = KPD_ROWS;
/* Input columns pins */
u8 KPD_Au8Colomns[KPD_u8_NUMBER_OF_COLS] = KPD_COLS;
u8 KPD_u8GetKeyStatus(u8 * Copy_pu8Returnedkey){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_u8CounterRow = 0;
	u8 Local_u8CounterColomn = 0;
	u8 Local_u8ReadKeyFlag = 0;
	u8 Local_u8ColomnPinValue = 0;
	/* check input arguments */
	if(Copy_pu8Returnedkey != NULL){
		/* Activate all rows (LOW) */
		for(Local_u8CounterRow = 0; Local_u8CounterRow < 4; Local_u8CounterRow++){
			/* activate row (LOW) */
			DIO_u8SetPinValue(KPD_u8_PORT,KPD_Au8Rows[Local_u8CounterRow],DIO_u8_LOW);
			/* test all columns (LOW) */
			for(Local_u8CounterColomn=0;Local_u8CounterColomn<4;Local_u8CounterColomn++){
				/* Read Pin Value (LOW) */
				DIO_u8GetPinValue(KPD_u8_PORT,KPD_Au8Colomns[Local_u8CounterColomn],&Local_u8ColomnPinValue);
				if(Local_u8ColomnPinValue == DIO_u8_LOW){
					/* store returned key */
					*Copy_pu8Returnedkey = KPD_Au8keys[Local_u8CounterRow][Local_u8CounterColomn];
					/* wait until the key is up */
					while(Local_u8ColomnPinValue == DIO_u8_LOW){
						DIO_u8GetPinValue(KPD_u8_PORT,KPD_Au8Colomns[Local_u8CounterColomn],&Local_u8ColomnPinValue);
					}
					/* set the flag */
					Local_u8ReadKeyFlag = 1;
					break;
				}
			}
			/* deactivate the row (HIGH)*/
			DIO_u8SetPinValue(KPD_u8_PORT,KPD_Au8Rows[Local_u8CounterRow],DIO_u8_HIGH);
			if(Local_u8ReadKeyFlag == 1)
				break;
		}
		/* if exited loop and no key is pressed */
		if(Local_u8ReadKeyFlag == 0)
			*Copy_pu8Returnedkey = KPD_u8_Key_Not_Pressed;
	}else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}