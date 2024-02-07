/*
 * IIC.c
 *
 * Created: 8/10/2023 7:14:32 PM
 *  Author: Developer
 */ 
#include "IIC.h"
void I2C_Init(void)
{
	//TWI Initialization
	///Bit rate : 100 KHz
	TWBR = 32;
	//Two Wire Bus Slave address : 0x01
	//General call configuration : off
	TWAR=0x02;//0b00000010
	//TWI Interrupt : off
	CLEAR_BIT(TWCR,TWIE);
	//Generate Acknowledge Pulse : on
	SET_BIT(TWCR,TWEA);
	//scaler
	CLEAR_BIT(TWSR,TWPS0);
	CLEAR_BIT(TWSR,TWPS1);
}

void I2C_Start(void)
{
	//Send START condition
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	//Wait for TWINT Flag set. This indicates
	//that the START condition has been
	//transmitted
	while(!(TWCR & (1<<TWINT)));
	LCD_GoTo(1,0);
	LCD_WriteString("st");
}

void I2C_Stop(void)
{
	//Transmit STOP condition
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	// Wait until stop condition execution 
	 while(TWCR&(1<<TWSTO));	
}
void I2C_Write(u8 data)
{
	//Put data on TWI register
	TWDR = data;
	//Send data
	TWCR = (1<<TWINT) | (1<<TWEN);
	//Wait for TWINT flag set in TWCR register
	while (!(TWCR & (1<<TWINT)));
}
u8 I2C_ReadWithAck(void)
{
	//Enable Ack
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	//Wait for TWINT flag set in TWCR register
	while (!(TWCR & (1<<TWINT)));
	//read Data
	return TWDR;
}
u8 I2C_ReadWithNoAck(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN);
	//Wait for TWINT flag set in TWCR register
	while (!(TWCR & (1<<TWINT)));
	//read Data
	return TWDR;
}
u8 I2C_GetStatus(void)
{
	u8 status;
	status = TWSR & 0xF8;
	return status;
}
/* This function initiate the start condition and 
	send the address you want to talk with and the
	data you want to send (only 1 byte)*/

//Input Argument : the address of the slave , the data you want to send
//Return : returns the status of the event
u8 I2C_SendMaster(u8 address, u8 data)
{
	
	u8 status;
	
	I2C_Start();
	
	status = I2C_GetStatus();
	if (status != START)
	{
		return 0;//indicates that no start or line busy
	}
	I2C_Write((address<<1)|0);//7-bit address + 1-bit (read 1, write 0)
	status = I2C_GetStatus();
	if (status != MT_SLA_ACK)
	{
		return 1;//indicates that no address ack is received
	}
	I2C_Write(data);
	status = I2C_GetStatus();
	if (status != MT_DATA_ACK)
	{
		return 2;//indicates that no data ack is received
	}
	I2C_Stop();
	return 3;
}