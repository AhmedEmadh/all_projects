/*
 * EXTI_interface.h
 *
 * Created: 6/17/2023 10:48:33 AM
 *  Author: Ahmed Emad Hassan
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_u8_INTERRUPT_0		0
#define EXTI_u8_INTERRUPT_1		1
#define EXTI_u8_INTERRUPT_2		2

#define EXTI_u8_INTERRUPT_LOW_LEVEL			0
#define EXTI_u8_INTERRUPT_LOGICAL_CHANGE	1
#define EXTI_u8_INTERRUPT_FALLING_EDGE		2
#define EXTI_u8_INTERRUPT_RISING_EDGE		3


u8 EXTI_u8Enable(u8 Copy_u8InterruptIndex,u8 Copy_u8InterruptEdge);

u8 EXTI_u8Disable(u8 Copy_u8InterruptIndex);

void __vector_1 (void) __attribute__((signal));
void __vector_2 (void) __attribute__((signal));
void __vector_3 (void) __attribute__((signal));

#endif /* EXTI_INTERFACE_H_ */