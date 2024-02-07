/*
 * ADC.h
 *
 * Created: 6/22/2023 8:38:24 PM
 *  Author: Developer
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "Utils.h"
#include "StdTypes.h"
#include "MemMap.h"

typedef enum{
	VREF_AVCC,
	VREF_AREF,
	VREF_256
	}ADC_VREF_type;
typedef enum{
	ADC_SCALER_2=1,
	ADC_SCALER_4,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128
	}ADC_SCALER_type;
typedef enum{
	ADC0=0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
	}ADC_Channel_type;
void ADC_Init(ADC_VREF_type vref, ADC_SCALER_type scaler);
void ADC_Enable(void);
void ADC_Disable(void);
u16 ADC_Read(ADC_Channel_type ch);
//Dividing the reading process into two steps to use the conversion time in another process
void ADC_StartConversion(ADC_Channel_type ch);
u16 ADC_GetRead(void);
u8 ADC_GetReadPeriodicCheck(u16 *pdata);
#endif /* ADC_H_ */