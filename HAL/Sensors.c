/*
 * Sensors.c
 *
 * Created: 6/24/2023 4:23:17 AM
 *  Author: Developer
 */ 
#include "Sensors.h"
u16 POT_VoltRead(void)
{
	u16 adc = ADC_Read(POT_CH);
	u16 volt = ((u32)5000*adc)/1024;//5000 millivolt
	return volt;//return in (milliVolt)
}
u16 TEMP_Read(void)
{
	u16 adc = ADC_Read(LM35);
	u16 volt = ((u32)5000*adc)/1024;//5000 millivolt
	u16 temp = volt;
	return temp;//returns temp*10
}