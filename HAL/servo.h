/*
 * servo.h
 *
 * Created: 7/18/2023 12:54:24 AM
 *  Author: Developer
 */ 


#ifndef SERVO_H_
#define SERVO_H_
#include "Timer.h"

#define SERVO_PIN OCR1A

void SERVO_Init(void);
void SERVO_SetPosition(u8 angle);


#endif /* SERVO_H_ */