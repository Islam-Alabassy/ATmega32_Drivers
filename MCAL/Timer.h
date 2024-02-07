/*
 * Timer.h
 *
 * Created: 10-Feb-21 4:12:18 PM
 *  Author: programmer
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"
typedef enum{
	TIMER0_STOP=0,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	EXTERNALT0_FALLINGEDGE,
	EXTERNALT0_RISINGEDGE
	}Timer0_Scaler_type;
typedef enum
{
	TIMER0_NORMAL_MODE=0,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE
	}Timer0_Mode_type;
typedef enum
{
	OC0_DISCONNECTED=0,
	OC0_TOGGLE,
	OC0_NON_INVERTING,
	OC0_INVERTING
	}OC0_Mode_type;

void Timer0_Init(Timer0_Mode_type mode, Timer0_Scaler_type scaler, OC0_Mode_type oc0_mode);
void Timer0_OVF_InterruptEnable(void);
void Timer0_OVF_InterruptDisable(void);
void Timer0_OC_InterruptEnable(void);
void Timer0_OC_InterruptDisable(void);
void Timer0_OVF_SetCallBack(void(*local_pf)(void));
void Timer0_OC_SetCallBack(void(*local_pf)(void));

/**********************************************TIMER1********************************************************/

typedef enum{
	TIMER1_STOP=0,
	TIMER1_SCALER_1,
	TIMER1_SCALER_8,
	TIMER1_SCALER_64,
	TIMER1_SCALER_256,
	TIMER1_SCALER_1024,
	EXTERNAL0_FALLING,
	EXTERNAL0_RISING
}Timer1Scaler_type;

typedef enum
{
	TIMER1_NORMAL_MODE=0,
	TIMER1_CTC_ICR_TOP_MODE,
	TIMER1_CTC_OCRA_TOP_MODE,
	TIMER1_FASTPWM_ICR_TOP_MODE,
	TIMER1_FASTPWM_OCRA_TOP_MODE

}Timer1Mode_type;

typedef enum
{
	OCRA_DISCONNECTED=0,
	OCRA_TOGGLE,
	OCRA_NON_INVERTING,
	OCRA_INVERTING

}OC1A_Mode_type;

typedef enum
{
	OCRB_DISCONNECTED=0,
	OCRB_TOGGLE,
	OCRB_NON_INVERTING,
	OCRB_INVERTING

}OC1B_Mode_type;


typedef enum{
	RISING,
	FALLING
}ICU_Edge_type;




void Timer1_InputCaptureEdge(ICU_Edge_type edge);
void Timer1_Init( Timer1Mode_type mode,Timer1Scaler_type scaler,OC1A_Mode_type oc1a_mode,OC1B_Mode_type oc1b_mode);

void Timer1_ICU_InterruptEnable(void);
void Timer1_ICU_InterruptDisable(void);
void Timer1_OVF_InterruptEnable(void);
void Timer1_OVF_InterruptDisable(void);
void Timer1_OCA_InterruptEnable(void);
void Timer1_OCA_InterruptDisable(void);
void Timer1_OCB_InterruptEnable(void);
void Timer1_OCB_InterruptDisable(void);
void Timer1_OVF_SetCallBack(void(*LocalFptr)(void));
void Timer1_OCA_SetCallBack(void(*LocalFptr)(void));
void Timer1_OCB_SetCallBack(void(*LocalFptr)(void));
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void));


#endif /* TIMER_H_ */