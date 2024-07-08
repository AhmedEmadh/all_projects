/*
 * DIO_program.c
 *
 * Created: 6/14/2023 8:43:00 PM
 *  Author: Ahmed Emad Hassan
 */ 
#include "../../lib/std_types.h"
#include "../../lib/bit_math.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_config.h"


/*implementation of functions in interface.h*/

/*
**	//////////////////////////////(for DIO Functions)///////////////////////////////
**	functions:
**	DIO_u8SetPinDirection DIO_u8SetPinValue DIO_u8GetPinValue
**	Ports:
**	DIO_u8_PortA DIO_u8_PortB DIO_u8_PortC DIO_u8_PortD
**	Pins:
**	DIO_u8_Pin0 DIO_u8_Pin1 DIO_u8_Pin2 DIO_u8_Pin3 DIO_u8_Pin4 DIO_u8_Pin5 DIO_u8_Pin6 DIO_u8_Pin7
**	Directions:
**	DIO_u8_INPUT DIO_u8_OUTPUT
**	values:
**	DIO_u8_LOW DIO_u8_HIGH
*/

void DIO_voidInit(void){
	DIO_u8_DDRA_REG = conc(DIO_u8_PA7_INITIAL_DIRECTION,DIO_u8_PA6_INITIAL_DIRECTION,DIO_u8_PA5_INITIAL_DIRECTION,DIO_u8_PA4_INITIAL_DIRECTION,DIO_u8_PA3_INITIAL_DIRECTION,DIO_u8_PA2_INITIAL_DIRECTION,DIO_u8_PA1_INITIAL_DIRECTION,DIO_u8_PA0_INITIAL_DIRECTION);
	DIO_u8_DDRB_REG = conc(DIO_u8_PB7_INITIAL_DIRECTION,DIO_u8_PB6_INITIAL_DIRECTION,DIO_u8_PB5_INITIAL_DIRECTION,DIO_u8_PB4_INITIAL_DIRECTION,DIO_u8_PB3_INITIAL_DIRECTION,DIO_u8_PB2_INITIAL_DIRECTION,DIO_u8_PB1_INITIAL_DIRECTION,DIO_u8_PB0_INITIAL_DIRECTION);
	DIO_u8_DDRC_REG = conc(DIO_u8_PC7_INITIAL_DIRECTION,DIO_u8_PC6_INITIAL_DIRECTION,DIO_u8_PC5_INITIAL_DIRECTION,DIO_u8_PC4_INITIAL_DIRECTION,DIO_u8_PC3_INITIAL_DIRECTION,DIO_u8_PC2_INITIAL_DIRECTION,DIO_u8_PC1_INITIAL_DIRECTION,DIO_u8_PC0_INITIAL_DIRECTION);
	DIO_u8_DDRD_REG = conc(DIO_u8_PD7_INITIAL_DIRECTION,DIO_u8_PD6_INITIAL_DIRECTION,DIO_u8_PD5_INITIAL_DIRECTION,DIO_u8_PD4_INITIAL_DIRECTION,DIO_u8_PD3_INITIAL_DIRECTION,DIO_u8_PD2_INITIAL_DIRECTION,DIO_u8_PD1_INITIAL_DIRECTION,DIO_u8_PD0_INITIAL_DIRECTION);
	
	DIO_u8_PORTA_REG = conc(DIO_u8_PA7_INITIAL_VALUE,DIO_u8_PA6_INITIAL_VALUE,DIO_u8_PA5_INITIAL_VALUE,DIO_u8_PA4_INITIAL_VALUE,DIO_u8_PA3_INITIAL_VALUE,DIO_u8_PA2_INITIAL_VALUE,DIO_u8_PA1_INITIAL_VALUE,DIO_u8_PA0_INITIAL_VALUE);
	DIO_u8_PORTB_REG = conc(DIO_u8_PB7_INITIAL_VALUE,DIO_u8_PB6_INITIAL_VALUE,DIO_u8_PB5_INITIAL_VALUE,DIO_u8_PB4_INITIAL_VALUE,DIO_u8_PB3_INITIAL_VALUE,DIO_u8_PB2_INITIAL_VALUE,DIO_u8_PB1_INITIAL_VALUE,DIO_u8_PB0_INITIAL_VALUE);
	DIO_u8_PORTC_REG = conc(DIO_u8_PC7_INITIAL_VALUE,DIO_u8_PC6_INITIAL_VALUE,DIO_u8_PC5_INITIAL_VALUE,DIO_u8_PC4_INITIAL_VALUE,DIO_u8_PC3_INITIAL_VALUE,DIO_u8_PC2_INITIAL_VALUE,DIO_u8_PC1_INITIAL_VALUE,DIO_u8_PC0_INITIAL_VALUE);
	DIO_u8_PORTD_REG = conc(DIO_u8_PD7_INITIAL_VALUE,DIO_u8_PD6_INITIAL_VALUE,DIO_u8_PD5_INITIAL_VALUE,DIO_u8_PD4_INITIAL_VALUE,DIO_u8_PD3_INITIAL_VALUE,DIO_u8_PD2_INITIAL_VALUE,DIO_u8_PD1_INITIAL_VALUE,DIO_u8_PD0_INITIAL_VALUE);
}
u8 DIO_u8SetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinDirection){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	switch(Copy_u8PortID){
		case DIO_u8_PortA:
			switch(Copy_u8PinID){
				case DIO_u8_Pin0:
					switch(Copy_u8PinDirection){
						case DIO_u8_INPUT:
							CLR_BIT( DIO_u8_DDRA_REG,0);
							break;
						case DIO_u8_OUTPUT:
							SET_BIT( DIO_u8_DDRA_REG,0);
							break;
						default:
							Local_u8ErrorState = STD_TYPES_NOK;
					}
					break;
				case DIO_u8_Pin1:
					switch(Copy_u8PinDirection){
						case DIO_u8_INPUT:
						CLR_BIT( DIO_u8_DDRA_REG,1);
						break;
						case DIO_u8_OUTPUT:
						SET_BIT( DIO_u8_DDRA_REG,1);
						break;
						default:
						Local_u8ErrorState = STD_TYPES_NOK;
					}
					break;
				case DIO_u8_Pin2:
					switch(Copy_u8PinDirection){
						case DIO_u8_INPUT:
						CLR_BIT( DIO_u8_DDRA_REG,2);
						break;
						case DIO_u8_OUTPUT:
						SET_BIT( DIO_u8_DDRA_REG,2);
						break;
						default:
						Local_u8ErrorState = STD_TYPES_NOK;
					}
					break;
				case DIO_u8_Pin3:
					switch(Copy_u8PinDirection){
						case DIO_u8_INPUT:
						CLR_BIT( DIO_u8_DDRA_REG,3);
						break;
						case DIO_u8_OUTPUT:
						SET_BIT( DIO_u8_DDRA_REG,3);
						break;
						default:
						Local_u8ErrorState = STD_TYPES_NOK;
					}
					break;
				case DIO_u8_Pin4:
					switch(Copy_u8PinDirection){
						case DIO_u8_INPUT:
						CLR_BIT( DIO_u8_DDRA_REG,4);
						break;
						case DIO_u8_OUTPUT:
						SET_BIT( DIO_u8_DDRA_REG,4);
						break;
						default:
						Local_u8ErrorState = STD_TYPES_NOK;
					}
					break;
				case DIO_u8_Pin5:
					switch(Copy_u8PinDirection){
						case DIO_u8_INPUT:
						CLR_BIT( DIO_u8_DDRA_REG,5);
						break;
						case DIO_u8_OUTPUT:
						SET_BIT( DIO_u8_DDRA_REG,5);
						break;
						default:
						Local_u8ErrorState = STD_TYPES_NOK;
					}
					break;
				case DIO_u8_Pin6:
					switch(Copy_u8PinDirection){
						case DIO_u8_INPUT:
						CLR_BIT( DIO_u8_DDRA_REG,6);
						break;
						case DIO_u8_OUTPUT:
						SET_BIT( DIO_u8_DDRA_REG,6);
						break;
						default:
						Local_u8ErrorState = STD_TYPES_NOK;
					}
					break;
				case DIO_u8_Pin7:
					switch(Copy_u8PinDirection){
						case DIO_u8_INPUT:
						CLR_BIT( DIO_u8_DDRA_REG,7);
						break;
						case DIO_u8_OUTPUT:
						SET_BIT( DIO_u8_DDRA_REG,7);
						break;
						default:
						Local_u8ErrorState = STD_TYPES_NOK;
					}
					break;
				default:
				Local_u8ErrorState = STD_TYPES_NOK;
			}
			break;
		case DIO_u8_PortB:
			switch(Copy_u8PinID){
				case DIO_u8_Pin0:
				switch(Copy_u8PinDirection){
					case DIO_u8_INPUT:
					CLR_BIT( DIO_u8_DDRB_REG,0);
					break;
					case DIO_u8_OUTPUT:
					SET_BIT( DIO_u8_DDRA_REG,0);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
				case DIO_u8_Pin1:
				switch(Copy_u8PinDirection){
					case DIO_u8_INPUT:
					CLR_BIT( DIO_u8_DDRB_REG,1);
					break;
					case DIO_u8_OUTPUT:
					SET_BIT( DIO_u8_DDRB_REG,1);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
				case DIO_u8_Pin2:
				switch(Copy_u8PinDirection){
					case DIO_u8_INPUT:
					CLR_BIT( DIO_u8_DDRB_REG,2);
					break;
					case DIO_u8_OUTPUT:
					SET_BIT( DIO_u8_DDRB_REG,2);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
				case DIO_u8_Pin3:
				switch(Copy_u8PinDirection){
					case DIO_u8_INPUT:
					CLR_BIT( DIO_u8_DDRB_REG,3);
					break;
					case DIO_u8_OUTPUT:
					SET_BIT( DIO_u8_DDRB_REG,3);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
				case DIO_u8_Pin4:
				switch(Copy_u8PinDirection){
					case DIO_u8_INPUT:
					CLR_BIT( DIO_u8_DDRB_REG,4);
					break;
					case DIO_u8_OUTPUT:
					SET_BIT( DIO_u8_DDRB_REG,4);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
				case DIO_u8_Pin5:
				switch(Copy_u8PinDirection){
					case DIO_u8_INPUT:
					CLR_BIT( DIO_u8_DDRB_REG,5);
					break;
					case DIO_u8_OUTPUT:
					SET_BIT( DIO_u8_DDRB_REG,5);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
				case DIO_u8_Pin6:
				switch(Copy_u8PinDirection){
					case DIO_u8_INPUT:
					CLR_BIT( DIO_u8_DDRB_REG,6);
					break;
					case DIO_u8_OUTPUT:
					SET_BIT( DIO_u8_DDRB_REG,6);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
				case DIO_u8_Pin7:
				switch(Copy_u8PinDirection){
					case DIO_u8_INPUT:
					CLR_BIT( DIO_u8_DDRB_REG,7);
					break;
					case DIO_u8_OUTPUT:
					SET_BIT( DIO_u8_DDRB_REG,7);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
				default:
				Local_u8ErrorState = STD_TYPES_NOK;
			}
			break;
		case DIO_u8_PortC:
			/*PortC*/
			switch(Copy_u8PinID){
				case DIO_u8_Pin0:
				/*PortC*/
				switch(Copy_u8PinDirection){
					case DIO_u8_INPUT:
					CLR_BIT( DIO_u8_DDRC_REG,0);
					break;
					case DIO_u8_OUTPUT:
					SET_BIT( DIO_u8_DDRC_REG,0);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
				case DIO_u8_Pin1:
				/*PortC*/
				switch(Copy_u8PinDirection){
					case DIO_u8_INPUT:
					CLR_BIT( DIO_u8_DDRC_REG,1);
					break;
					case DIO_u8_OUTPUT:
					SET_BIT( DIO_u8_DDRC_REG,1);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
				case DIO_u8_Pin2:
				/*PortC*/
				switch(Copy_u8PinDirection){
					case DIO_u8_INPUT:
					CLR_BIT( DIO_u8_DDRC_REG,2);
					break;
					case DIO_u8_OUTPUT:
					SET_BIT( DIO_u8_DDRC_REG,2);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
				case DIO_u8_Pin3:
				/*PortC*/
				switch(Copy_u8PinDirection){
					case DIO_u8_INPUT:
					CLR_BIT( DIO_u8_DDRC_REG,3);
					break;
					case DIO_u8_OUTPUT:
					SET_BIT( DIO_u8_DDRC_REG,3);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
				case DIO_u8_Pin4:
				/*PortC*/
				switch(Copy_u8PinDirection){
					case DIO_u8_INPUT:
					CLR_BIT( DIO_u8_DDRC_REG,4);
					break;
					case DIO_u8_OUTPUT:
					SET_BIT( DIO_u8_DDRC_REG,4);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
				case DIO_u8_Pin5:
				/*PortC*/
				switch(Copy_u8PinDirection){
					case DIO_u8_INPUT:
					CLR_BIT( DIO_u8_DDRC_REG,5);
					break;
					case DIO_u8_OUTPUT:
					SET_BIT( DIO_u8_DDRC_REG,5);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
				case DIO_u8_Pin6:
				/*PortC*/
				switch(Copy_u8PinDirection){
					case DIO_u8_INPUT:
					CLR_BIT( DIO_u8_DDRC_REG,6);
					break;
					case DIO_u8_OUTPUT:
					SET_BIT( DIO_u8_DDRC_REG,6);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
				case DIO_u8_Pin7:
				/*PortC*/
				switch(Copy_u8PinDirection){
					case DIO_u8_INPUT:
					CLR_BIT( DIO_u8_DDRC_REG,7);
					break;
					case DIO_u8_OUTPUT:
					SET_BIT( DIO_u8_DDRC_REG,7);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
				default:
				Local_u8ErrorState = STD_TYPES_NOK;
			}
			break;
		case DIO_u8_PortD:
			/*PortD*/
			switch(Copy_u8PinID){
				case DIO_u8_Pin0:
					/*PortD*/
					switch(Copy_u8PinDirection){
						case DIO_u8_INPUT:
						CLR_BIT( DIO_u8_DDRD_REG,0);
						break;
						case DIO_u8_OUTPUT:
						SET_BIT( DIO_u8_DDRD_REG,0);
						break;
						default:
						Local_u8ErrorState = STD_TYPES_NOK;
					}
					break;
				case DIO_u8_Pin1:
					/*PortD*/
					switch(Copy_u8PinDirection){
						case DIO_u8_INPUT:
						CLR_BIT( DIO_u8_DDRD_REG,1);
						break;
						case DIO_u8_OUTPUT:
						SET_BIT( DIO_u8_DDRD_REG,1);
						break;
						default:
						Local_u8ErrorState = STD_TYPES_NOK;
					}
					break;
				case DIO_u8_Pin2:
					/*PortD*/
					switch(Copy_u8PinDirection){
						case DIO_u8_INPUT:
						CLR_BIT( DIO_u8_DDRD_REG,2);
						break;
						case DIO_u8_OUTPUT:
						SET_BIT( DIO_u8_DDRD_REG,2);
						break;
						default:
						Local_u8ErrorState = STD_TYPES_NOK;
					}
					break;
				case DIO_u8_Pin3:
					/*PortD*/
					switch(Copy_u8PinDirection){
						case DIO_u8_INPUT:
						CLR_BIT( DIO_u8_DDRD_REG,3);
						break;
						case DIO_u8_OUTPUT:
						SET_BIT( DIO_u8_DDRD_REG,3);
						break;
						default:
						Local_u8ErrorState = STD_TYPES_NOK;
					}
					break;
				case DIO_u8_Pin4:
					/*PortD*/
					switch(Copy_u8PinDirection){
						case DIO_u8_INPUT:
						CLR_BIT( DIO_u8_DDRD_REG,4);
						break;
						case DIO_u8_OUTPUT:
						SET_BIT( DIO_u8_DDRD_REG,4);
						break;
						default:
						Local_u8ErrorState = STD_TYPES_NOK;
					}
				break;
				case DIO_u8_Pin5:
					/*PortD*/
					switch(Copy_u8PinDirection){
						case DIO_u8_INPUT:
						CLR_BIT( DIO_u8_DDRD_REG,5);
						break;
						case DIO_u8_OUTPUT:
						SET_BIT( DIO_u8_DDRD_REG,5);
						break;
						default:
						Local_u8ErrorState = STD_TYPES_NOK;
					}
				break;
				case DIO_u8_Pin6:
					/*PortD*/
					switch(Copy_u8PinDirection){
						case DIO_u8_INPUT:
						CLR_BIT( DIO_u8_DDRD_REG,6);
						break;
						case DIO_u8_OUTPUT:
						SET_BIT( DIO_u8_DDRD_REG,6);
						break;
						default:
						Local_u8ErrorState = STD_TYPES_NOK;
					}
					break;
				case DIO_u8_Pin7:
				/*PortD*/
				switch(Copy_u8PinDirection){
					case DIO_u8_INPUT:
					CLR_BIT( DIO_u8_DDRD_REG,7);
					break;
					case DIO_u8_OUTPUT:
					SET_BIT( DIO_u8_DDRD_REG,7);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
				default:
				Local_u8ErrorState = STD_TYPES_NOK;
			}
			break;
		default:
		Local_u8ErrorState = STD_TYPES_NOK;	
	}
	return Local_u8ErrorState;
}
u8 DIO_u8SetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	
	
	switch(Copy_u8PinValue){
		case DIO_u8_HIGH:
			switch(Copy_u8PortID){
				case DIO_u8_PortA:
					switch(Copy_u8PinID){
						case DIO_u8_Pin0:
							SET_BIT(DIO_u8_PORTA_REG,0);
							break;
						case DIO_u8_Pin1:
							SET_BIT(DIO_u8_PORTA_REG,1);
							break;
						case DIO_u8_Pin2:
							SET_BIT(DIO_u8_PORTA_REG,2);
							break;
						case DIO_u8_Pin3:
							SET_BIT(DIO_u8_PORTA_REG,3);
							break;
						case DIO_u8_Pin4:
							SET_BIT(DIO_u8_PORTA_REG,4);
							break;
						case DIO_u8_Pin5:
							SET_BIT(DIO_u8_PORTA_REG,5);
							break;
						case DIO_u8_Pin6:
							SET_BIT(DIO_u8_PORTA_REG,6);
							break;
						case DIO_u8_Pin7:
							SET_BIT(DIO_u8_PORTA_REG,7);
							break;
						default:
						Local_u8ErrorState = STD_TYPES_NOK;
					}
					break;
				case DIO_u8_PortB:
					switch(Copy_u8PinID){
						case DIO_u8_Pin0:
						SET_BIT(DIO_u8_PORTB_REG,0);
						break;
						case DIO_u8_Pin1:
						SET_BIT(DIO_u8_PORTB_REG,1);
						break;
						case DIO_u8_Pin2:
						SET_BIT(DIO_u8_PORTB_REG,2);
						break;
						case DIO_u8_Pin3:
						SET_BIT(DIO_u8_PORTB_REG,3);
						break;
						case DIO_u8_Pin4:
						SET_BIT(DIO_u8_PORTB_REG,4);
						break;
						case DIO_u8_Pin5:
						SET_BIT(DIO_u8_PORTB_REG,5);
						break;
						case DIO_u8_Pin6:
						SET_BIT(DIO_u8_PORTB_REG,6);
						break;
						case DIO_u8_Pin7:
						SET_BIT(DIO_u8_PORTB_REG,7);
						break;
						default:
						Local_u8ErrorState = STD_TYPES_NOK;
					}
					break;
				case DIO_u8_PortC:
					switch(Copy_u8PinID){
						case DIO_u8_Pin0:
						SET_BIT(DIO_u8_PORTC_REG,0);
						break;
						case DIO_u8_Pin1:
						SET_BIT(DIO_u8_PORTC_REG,1);
						break;
						case DIO_u8_Pin2:
						SET_BIT(DIO_u8_PORTC_REG,2);
						break;
						case DIO_u8_Pin3:
						SET_BIT(DIO_u8_PORTC_REG,3);
						break;
						case DIO_u8_Pin4:
						SET_BIT(DIO_u8_PORTC_REG,4);
						break;
						case DIO_u8_Pin5:
						SET_BIT(DIO_u8_PORTC_REG,5);
						break;
						case DIO_u8_Pin6:
						SET_BIT(DIO_u8_PORTC_REG,6);
						break;
						case DIO_u8_Pin7:
						SET_BIT(DIO_u8_PORTC_REG,7);
						break;
						default:
						Local_u8ErrorState = STD_TYPES_NOK;
					}
					break;
				case DIO_u8_PortD:
					switch(Copy_u8PinID){
						case DIO_u8_Pin0:
						SET_BIT(DIO_u8_PORTD_REG,0);
						break;
						case DIO_u8_Pin1:
						SET_BIT(DIO_u8_PORTD_REG,1);
						break;
						case DIO_u8_Pin2:
						SET_BIT(DIO_u8_PORTD_REG,2);
						break;
						case DIO_u8_Pin3:
						SET_BIT(DIO_u8_PORTD_REG,3);
						break;
						case DIO_u8_Pin4:
						SET_BIT(DIO_u8_PORTD_REG,4);
						break;
						case DIO_u8_Pin5:
						SET_BIT(DIO_u8_PORTD_REG,5);
						break;
						case DIO_u8_Pin6:
						SET_BIT(DIO_u8_PORTD_REG,6);
						break;
						case DIO_u8_Pin7:
						SET_BIT(DIO_u8_PORTD_REG,7);
						break;
						default:
						Local_u8ErrorState = STD_TYPES_NOK;
					}
					break;
				default:
					Local_u8ErrorState = STD_TYPES_NOK;
			}
			break;
		case DIO_u8_LOW:
			switch(Copy_u8PortID){
				case DIO_u8_PortA:
				switch(Copy_u8PinID){
					case DIO_u8_Pin0:
					CLR_BIT(DIO_u8_PORTA_REG,0);
					break;
					case DIO_u8_Pin1:
					CLR_BIT(DIO_u8_PORTA_REG,1);
					break;
					case DIO_u8_Pin2:
					CLR_BIT(DIO_u8_PORTA_REG,2);
					break;
					case DIO_u8_Pin3:
					CLR_BIT(DIO_u8_PORTA_REG,3);
					break;
					case DIO_u8_Pin4:
					CLR_BIT(DIO_u8_PORTA_REG,4);
					break;
					case DIO_u8_Pin5:
					CLR_BIT(DIO_u8_PORTA_REG,5);
					break;
					case DIO_u8_Pin6:
					CLR_BIT(DIO_u8_PORTA_REG,6);
					break;
					case DIO_u8_Pin7:
					CLR_BIT(DIO_u8_PORTA_REG,7);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
				case DIO_u8_PortB:
				switch(Copy_u8PinID){
					case DIO_u8_Pin0:
					CLR_BIT(DIO_u8_PORTB_REG,0);
					break;
					case DIO_u8_Pin1:
					CLR_BIT(DIO_u8_PORTB_REG,1);
					break;
					case DIO_u8_Pin2:
					CLR_BIT(DIO_u8_PORTB_REG,2);
					break;
					case DIO_u8_Pin3:
					CLR_BIT(DIO_u8_PORTB_REG,3);
					break;
					case DIO_u8_Pin4:
					CLR_BIT(DIO_u8_PORTB_REG,4);
					break;
					case DIO_u8_Pin5:
					CLR_BIT(DIO_u8_PORTB_REG,5);
					break;
					case DIO_u8_Pin6:
					CLR_BIT(DIO_u8_PORTB_REG,6);
					break;
					case DIO_u8_Pin7:
					CLR_BIT(DIO_u8_PORTB_REG,7);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
				case DIO_u8_PortC:
				switch(Copy_u8PinID){
					case DIO_u8_Pin0:
					CLR_BIT(DIO_u8_PORTC_REG,0);
					break;
					case DIO_u8_Pin1:
					CLR_BIT(DIO_u8_PORTC_REG,1);
					break;
					case DIO_u8_Pin2:
					CLR_BIT(DIO_u8_PORTC_REG,2);
					break;
					case DIO_u8_Pin3:
					CLR_BIT(DIO_u8_PORTC_REG,3);
					break;
					case DIO_u8_Pin4:
					CLR_BIT(DIO_u8_PORTC_REG,4);
					break;
					case DIO_u8_Pin5:
					CLR_BIT(DIO_u8_PORTC_REG,5);
					break;
					case DIO_u8_Pin6:
					CLR_BIT(DIO_u8_PORTC_REG,6);
					break;
					case DIO_u8_Pin7:
					CLR_BIT(DIO_u8_PORTC_REG,7);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
				case DIO_u8_PortD:
				switch(Copy_u8PinID){
					case DIO_u8_Pin0:
					CLR_BIT(DIO_u8_PORTD_REG,0);
					break;
					case DIO_u8_Pin1:
					CLR_BIT(DIO_u8_PORTD_REG,1);
					break;
					case DIO_u8_Pin2:
					CLR_BIT(DIO_u8_PORTD_REG,2);
					break;
					case DIO_u8_Pin3:
					CLR_BIT(DIO_u8_PORTD_REG,3);
					break;
					case DIO_u8_Pin4:
					CLR_BIT(DIO_u8_PORTD_REG,4);
					break;
					case DIO_u8_Pin5:
					CLR_BIT(DIO_u8_PORTD_REG,5);
					break;
					case DIO_u8_Pin6:
					CLR_BIT(DIO_u8_PORTD_REG,6);
					break;
					case DIO_u8_Pin7:
					CLR_BIT(DIO_u8_PORTD_REG,7);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
				default:
				Local_u8ErrorState = STD_TYPES_NOK;
			}
			break;
		default:
			Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
u8 DIO_u8GetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8* Copy_pu8PinValue){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_pu8PinValue != NULL){	
		switch(Copy_u8PinID){
			case DIO_u8_Pin0:
				switch(Copy_u8PortID){
					case DIO_u8_PortA:
						*Copy_pu8PinValue = READ_BIT(DIO_u8_PINA_REG,0);
						break;
					case DIO_u8_PortB:
						*Copy_pu8PinValue = READ_BIT(DIO_u8_PINB_REG,0);
						break;
					case DIO_u8_PortC:
						*Copy_pu8PinValue = READ_BIT(DIO_u8_PINC_REG,0);
						break;
					case DIO_u8_PortD:
						*Copy_pu8PinValue = READ_BIT(DIO_u8_PIND_REG,0);
						break;
					default:
						Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
			case DIO_u8_Pin1:
				switch(Copy_u8PortID){
					case DIO_u8_PortA:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PINA_REG,1);
					break;
					case DIO_u8_PortB:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PINB_REG,1);
					break;
					case DIO_u8_PortC:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PINC_REG,1);
					break;
					case DIO_u8_PortD:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PIND_REG,1);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
			case DIO_u8_Pin2:
				switch(Copy_u8PortID){
					case DIO_u8_PortA:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PINA_REG,2);
					break;
					case DIO_u8_PortB:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PINB_REG,2);
					break;
					case DIO_u8_PortC:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PINC_REG,2);
					break;
					case DIO_u8_PortD:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PIND_REG,2);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
			case DIO_u8_Pin3:
				switch(Copy_u8PortID){
					case DIO_u8_PortA:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PINA_REG,3);
					break;
					case DIO_u8_PortB:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PINB_REG,3);
					break;
					case DIO_u8_PortC:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PINC_REG,3);
					break;
					case DIO_u8_PortD:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PIND_REG,3);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
			case DIO_u8_Pin4:
				switch(Copy_u8PortID){
					case DIO_u8_PortA:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PINA_REG,4);
					break;
					case DIO_u8_PortB:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PINB_REG,4);
					break;
					case DIO_u8_PortC:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PINC_REG,4);
					break;
					case DIO_u8_PortD:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PIND_REG,4);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
			case DIO_u8_Pin5:
				switch(Copy_u8PortID){
					case DIO_u8_PortA:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PINA_REG,5);
					break;
					case DIO_u8_PortB:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PINB_REG,5);
					break;
					case DIO_u8_PortC:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PINC_REG,5);
					break;
					case DIO_u8_PortD:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PIND_REG,5);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
			case DIO_u8_Pin6:
				switch(Copy_u8PortID){
					case DIO_u8_PortA:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PINA_REG,6);
					break;
					case DIO_u8_PortB:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PINB_REG,6);
					break;
					case DIO_u8_PortC:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PINC_REG,6);
					break;
					case DIO_u8_PortD:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PIND_REG,6);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
			case DIO_u8_Pin7:
				switch(Copy_u8PortID){
					case DIO_u8_PortA:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PINA_REG,7);
					break;
					case DIO_u8_PortB:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PINB_REG,7);
					break;
					case DIO_u8_PortC:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PINC_REG,7);
					break;
					case DIO_u8_PortD:
					*Copy_pu8PinValue = READ_BIT(DIO_u8_PIND_REG,7);
					break;
					default:
					Local_u8ErrorState = STD_TYPES_NOK;
				}
				break;
			default:
			Local_u8ErrorState = STD_TYPES_NOK;
		
		}
	}
	return Local_u8ErrorState;
}


u8 DIO_u8SetPortValue(u8 Copy_u8PortID,u8 Copy_u8Value){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	switch(Copy_u8PortID){
		case DIO_u8_PortA:
			DIO_u8_PORTA_REG = Copy_u8Value;
		break;
		case DIO_u8_PortB:
			DIO_u8_PORTB_REG = Copy_u8Value;
		break;
		case DIO_u8_PortC:
			DIO_u8_PORTC_REG = Copy_u8Value;
		break;
		case DIO_u8_PortD:
			DIO_u8_PORTD_REG = Copy_u8Value;
		break;
		default:
			Local_u8ErrorState = STD_TYPES_NOK;		
	}
	return Local_u8ErrorState;
}