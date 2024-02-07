/*
 * SPI.c
 *
 * Created: 8/1/2023 3:11:03 PM
 *  Author: Developer
 */ 
#include "SPI.h"
static void (*SPI_Fptr)(void) = NULLPTR;
void SPI_InitMaster(Clock_Polarity_type cpoltype, Clock_Phase_type cphatype, Clock_Scaler_type scaler)
{
	//Master
	SET_BIT(SPCR,MSTR); 
	//clock
	switch(scaler)
	{
		case SPI_SCALER_4:
		CLEAR_BIT(SPCR,SPR0);
		CLEAR_BIT(SPCR,SPR1);
		CLEAR_BIT(SPSR,SPI2X);
		break;
		case SPI_SCALER_16:
		SET_BIT(SPCR,SPR0);
		CLEAR_BIT(SPCR,SPR1);
		CLEAR_BIT(SPSR,SPI2X);
		break;
		case SPI_SCALER_64:
		CLEAR_BIT(SPCR,SPR0);
		SET_BIT(SPCR,SPR1);
		CLEAR_BIT(SPSR,SPI2X);
		break;
		case  SPI_SCALER_128:
		SET_BIT(SPCR,SPR0);
		SET_BIT(SPCR,SPR1);
		CLEAR_BIT(SPSR,SPI2X);
		break; 
		case SPI_SCALER_2:
		CLEAR_BIT(SPCR,SPR0);
		CLEAR_BIT(SPCR,SPR1);
		SET_BIT(SPSR,SPI2X);
		break;
		case SPI_SCALER_8:
		SET_BIT(SPCR,SPR0);
		CLEAR_BIT(SPCR,SPR1);
		SET_BIT(SPSR,SPI2X);
		break;
		case SPI_SCALER_32:
		CLEAR_BIT(SPCR,SPR0);
		SET_BIT(SPCR,SPR1);
		SET_BIT(SPSR,SPI2X);
		break;
	}
	//polarity
	switch(cpoltype)
	{
		case LEADING_EDGE_RISING:
		CLEAR_BIT(SPCR,CPOL);
		break;
		case LEADING_EDGE_FALLING:
		SET_BIT(SPCR,CPOL);
		break;
	}
	//phase
	switch(cphatype)
	{
		case SAMPLE_AT_LEADING_EDGE:
		CLEAR_BIT(SPCR,CPHA);
		break;
		case SETUP_AT_LEADING_EDGE:
		SET_BIT(SPCR,CPHA);
		break;
	}
	//Enable
	SET_BIT(SPCR,SPE);
}
void SPI_InitSlave(Clock_Phase_type cphatype)
{
	//Slave
	CLEAR_BIT(SPCR,MSTR);
	//phase
	switch(cphatype)
	{
		case SAMPLE_AT_LEADING_EDGE:
		CLEAR_BIT(SPCR,CPHA);
		break;
		case SETUP_AT_LEADING_EDGE:
		SET_BIT(SPCR,CPHA);
		break;
	}
	//Enable
	SET_BIT(SPCR,SPE);
}
//if the MCU is master it is okay
//if the MCU is a slave the function will stuck until the master send data
u8 SPI_SendReceive(u8 data)
{
	//put data in the buffer
	SPDR = data;
	//wait until finishing communication
	while(!READ_BIT(SPSR,SPIF));
	//return the received data
	return SPDR;
}

//Functions to use in slave mode
void SPI_SendNoBlock(u8 data)
{
	SPDR = data;
}

//to use with interrupt
u8 SPI_ReceiveNoBlock(void)
{
	return SPDR;
}

//to use with periodic checking polling
u8 SPI_ReceivePeriodicChecking(u8 *pdata)
{
	if (READ_BIT(SPSR,SPIF))
	{
		*pdata = SPDR;
		return 1;
	}
	else
	return 0;
}

void SPI_InterruptEnable(void)
{
	SET_BIT(SPCR,SPIE);
}
void SPI_InterruptDisable(void)
{
	CLEAR_BIT(SPCR,SPIE);
}
void SPI_InterruptSetCallBack(void(*LocalFptr)(void))
{
	SPI_Fptr=LocalFptr;
}

/***************************** ISR *************************************/
ISR(SPI_STC_vect)
{
	if(SPI_Fptr!=NULLPTR)SPI_Fptr();
}