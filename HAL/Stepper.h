/*
 * Stepper.h
 *
 * Created: 6/17/2023 8:28:27 PM
 *  Author: Developer
 */ 


#ifndef STEPPER_H_
#define STEPPER_H_
#include "StdTypes.h"
#include "DIO_Interface.h"
#define F_CPU  8000000UL
#include <util/delay.h>

#define BI_POLAR  0
#define UNI_POLAR 1
/******************** STEPPER PINS CONFIG **************************/
//Motor type Configuration
#define MOTOR_TYPE UNI_POLAR
//Bipolar Stepper Configuration
#define  COIL1A  U_PINA0
#define  COIL1B	 U_PINA1
#define  COIL2A  U_PINA2
#define  COIL2B  U_PINA3

//Unipolar Stepper Configuration
#define  COIL1  U_PINA4
#define  COIL2	U_PINA5
#define  COIL3  U_PINA6
#define  COIL4  U_PINA7

//Speed Configuration
#define  DELAY  500
#define STEPS_PER_REV 512
/*******************************************************************/


void STEPPER_Bipolar_CW(void);
void STEPPER_Bipolar_CCW(void); 

void STEPPER_Unipolar_CW(void);
void STEPPER_Unipolar_CCW(void);
void STEPPER_Unipolar_CW_HalfStep(void);

void STEPPER_CW(u8 rev);
void STEPPER_CW_Angle(u16 angle);
#endif /* STEPPER_H_ */