/*
 * TIMERS_interface.h
 *
 * Created: 6/20/2023 11:15:56 PM
 *  Author: Ahmed Emad Hassan
 */ 


#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_

void TIMERS_voidTimer0Init(void);
u8 TIMERS_u8Timer0SetCallBack(void(*Copy_pf)(void));
void set_angle(u8 Copy_u8Angle);
void TIMERS_voidTimer0SetCompareMatchValue(u8 Copy_u8OCR0Value);

void TIMERS_voidTimer1Init(void);

void TIMERS_voidTimer1SetCompareMatchValueA(u16 Copy_u16OCRValue);



#endif /* TIMERS_INTERFACE_H_ */