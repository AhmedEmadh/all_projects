/*
 * DIO_program.h
 *
 * Created: 6/14/2023 8:43:21 PM
 *  Author: Ahmed Emad Hassan
 */ 

/*accessible in app layer*/
/*included by app layer*/




#define DIO_u8_LOW				0
#define DIO_u8_HIGH				1
#define DIO_u8_INPUT_FLOOTING	0
#define DIO_u8_INPUT_PULLUP		1

#define DIO_u8_INPUT			2
#define DIO_u8_OUTPUT			3


#define DIO_u8_PortA			5
#define DIO_u8_PortB			6
#define DIO_u8_PortC			7
#define DIO_u8_PortD			8

#define DIO_u8_Pin0				9
#define DIO_u8_Pin1				10
#define DIO_u8_Pin2				11
#define DIO_u8_Pin3				12
#define DIO_u8_Pin4				13
#define DIO_u8_Pin5				14
#define DIO_u8_Pin6				15
#define DIO_u8_Pin7				16



void DIO_voidInit(void);
u8 DIO_u8SetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinDirection);
u8 DIO_u8SetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue);
u8 DIO_u8GetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8* Copy_pu8PinValue);
u8 DIO_u8SetPortValue(u8 Copy_u8PortID,u8 Copy_u8Value);
