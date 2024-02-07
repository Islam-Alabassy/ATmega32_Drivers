/*
 * LCD.h
 *
 * Created: 6/18/2023 3:55:37 PM
 *  Author: Developer
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "StdTypes.h"
#include "DIO_Interface.h"
#include "Utils.h"
#define F_CPU 8000000UL
#include <util/delay.h>

/******************************** CONFIG ************************************/


#define _8_BIT 0
#define _4_BIT 1
#define LCD_MODE _4_BIT
//8_Bit Mode :
#define LCD_PORT  U_PD
#define FUNCTION_SET_8BIT 0x38
#define FUNCTION_SET_4BIT 0x28
#define DISPLAY_CONTROL 0x0c
#define DISPLAY_CLEAR 0X01
#define ENTRY_MODE_SET 0x06
//4_Bit Mode :
#define D4          U_PINC3
#define D5          U_PINC4
#define D6          U_PINC5
#define D7          U_PINC6

#define RS  U_PINA1
#define RW  U_PINA2
#define EN  U_PINC2
/***************************************************************************/

/******************************** FUNCTIONS ********************************/
void LCD_WriteData(u8 data);
void LCD_WriteCommand(u8 command);
void LCD_Init(void);
/********************************* SERVICES *******************************/
void LCD_WriteString(u8 str[]);
void LCD_WriteNumber(s64 num);
void LCD_Clear(void);
void LCD_GoTo(u8 y,u8 x);
void LCD_CreateCharacter(u8* pattern,u8 address);
void LCD_WriteChar(u8 ch);
void LCD_WriteNumberInBinary(u8 num);
void LCD_WriteNumber_4D(u16 num);
#endif /* LCD_H_ */