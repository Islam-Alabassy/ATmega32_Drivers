/*
 * EEPROM.c
 *
 * Created: 7/29/2023 6:31:35 PM
 *  Author: Developer
 */ 
#include "EEPROM.h"
void EEPROM_Write(u16 address, u8 data)
{
	//Wait for completion of previous write
	//wait until write enable bit (EEWE) becomes zero
	while(READ_BIT(EECR,EEWE));//busy wait polling
	
	//Set up address and data registers
	EEAR = address;
	EEDR = data;
	
	//write logical one to EEMWE bit (Master Write Enable)
	SET_BIT(EECR,EEMWE);
	
	//Start EEPROM Write by setting logical one to EEWE(Write Enable)
	SET_BIT(EECR,EEWE);
}

u8 EEPROM_Read(u16 address)
{
	//Wait for completion of previous write
	//wait until write enable bit (EEWE) becomes zero
	while(READ_BIT(EECR,EEWE));//busy wait polling
	
	//Set up address register
	EEAR = address;
	
	//Start EEPROM read by writing EERE (Read Enable)
	SET_BIT(EECR,EERE);
	
	//Return data from data register
	return EEDR;
}