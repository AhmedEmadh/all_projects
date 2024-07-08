/*
 * KPD_interface.h
 *
 * Created: 7/14/2023 2:01:28 AM
 *  Author: Ahmed Emad Hassan
 */ 


#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

#define  KPD_u8_Key_Not_Pressed		0xff

u8 KPD_u8GetKeyStatus(u8 * Copy_pu8Returnedkey);


#endif /* KPD_INTERFACE_H_ */