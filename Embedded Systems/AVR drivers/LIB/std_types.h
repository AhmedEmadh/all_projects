/*
 * std_types.h
 *
 * Created: 6/15/2023 12:20:09 AM
 *  Author: Ahmed Emad Hassan
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_
/*defining data types*/
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;
/*data types used in error detection*/
#define STD_TYPES_OK	1
#define STD_TYPES_NOK	0

#ifndef NULL
#define NULL ((void*)0)
#endif

#endif /* STD_TYPES_H_ */