/*
 * Timer.c
 *
 * Created: 7/8/2023 8:09:19 PM
 *  Author: Developer
 */ 

#include "Timer.h"
static void (*TIMER0_OVF_Fptr) (void)=NULLPTR;
static void (*TIMER0_OC_Fptr)  (void)=NULLPTR;
static void (*Timer1_OVF_Fptr) (void)=NULLPTR;
static void (*Timer1_OCA_Fptr) (void)=NULLPTR;
static void (*Timer1_OCB_Fptr) (void)=NULLPTR;
static void (*Timer1_ICU_Fptr) (void)=NULLPTR;

void Timer0_Init(Timer0_Mode_type mode, Timer0_Scaler_type scaler, OC0_Mode_type oc0_mode)
{
	//Selecting the mode
	switch(mode)
	{
		case TIMER0_NORMAL_MODE:
		CLEAR_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		break;
		case TIMER0_PHASECORRECT_MODE:
		SET_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		break;
		case TIMER0_CTC_MODE:
		CLEAR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
		case TIMER0_FASTPWM_MODE:
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
	}
	//Selecting the clock
	TCCR0 &= 0xf8;
	scaler &= 0x07;
	TCCR0 |= scaler;
	//Selecting the status of Output Compare Pin Mode
	switch(oc0_mode)
	{
		case OC0_DISCONNECTED:
		CLEAR_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		break;
		case OC0_TOGGLE:
		SET_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		break;
		case OC0_NON_INVERTING:
		CLEAR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
		case OC0_INVERTING:
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
	}
}
void Timer0_OVF_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE0);
}
void Timer0_OVF_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TOIE0);
}
void Timer0_OVF_SetCallBack(void(*local_pf)(void))
{
	TIMER0_OVF_Fptr=local_pf;
}
void Timer0_OC_SetCallBack(void(*local_pf)(void))
{
	TIMER0_OC_Fptr=local_pf;
}
ISR(TIMER0_OVF_vect)
{
	if(TIMER0_OVF_Fptr!=NULLPTR)TIMER0_OVF_Fptr();
}
ISR(TIMER0_OC_vect)
{
	if(TIMER0_OC_Fptr!=NULLPTR)TIMER0_OC_Fptr();
}
/*********************************Timer 1 Call Back functions*****************************************/

void Timer1_OVF_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OVF_Fptr=LocalFptr;
}
void Timer1_OCA_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCA_Fptr=LocalFptr;
}
void Timer1_OCB_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCB_Fptr=LocalFptr;
}
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_ICU_Fptr=LocalFptr;
}
/****************************************Timer 1 **********************************************/

void Timer1_Init( Timer1Mode_type mode,Timer1Scaler_type scaler,OC1A_Mode_type oc1a_mode,OC1B_Mode_type oc1b_mode)

{
	switch (mode)
	{
		case TIMER1_NORMAL_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_CTC_ICR_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_CTC_OCRA_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_FASTPWM_ICR_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_FASTPWM_OCRA_TOP_MODE:
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
	}
	switch (oc1a_mode)
	{
		case OCRA_DISCONNECTED:
		CLEAR_BIT(TCCR1A,COM1A0);
		CLEAR_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_TOGGLE:
		SET_BIT(TCCR1A,COM1A0);
		CLEAR_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_NON_INVERTING:
		CLEAR_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_INVERTING:
		SET_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
	}
	switch (oc1b_mode)
	{
		case OCRB_DISCONNECTED:
		CLEAR_BIT(TCCR1A,COM1B0);
		CLEAR_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_TOGGLE:
		SET_BIT(TCCR1A,COM1B0);
		CLEAR_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_NON_INVERTING:
		CLEAR_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_INVERTING:
		SET_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
	}
	
	
	TCCR1B&=0XF8;
	TCCR1B|=scaler;

}

void Timer1_InputCaptureEdge(ICU_Edge_type edge)
{
	if(edge==RISING)
	SET_BIT(TCCR1B,ICES1);
	
	else if(edge==FALLING)
	CLEAR_BIT(TCCR1B,ICES1);

}
/****************************Timer 1 Interrupt functions**************************************/

void Timer1_ICU_InterruptEnable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
void Timer1_ICU_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TICIE1);
}
void Timer1_OVF_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE1);
}
void Timer1_OVF_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TOIE1);
}
void Timer1_OCA_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1A);
}
void Timer1_OCA_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE1A);
}
void Timer1_OCB_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1B);
}
void Timer1_OCB_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE1B);
}


/*********************************Timer 1 ISR functions*********************************************/
ISR(TIMER1_OVF_vect)
{
	if(Timer1_OVF_Fptr!=0)
	{
		Timer1_OVF_Fptr();
	}
}
ISR(TIMER1_OCA_vect)
{
	if(Timer1_OCA_Fptr!=0)
	{
		Timer1_OCA_Fptr();
	}
}
ISR(TIMER1_OCB_vect)
{
	if(Timer1_OCB_Fptr!=0)
	{
		Timer1_OCB_Fptr();
	}
}
ISR(TIMER1_ICU_vect)
{
	if(Timer1_ICU_Fptr!=0)
	{
		Timer1_ICU_Fptr();
	}
}