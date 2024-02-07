/*
 * Ultrasonic.h
 *
 * Created: 7/19/2023 9:10:00 PM
 *  Author: Developer
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include "StdTypes.h"
#include "Timer.h"
#include "DIO_Interface.h"
#define F_CPU  8000000UL
#include <util/delay.h>

#define ULTRASONIC_PIN_1 U_PIND0
#define ULTRASONIC_PIN_2 U_PIND1
#define ULTRASONIC_PIN_3 U_PIND2
#define ULTRASONIC_PIN_4 U_PIND3
static void icu_func(void);
u16 ultrasonic_getDistance(DIO_Pin_type ultrasonic_pin);
#endif /* ULTRASONIC_H_ */