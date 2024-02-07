/*
 * EEPROM.h
 *
 * Created: 7/29/2023 6:31:14 PM
 *  Author: Developer
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"

void EEPROM_Write(u16 address, u8 data);
u8 EEPROM_Read(u16 address);
#endif /* EEPROM_H_ */