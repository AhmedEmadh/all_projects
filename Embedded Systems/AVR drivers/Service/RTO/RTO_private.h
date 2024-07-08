/*
 * RTO_private.h
 *
 * Created: 7/6/2023 2:20:19 PM
 *  Author: Ahmed Emad Hassan
 */ 


#ifndef RTO_PRIVATE_H_
#define RTO_PRIVATE_H_

typedef struct {
	u16 FirstDelay;
	u16 periodicity;
	void(*pf)(void);
	
} RTO_TCB;

static void RTO_voidScheduler(void);

#endif /* RTO_PRIVATE_H_ */