/*
 * UART.c
 *
 * Created: 7/23/2023 6:01:45 PM
 *  Author: Developer
 */ 
#include "UART.h"
static void (*UART_RX_Fptr) (void)=NULLPTR;
static void (*UART_TX_Fptr) (void)=NULLPTR;

void UART_Init(void)
{
	
	//baud rate 9600
	UBRRL=51;
	//enable trans,receiver
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
}
void UART_Send(u8 data)
{
	while(!READ_BIT(UCSRA,UDRE));//busy wait polling
	UDR=data;
}
u8 UART_Receive(void)
{
	while(!READ_BIT(UCSRA,RXC));//busy wait polling
	return UDR;
}
u8 UART_ReceiveNoBlock(u8*pdata)
{
	if(READ_BIT(UCSRA,RXC))//periodic check polling
	{
		*pdata = UDR;
		return 1;
	}
	else
	return 0;
}

//Functions to use with the interrupt
void UART_Send_NoBlock(u8 data)
{
	UDR=data;
}
u8 UART_Receive_NoBlock(void)
{
	return UDR;
}
/****************************** Inerrupt Functions ********************/
void UART_RX_InterruptEnable(void)
{
	SET_BIT(UCSRB,RXCIE);
}
void UART_RX_InterruptDisable(void)
{
	CLEAR_BIT(UCSRB,RXCIE);
}
void UART_TX_InterruptEnable(void)
{
	SET_BIT(UCSRB,TXCIE);
}
void UART_TX_InterruptDisable(void)
{
	CLEAR_BIT(UCSRB,TXCIE);
}
/******************************* set callback functions ****************/
void UART_RX_SetCallBack(void(*LocalFptr)(void))
{
	UART_RX_Fptr = LocalFptr;
}
void UART_TX_SetCallBack(void(*LocalFptr)(void))
{
	UART_TX_Fptr = LocalFptr;
}
/***************************** ISR *************************************/
ISR(UART_RX_vect)
{
	if(UART_RX_Fptr!=NULLPTR)UART_RX_Fptr();
}
ISR(UART_TX_vect)
{
	if(UART_TX_Fptr!=NULLPTR)UART_TX_Fptr();
}
