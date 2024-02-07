/*
 * KeyPad.h
 *
 * Created: 6/20/2023 7:09:33 PM
 *  Author: Developer
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "DIO_Interface.h"
#include "StdTypes.h"

/*************************** Config ******************************/
#define FIRST_IN  U_PINB0
#define FIRST_OUT U_PINB4
#define ROWS 4
#define COL 4
#define DEFAULT_KEY '$'


/************************** Functions ***************************/
u8 KEYPAD_GetCharacter(void);



#endif /* KEYPAD_H_ */