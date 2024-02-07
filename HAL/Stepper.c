/*
 * Stepper.c
 *
 * Created: 6/17/2023 8:28:15 PM
 *  Author: Developer
 */ 
#include "Stepper.h"
#if(MOTOR_TYPE==BI_POLAR)
void STEPPER_Bipolar_CW(void)
{
	DIO_WritePin(COIL1A,HIGH);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGH);
	_delay_ms(DELAY);
}
#elif(MOTOR_TYPE==UNI_POLAR)
void STEPPER_Unipolar_CW(void)
{
	DIO_WritePin(COIL1,HIGH);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL4,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1,LOW);
	DIO_WritePin(COIL2,HIGH);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL4,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1,LOW);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL3,HIGH);
	DIO_WritePin(COIL4,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1,LOW);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL4,HIGH);
	_delay_ms(DELAY);
}
void STEPPER_Unipolar_CW_HalfStep(void)
{
	DIO_WritePin(COIL1,HIGH);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL4,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1,HIGH);
	DIO_WritePin(COIL2,HIGH);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL4,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1,LOW);
	DIO_WritePin(COIL2,HIGH);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL4,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1,LOW);
	DIO_WritePin(COIL2,HIGH);
	DIO_WritePin(COIL3,HIGH);
	DIO_WritePin(COIL4,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1,LOW);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL3,HIGH);
	DIO_WritePin(COIL4,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1,LOW);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL3,HIGH);
	DIO_WritePin(COIL4,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1,LOW);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL4,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1,HIGH);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL4,HIGH);
	_delay_ms(DELAY);
}
void STEPPER_Unipolar_CCW(void)
{
	DIO_WritePin(COIL1,LOW);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL4,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1,LOW);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL3,HIGH);
	DIO_WritePin(COIL4,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1,LOW);
	DIO_WritePin(COIL2,HIGH);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL4,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1,HIGH);
	DIO_WritePin(COIL2,LOW);
	DIO_WritePin(COIL3,LOW);
	DIO_WritePin(COIL4,LOW);
	_delay_ms(DELAY);
}
void STEPPER_CW(u8 rev)
{
	u32 i,n = rev*STEPS_PER_REV;
	for (i=0;i<n;i++)
	{
		STEPPER_Unipolar_CW();
	}
}
void STEPPER_CW_Angle(u16 angle)
{
	u32 i, n = (angle*512)/360;
	for (i=0;i<n;i++)
	{
		STEPPER_Unipolar_CW();
	}
}
#endif