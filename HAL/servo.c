/*
 * servo.c
 *
 * Created: 7/18/2023 12:54:12 AM
 *  Author: Developer
 */ 
#include "servo.h"
void SERVO_Init(void)
{
	ICR1=20000-1;
	SERVO_PIN=1000-1;
}
void SERVO_SetPosition(u8 angle)
{
	SERVO_PIN = ((u32)angle*1000)/180+1000-1;
}