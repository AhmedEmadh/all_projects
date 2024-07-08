/*
 * DIO_private.h
 *
 * Created: 6/14/2023 8:44:11 PM
 *  Author: Ahmed Emad Hassan
 */ 

/*not accessible in app layer*/
/*accessible only inside the driver*/

/*
*	there are 3 registers for each port (X is A, B, C or D)
*	DDRX: sets the direction of each pin in the port 0 for input and 1 for output
*	PORTX: sets the value of the pin 1 for HIGH and 0 for LOW 
*		   if the pin is input then 0 for no pull up resistor and 1 for activate pull up resistor
*	PINX: holds the value of the pin at any cause for reading (read only)
*/


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


#define DIO_u8_INITIAL_INPUT					0
#define DIO_u8_INITIAL_OUTPUT					1

#define DIO_u8_INITIAL_OUTPUT_LOW				0
#define DIO_u8_INITIAL_OUTPUT_HIGH				1
#define DIO_u8_INITIAL_INPUT_FLOATING			0
#define DIO_u8_INITIAL_INPUT_PULLUP				1

#define conc(b7,b6,b5,b4,b3,b2,b1,b0) conc_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define conc_help(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0







#define DIO_u8_PORTA_REG	(*((volatile u8*)0x3B))
#define DIO_u8_DDRA_REG		(*((volatile u8*)0x3A))
#define DIO_u8_PINA_REG		(*((volatile u8*)0x39))

#define DIO_u8_PORTB_REG	(*((volatile u8*)0x38))
#define DIO_u8_DDRB_REG		(*((volatile u8*)0x37))
#define DIO_u8_PINB_REG		(*((volatile u8*)0x36))

#define DIO_u8_PORTC_REG	(*((volatile u8*)0x35))
#define DIO_u8_DDRC_REG		(*((volatile u8*)0x34))
#define DIO_u8_PINC_REG		(*((volatile u8*)0x33))

#define DIO_u8_PORTD_REG	(*((volatile u8*)0x32))
#define DIO_u8_DDRD_REG		(*((volatile u8*)0x31))
#define DIO_u8_PIND_REG		(*((volatile u8*)0x30))




#endif /* DIO_PRIVATE_H_ */