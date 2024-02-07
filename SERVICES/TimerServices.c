/*
 * TimerServices.c
 *
 * Created: 7/18/2023 10:51:12 PM
 *  Author: Developer
 */ 
#include "TimerServices.h"
#include "LCD.h"
static volatile u8 flag=0;
static u16 t2, t1, t3, c=0;
void PWM_Measure(u16* pfreq,u8* pduty)
{
	u16 Ton,Toff;
	TCNT1=0;
	Timer1_ICU_SetCallBack(Func_ICU);
	
	Timer1_InputCaptureEdge(RISING);
	
	Timer1_ICU_InterruptEnable();
	flag=0;
	while(flag<3);
	
	Ton = t2 - t1;
	Toff= t3 - t2;
	
	*pduty = ((u32)Ton*100)/((u32)Ton+Toff);
	*pfreq = (u32)1000000/((u32)Toff+Ton);
}
static void Func_ICU(void)
{
	if (flag==0)
	{
		t1=ICR1;
		Timer1_InputCaptureEdge(FALLING);
		flag=1;
	}
	else if (flag==1)
	{
		t2=ICR1;
		Timer1_InputCaptureEdge(RISING);
		flag=2;
	}
	else if (flag==2)
	{
		t3=ICR1;
		Timer1_ICU_InterruptDisable();
		flag=3;
	}
}
void PWM_Init(void)
{
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE, TIMER1_SCALER_8, OCRA_NON_INVERTING, OCRB_DISCONNECTED);
}
void PWM_Freq_KHZ(u16 freq)
{
	if (freq==0);
	else
	{
		u16 Ttotal = 1000/freq;
		if (Ttotal>=1)
		{
			ICR1 = Ttotal-1;
		} 
		else
		{
			ICR1 = 0;
		}
	}
}
void PWM_Freq_HZ(u16 freq)
{
	if (freq==0);
	else
	{
		u16 Ttotal = (u32)1000000/freq;
		if (Ttotal>=1)
		{
			ICR1 = Ttotal-1;
		}
		else
		{
			ICR1 = 0;
		}
	}
}
