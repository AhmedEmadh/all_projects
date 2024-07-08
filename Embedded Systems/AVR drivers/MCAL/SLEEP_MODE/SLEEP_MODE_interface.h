/*
 * SLEEP_MODE_interface.h
 *
 * Created: 6/15/2023 5:09:40 PM
 *  Author: Ahmed Emad Hassan
 */ 


#ifndef SLEEP_MODE_INTERFACE_H_
#define SLEEP_MODE_INTERFACE_H_


#define SLEEP_MODE_u8_IDLE_MODE						0
#define SLEEP_MODE_u8_ADC_NOISE_REDUCTION_MODE		1
#define SLEEP_MODE_u8_POWER_DOWN_MODE				2
#define SLEEP_MODE_u8_POWER_SAVE_MODE				3
#define SLEEP_MODE_u8_STANDBY_MODE					4
#define SLEEP_MODE_u8_EXTENDED_STANDBY_MODE			5
void SLEEP_MODE_voidEnable(void);
void SLEEP_MODE_voidDisable(void);
u8 SLEEP_MODE_u8SetMode(u8 copy_u8Mode);

#endif /* SLEEP_MODE_INTERFACE_H_ */