/*
 * ADC.c
 *
 * Created: 6/22/2023 8:38:13 PM
 *  Author: Developer
 */ 
#include "ADC.h"
static u8 read_flag= 0;
void ADC_Init(ADC_VREF_type vref, ADC_SCALER_type scaler)
{
	//VREF
	switch(vref)
	{
		case VREF_AVCC:
		SET_BIT(ADMUX,REFS0);
		CLEAR_BIT(ADMUX,REFS1);
		break;
		case VREF_AREF:
		CLEAR_BIT(ADMUX,REFS0);
		CLEAR_BIT(ADMUX,REFS1);
		break;
		case VREF_256:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
	}
	//read adjust right
	CLEAR_BIT(ADMUX,ADLAR);
	//CLOCK
	ADCSRA = ADCSRA & 0xf8; //0b11111000 => clear the first three bits to set the scaler
	scaler = scaler & 0x07; //to confirm that the scaler has only three bits
	ADCSRA = ADCSRA | scaler;//setting the scaler in the register
}
void ADC_Enable(void)
{
	SET_BIT(ADCSRA,ADEN);
}
void ADC_Disable(void)
{
	CLEAR_BIT(ADCSRA,ADEN);
}
u16 ADC_Read(ADC_Channel_type ch)
{
	//Select channel
	ADMUX = ADMUX & 0xe0;//0b11100000  => clear the first five bits to select the channel
	ch = ch & 0x1f;//to confirm that the channel has only five bits
	ADMUX = ADMUX | ch;
	//start conversion
	SET_BIT(ADCSRA,ADSC);
	//polling(busy wait) until the ADC end conversion
	while(READ_BIT(ADCSRA,ADSC));
	//return the value
	//another option to get the value
	//u16 adc_value = ADCL | ((u16)ADCH<<8);
	return ADC_VALUE;//this option to get the value using memory mapping
}

//Dividing the reading process into two steps to use the conversion time in another process 
void ADC_StartConversion(ADC_Channel_type ch)
{
	if (read_flag == 0)
	{
		//Select channel
		ADMUX = ADMUX & 0xe0;//0b11100000  => clear the first five bits to select the channel
		ch = ch & 0x1f;//to confirm that the channel has only five bits
		ADMUX = ADMUX | ch;
		//start conversion
		SET_BIT(ADCSRA,ADSC);
		read_flag = 1;
	}
	
}
//first way to polling the remaining time 
u16 ADC_GetRead(void)
{
	//polling(busy wait) until the ADC end conversion
	while(READ_BIT(ADCSRA,ADSC));
	//return the value
	//another option to get the value
	//u16 adc_value = ADCL | ((u16)ADCH<<8);
	read_flag = 0;
	return ADC_VALUE;//this option to get the value using memory mapping
}
//polling(periodic check)
u8 ADC_GetReadPeriodicCheck(u16 *pdata)
{
	if (READ_BIT(ADCSRA,ADSC)==0)
	{
		*pdata = ADC_VALUE;
		read_flag = 0;
		return 1;
	}
	
	return 0;
}
