/*
 * bit_math.h
 *
 * Created: 6/15/2023 12:19:32 AM
 *  Author: Ahmed Emad Hassan
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,bit)		reg = reg | (1<<bit)
#define CLR_BIT(reg,bit)		reg = reg & (~(1<<bit))
#define TOG_BIT(reg,bit)		reg = reg ^ (1<<bit)
#define READ_BIT(reg,bit)		((reg>>bit)&1)




#endif /* BIT_MATH_H_ */