/*
 * LCD_interface.h
 *
 * Created: 7/24/2023 1:57:38 AM
 *  Author: Ahmed Emad Hassan
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_voidInit();
void LCD_voidSendCmnd(u8 Copy_u8Data);
void LCD_voidSendChar(u8 Copy_u8Data);
u8 LCD_u8SendString(u8 *Copy_pu8PointerToNextChar);
void LCD_voidSendNum(s32 num);
u8 LCD_u8SetPos(u8 Copy_u8Line,u8 Copy_u8Position);
void LCD_voidClear();
u8 LCD_u8SendString_const(const u8 *Copy_pu8String);
#define LCD_u8_LINE1	0
#define LCD_u8_LINE2	1

#endif /* LCD_INTERFACE_H_ */