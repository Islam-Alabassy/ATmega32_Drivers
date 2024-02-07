/*
 * UART_Stack.h
 *
 * Created: 7/30/2023 8:06:10 PM
 *  Author: Developer
 */ 


#ifndef UART_STACK_H_
#define UART_STACK_H_
#include "StdTypes.h"
#define STACK_SIZE 100

typedef enum{
	STACK_FULL,
	STACK_EMPTY,
	DONE
	}StackStatus_type;
StackStatus_type push(u8 data);
StackStatus_type pop(u8 *pdata);
#endif /* UART_STACK_H_ */