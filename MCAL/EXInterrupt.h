/*
 * EXInterrupt.h
 *
 * Created: 7/1/2023 5:35:43 PM
 *  Author: Developer
 */ 


#ifndef EXINTERRUPT_H_
#define EXINTERRUPT_H_
#include "MemMap.h"
#include "StdTypes.h"
#include "Utils.h"

typedef enum{
	EXI_INT0=0,
	EXI_INT1,
	EXI_INT2
}ExInterruptSource_type;
typedef enum{
	LOW_LEVEL=0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
}TriggerEdge_type;
void EXI_Enable(ExInterruptSource_type interrupt);
void EXI_Disable(ExInterruptSource_type interrupt);
void EXI_TriggerEdge(ExInterruptSource_type interrupt, TriggerEdge_type edge);
void EXI_SetCallBack(ExInterruptSource_type interrupt, void (*pf_local)(void));
#endif /* EXINTERRUPT_H_ */