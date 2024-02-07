/*
 * WDT.h
 *
 * Created: 8/14/2023 7:53:11 PM
 *  Author: Developer
 */ 


#ifndef WDT_H_
#define WDT_H_
#include "MemMap.h"
#include "Utils.h"
#include "StdTypes.h"

typedef enum{
	timeout_16ms=0,
	timeout_32ms,
	timeout_65ms,
	timeout_130ms,
	timeout_260ms,
	timeout_520ms,
	timeout_1000ms,
	timeout_2100ms,
	}Timeout_type;
void WDT_SetAndStart(Timeout_type time);
void WDT_Stop(void);

#endif /* WDT_H_ */