/*
 * Sensors.h
 *
 * Created: 6/24/2023 4:22:59 AM
 *  Author: Developer
 */ 


#ifndef SENSORS_H_
#define SENSORS_H_
#include "ADC.h"
#include "StdTypes.h"

#define POT_CH ADC0
#define LM35   ADC1
u16 POT_VoltRead(void);
u16 TEMP_Read(void);


#endif /* SENSORS_H_ */