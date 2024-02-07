/*
 * DIO_Interface.h
 *
 * Created: 6/15/2023 6:44:31 PM
 *  Author: Developer
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"

typedef enum{
	INPUT,
	OUTPUT,
	INPUT_PULLUP
	}DIO_PinStatus_type;
typedef enum{
	LOW=0,
	HIGH
	}DIO_VoltageStatus_type;
typedef enum{
	U_PA=0,U_PB,U_PC,U_PD
	}DIO_Port_type;   //U stands for User Defined
typedef enum{
	U_PINA0=0,U_PINA1,U_PINA2,U_PINA3,U_PINA4,U_PINA5,U_PINA6,U_PINA7,
	U_PINB0,U_PINB1,U_PINB2,U_PINB3,U_PINB4,U_PINB5,U_PINB6,U_PINB7,
	U_PINC0,U_PINC1,U_PINC2,U_PINC3,U_PINC4,U_PINC5,U_PINC6,U_PINC7,
	U_PIND0,U_PIND1,U_PIND2,U_PIND3,U_PIND4,U_PIND5,U_PIND6,U_PIND7,
	TOTAL_PINS=32
	}DIO_Pin_type;  //U stands for User Defined

/*********************** functions **************************/
void DIO_InitPin(DIO_Pin_type pin, DIO_PinStatus_type status);
void DIO_WritePin(DIO_Pin_type pin, DIO_VoltageStatus_type volt);
DIO_VoltageStatus_type DIO_ReadPin(DIO_Pin_type pin);
void DIO_TogglePin(DIO_Pin_type pin);
void DIO_WritePort(DIO_Port_type port,u8 data);
u8 DIO_ReadPort(DIO_Port_type port);

void DIO_Init(void);
extern const DIO_PinStatus_type PinsStatusArray[TOTAL_PINS];
#endif /* DIO_INTERFACE_H_ */