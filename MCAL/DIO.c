/*
 * DIO.c
 *
 * Created: 6/15/2023 6:44:08 PM
 *  Author: Developer
 */ 
#include "DIO_Interface.h"
void DIO_InitPin(DIO_Pin_type pin, DIO_PinStatus_type status)
{
	DIO_Port_type port = pin/8;
	u8 pin_num = pin%8;
	switch(status)
	{
		case INPUT:
		switch(port)
		{
			case U_PA:
			CLEAR_BIT(DDRA,pin_num);
			break;
			case U_PB:
			CLEAR_BIT(DDRB,pin_num);
			break;
			case U_PC:
			CLEAR_BIT(DDRC,pin_num);
			break;
			case U_PD:
			CLEAR_BIT(DDRD,pin_num);
			break;
		}
		break;
		case OUTPUT:
		switch(port)
		{
			case U_PA:
			SET_BIT(DDRA,pin_num);
			break;
			case U_PB:
			SET_BIT(DDRB,pin_num);
			break;
			case U_PC:
			SET_BIT(DDRC,pin_num);
			break;
			case U_PD:
			SET_BIT(DDRD,pin_num);
			break;
		}
		break;
		case  INPUT_PULLUP:
		switch(port)
		{
			case U_PA:
			CLEAR_BIT(DDRA,pin_num);
			SET_BIT(PORTA,pin_num);
			break;
			case U_PB:
			CLEAR_BIT(DDRB,pin_num);
			SET_BIT(PORTB,pin_num);
			break;
			case U_PC:
			CLEAR_BIT(DDRC,pin_num);
			SET_BIT(PORTC,pin_num);
			break;
			case U_PD:
			CLEAR_BIT(DDRD,pin_num);
			SET_BIT(PORTD,pin_num);
			break;
		}
		break;
	}
}

void DIO_WritePin(DIO_Pin_type pin, DIO_VoltageStatus_type volt)
{
	DIO_Port_type port = pin/8;
	u8 pin_num = pin%8;
	switch(volt)
	{
		case HIGH:
		switch(port)
		{
			case U_PA:
			SET_BIT(PORTA,pin_num);
			break;
			case U_PB:
			SET_BIT(PORTB,pin_num);
			break;
			case U_PC:
			SET_BIT(PORTC,pin_num);
			break;
			case U_PD:
			SET_BIT(PORTD,pin_num);
			break;
		}
		break;
		case LOW:
		switch(port)
		{
			case U_PA:
			CLEAR_BIT(PORTA,pin_num);
			break;
			case U_PB:
			CLEAR_BIT(PORTB,pin_num);
			break;
			case U_PC:
			CLEAR_BIT(PORTC,pin_num);
			break;
			case U_PD:
			CLEAR_BIT(PORTD,pin_num);
			break;
		}
		break;
	}
}
DIO_VoltageStatus_type DIO_ReadPin(DIO_Pin_type pin)
{
	DIO_Port_type port = pin/8;
	u8 pin_num = pin%8;
	DIO_VoltageStatus_type volt;
	switch(port)
	{
		case U_PA:
		volt=READ_BIT(PINA,pin_num);
		break;
		case U_PB:
		volt=READ_BIT(PINB,pin_num);
		break;
		case U_PC:
		volt=READ_BIT(PINC,pin_num);
		break;
		case U_PD:
		volt=READ_BIT(PIND,pin_num);
		break;
	}
	return volt;
}

void DIO_WritePort(DIO_Port_type port,u8 data)
{
	switch(port)
	{
		case U_PA:
		PORTA = data;
		break;
		case U_PB:
		PORTB = data;
		break;
		case U_PC:
		PORTC = data;
		break;
		case U_PD:
		PORTD = data;
		break;
	}
}

u8 DIO_ReadPort(DIO_Port_type port)
{
	u8 data;
	switch(port)
	{
		case U_PA:
		data = PINA;
		break;
		case U_PB:
		data = PINB;
		break;
		case U_PC:
		data = PINC;
		break;
		case U_PD:
		data = PIND;
		break;
	}
	return data;
}
void DIO_TogglePin(DIO_Pin_type pin)
{
	DIO_Port_type port = pin/8;
	u8 pin_num = pin%8;
	switch(port)
	{
		case U_PA:
		TOGGLE_BIT(PORTA,pin_num);
		break;
		case U_PB:
		TOGGLE_BIT(PORTB,pin_num);
		break;
		case U_PC:
		TOGGLE_BIT(PORTC,pin_num);
		break;
		case U_PD:
		TOGGLE_BIT(PORTD,pin_num);
		break;
	}
}

void DIO_Init(void)
{
	DIO_Pin_type i;
	for(i=U_PINA0;i<TOTAL_PINS;i++)
	{
		DIO_InitPin(i,PinsStatusArray[i]);
	}
}