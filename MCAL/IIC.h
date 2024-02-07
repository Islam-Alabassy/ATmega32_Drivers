/*
 * IIC.h
 *
 * Created: 8/10/2023 7:14:19 PM
 *  Author: Developer
 */ 


#ifndef IIC_H_
#define IIC_H_
#include "MemMap.h"
#include "StdTypes.h"
#include "Utils.h"
#include "LCD.h"
#define START 0x08
#define REPEATED_START 0x10
#define MT_SLA_ACK 0x18
#define MT_DATA_ACK 0x28
void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write(u8 data);
u8 I2C_ReadWithAck(void);
u8 I2C_ReadWithNoAck(void);
u8 I2C_GetStatus(void);
u8 I2C_SendMaster(u8 address, u8 data);
#endif /* IIC_H_ */