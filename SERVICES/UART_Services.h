/*
 * UART_Services.h
 *
 * Created: 7/23/2023 10:17:57 PM
 *  Author: Developer
 */ 


#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_
#include "UART.h"

void UART_SendInt(u32 num);
u32 UART_ReceiveInt(void);
void UART_SendString(u8*str);
void UART_SendString_CS(u8*str);//CS stands for Check Sum
u8 UART_ReceiveString_CS(u8*str);//CS stands for Check Sum
/**************************** static funtions ************/
static void UART_TX_Func(void);
static void UART_RX_Func(void);
/************************** functions using interrupt *********************/
void UART_SendString_Asynchronous(u8*str);
void UART_ReceiveString_Asynchronous(u8*str);
#endif /* UART_SERVICES_H_ */