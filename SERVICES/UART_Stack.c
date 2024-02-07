/*
 * UART_Stack.c
 *
 * Created: 7/30/2023 8:05:51 PM
 *  Author: Developer
 */ 
#include "UART_Stack.h"
static u8 stack[STACK_SIZE]={0};
static u8 sp=0;//stack pointer
StackStatus_type push(u8 data)
{
	if (sp==STACK_SIZE)
	{
		return STACK_FULL;
	}
	stack[sp]=data;
	sp++;
	return DONE;
}
StackStatus_type pop(u8 *pdata)
{
	if (sp==0)
	{
		return STACK_EMPTY;
	}
	sp--;
	*pdata=stack[sp];
	return DONE;
}