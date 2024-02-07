/*
 * TimerServices.h
 *
 * Created: 7/18/2023 10:51:35 PM
 *  Author: Developer
 */ 


#ifndef TIMERSERVICES_H_
#define TIMERSERVICES_H_
#include "StdTypes.h"
#include "Timer.h"

void PWM_Measure(u16* pfreq,u8* pduty);
static void Func_ICU(void);
static void timer1_ovf(void);

void PWM_Init(void);
void PWM_Freq_KHZ(u16 freq);
void PWM_Freq_HZ(u16 freq);
#endif /* TIMERSERVICES_H_ */