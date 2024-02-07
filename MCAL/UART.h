/*
 * UART.h
 *
 * Created: 7/23/2023 6:02:02 PM
 *  Author: Developer
 */ 


#ifndef UART_H_
#define UART_H_
#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"

void UART_Init(void);
void UART_Send(u8 data);
u8 UART_Receive(void);
u8 UART_ReceiveNoBlock(u8*pdata);

void UART_Send_NoBlock(u8 data);
u8 UART_Receive_NoBlock(void);
/****************************** Inerrupt Functions ********************/
void UART_RX_InterruptEnable(void);
void UART_RX_InterruptDisable(void);
void UART_TX_InterruptEnable(void);
void UART_TX_InterruptDisable(void);
/******************************* set callback functions ****************/
void UART_RX_SetCallBack(void(*LocalFptr)(void));
void UART_TX_SetCallBack(void(*LocalFptr)(void));
#endif /* UART_H_ */