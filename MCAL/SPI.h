/*
 * SPI.h
 *
 * Created: 8/1/2023 3:11:14 PM
 *  Author: Developer
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"

typedef enum{
	LEADING_EDGE_RISING=0,
	LEADING_EDGE_FALLING
	}Clock_Polarity_type;
typedef enum{
	SAMPLE_AT_LEADING_EDGE=0,
	SETUP_AT_LEADING_EDGE
	}Clock_Phase_type;
typedef enum{
	SPI_SCALER_4=0,
	SPI_SCALER_16,
	SPI_SCALER_64,
	SPI_SCALER_128,
	SPI_SCALER_2,
	SPI_SCALER_8,
	SPI_SCALER_32
	}Clock_Scaler_type;
void SPI_InitMaster(Clock_Polarity_type cpoltype, Clock_Phase_type cphatype, Clock_Scaler_type scaler);
void SPI_InitSlave(Clock_Phase_type cphatype);
u8 SPI_SendReceive(u8 data);

//Functions to use in slave mode
void SPI_SendNoBlock(u8 data);
//to use with interrupt
u8 SPI_ReceiveNoBlock(void);
//to use with periodic checking polling
u8 SPI_ReceivePeriodicChecking(u8 *pdata);

void SPI_InterruptEnable(void);
void SPI_InterruptDisable(void);
void SPI_InterruptSetCallBack(void(*LocalFptr)(void));
#endif /* SPI_H_ */