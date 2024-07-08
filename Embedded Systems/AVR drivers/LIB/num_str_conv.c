/*
 * num_str_conv.c
 *
 * Created: 7/24/2023 6:22:48 PM
 *  Author: Ahmed Emad Hassan
 */ 
#include "bit_math.h"
#include "std_types.h"

u32 power(u32 Copy_u32Base,u32 Copy_u32exponent){
	u8 Local_u8Counter = 0;
	u32 Local_u32Result = 1;
	for(Local_u8Counter = 0;Local_u8Counter<Copy_u32exponent;Local_u8Counter++){
		Local_u32Result *= Copy_u32Base;
	}
	return Local_u32Result;
}
void numberPositiveToString(u32 num,u8 *Copy_u8String){
	s8 counter = 0;
	u8 stringCounter = 0;
	u8 Local_u8Array[10] = {0,0,0,0,0,0,0,0,0,0};
	Local_u8Array[9] = num/1000000000UL;
	for(counter = 0;counter< 9;counter++){
		Local_u8Array[counter] = (num % power(10,counter+1))/power(10,counter);
	}
	/* get the beginning of the string */
	s8 counter_initial = 9;
	while(Local_u8Array[counter_initial] == 0){
		counter_initial--;
	}
	/* convert array to string */
	for(counter = counter_initial;counter>=0;counter--){
		Copy_u8String[stringCounter] = Local_u8Array[counter] + '0';
		stringCounter++;
	}
	Copy_u8String[stringCounter] = '\0';
}