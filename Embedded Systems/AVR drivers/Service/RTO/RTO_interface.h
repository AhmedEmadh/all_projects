/*
 * RTO_interface.h
 *
 * Created: 7/6/2023 2:19:59 PM
 *  Author: Ahmed Emad Hassan
 */ 


#ifndef RTO_INTERFACE_H_
#define RTO_INTERFACE_H_

void RTO_voidInit(void);

u8 RTO_u8CreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicty, u16 Copy_u16FirstDelay, void (*Copy_pf)(void));



#endif /* RTO_INTERFACE_H_ */