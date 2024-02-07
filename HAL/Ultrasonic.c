/*
 * Ultrasonic.c
 *
 * Created: 7/19/2023 9:09:39 PM
 *  Author: Developer
 */ 
#include "Ultrasonic.h"
static volatile u8 flag=0;
u16 t1,t2,t;

u16 ultrasonic_getDistance(DIO_Pin_type ultrasonic_pin)
{
	DIO_WritePin(ultrasonic_pin,HIGH);
	_delay_us(10);
	DIO_WritePin(ultrasonic_pin,LOW);
	Timer1_ICU_SetCallBack(icu_func);
	Timer1_InputCaptureEdge(RISING);
	Timer1_ICU_InterruptEnable();
	TCNT1=0;
	while(flag<2);
	t=t2-t1;
	flag=0;
	
	return (t/58);
}
static void icu_func(void)
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
		Timer1_ICU_InterruptDisable();
		flag=2;
	}
}