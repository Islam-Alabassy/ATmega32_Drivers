/*
 * DIO_Lcfg.c
 *
 * Created: 6/15/2023 6:44:53 PM
 *  Author: Developer
 */ 
#include "DIO_Interface.h"
const DIO_PinStatus_type PinsStatusArray[TOTAL_PINS]={
	INPUT,                 /*port A pin 0 | ADC0 */
	OUTPUT,          /*port A pin 1| ADC1 */
	OUTPUT,          /*port A pin 2| ADC2 */
	INPUT_PULLUP,          /*port A pin 3| ADC3 */
	OUTPUT,                /*port A pin 4| ADC4 */
	OUTPUT,                /*port A pin 5| ADC5 */
	OUTPUT,                /*port A pin 6| ADC6 */
	OUTPUT,                /*port A pin 7| ADC7 */
	INPUT_PULLUP,          /*port B pin 0 */
	INPUT_PULLUP,          /*port B pin 1 */
	INPUT_PULLUP,          /*port B pin 2 */
	OUTPUT,          /*port B pin 3 | OC0 */
	OUTPUT,                /*port B pin 4 */
	OUTPUT,                /*port B pin 5 */
	INPUT,          /*port B pin 6 */
	OUTPUT,          /*port B pin 7 */
	OUTPUT,          /*port C pin 0 */
	OUTPUT,          /*port C pin 1 */
	OUTPUT,          /*port C pin 2 */
	OUTPUT,          /*port C pin 3 */
	OUTPUT,          /*port C pin 4 */
	OUTPUT,          /*port C pin 5 */
	OUTPUT,          /*port C pin 6 */
	OUTPUT,          /*port C pin 7 */
	OUTPUT,          /*port D pin 0 */
	OUTPUT,          /*port D pin 1 */
	OUTPUT,          /*port D pin 2 */
	OUTPUT,          /*port D pin 3 */
	OUTPUT,          /*port D pin 4 */
	OUTPUT,          /*port D pin 5 */
	INPUT,           /*port D pin 6 | ICP */
	OUTPUT           /*port D pin 7 */
};