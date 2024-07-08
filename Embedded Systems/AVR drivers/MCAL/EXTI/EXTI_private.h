/*
 * EXTI_private.h
 *
 * Created: 6/17/2023 10:48:55 AM
 *  Author: Ahmed Emad Hassan
 */ 


#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

/* GICR : (INT1) (INT0) (INT2) _ _ _ IVSEL IVCE */
#define EXTI_u8_GICR_REG										*((volatile u8*)0x5B)		
/* MCUCR : SE SM2 SM1 SM0 (ISC11) (ISC10) (ISC01) (ISC00) */
#define EXTI_u8_MCUCR_REG										*((volatile u8*)0x55)
/* MCUCSR : JTD (ISC2) _ JTRF WDRF BORF EXTRF PORF */
#define EXTI_u8_MCUCSR_REG										*((volatile u8*)0x54)
/* GIFR : (INTF1) (INTF0) (INTF2) _ _ _ _ _ */
#define EXTI_u8_GIFR_REG										*((volatile u8*)0x5A)


#endif /* EXTI_PRIVATE_H_ */