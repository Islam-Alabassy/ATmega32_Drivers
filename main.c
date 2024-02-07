/*
 * MyDrivers.c
 *
 * Created: 6/9/2023 4:12:35 PM
 * Author : Developer
 */ 


#define F_CPU  8000000UL
#include <util/delay.h>
#include "MemMap.h"
#include "StdTypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "Stepper.h"
#include "LCD.h"
#include "KeyPad.h"
#include "ADC.h"
#include "Sensors.h"
#include "EXInterrupt.h"
#include "Timer.h"
#include "servo.h"
#include "TimerServices.h"
#include "Ultrasonic.h"
#include "UART.h"
#include "UART_Services.h"
#include "EEPROM.h"
#include "UART_Stack.h"
#include "SPI.h"
#include "IIC.h"
#include "WDT.h"
// Common Cathode Configuration
unsigned char lookup[10] = {
	0x3f, 0x06, 0x5b, 0x4f, 0x66,
	0x6d, 0x7d, 0x07, 0x7f, 0x6f
};

//Buttons Config
#define UP		U_PINA0
#define DOWN	U_PINA1
#define LEFT	U_PINA2
#define RIGHT	U_PINA3


void segment_display(unsigned char number);
void timer_fun(void);
void timer_pwm(void);



int main(void)
{
	sei();
	
   	 DIO_Init();
	LCD_Init();
	UART_Init();
	ADC_Init(VREF_AVCC, ADC_SCALER_64);
	Timer0_Init(TIMER0_FASTPWM_MODE, TIMER0_SCALER_8, OC0_NON_INVERTING);
	Timer1_Init(TIMER1_NORMAL_MODE, TIMER1_SCALER_8, OCRA_DISCONNECTED, OCRB_DISCONNECTED);
	u8 str[100];
	//UART_SendString_Asynchronous(str);
	//UART_ReceiveString_Asynchronous(str);
	//EEPROM_Write(0,200);
	//u8 x = EEPROM_Read(0);
	LCD_GoTo(0,0);
	LCD_WriteString("system ready");
	_delay_ms(500);
	I2C_Init();
	//WDT_SetAndStart(timeout_1000ms);
	u8 s = I2C_SendMaster(0b00000100,'A');
	//WDT_Stop();
	if(s==3)
	{
		LCD_GoTo(0,0);
		LCD_WriteString("I2C done");
	}
	else if (s==0)
	{
		LCD_GoTo(0,0);
		LCD_WriteString("Bus busy");
	} else if (s==1)
	{
		LCD_GoTo(0,0);
		LCD_WriteString("no address ack");
	}
	else if (s==2)
	{
		LCD_GoTo(0,0);
		LCD_WriteString("no data ack");
	}
	SPI_InitMaster(LEADING_EDGE_RISING, SAMPLE_AT_LEADING_EDGE, SPI_SCALER_4);
	u8 y = 'a';
    while (1) 
    {
		SPI_SendReceive(y);
		y++;
		_delay_ms(1000);
	}		
}

//Timer in normal mode
//Create PWM 1kHz and Duty cycle 20%
void timer_pwm(void)
{
	static u16 c=0;
	c++;
	TCNT0 = 56;
	if (c==4)
	{
		DIO_WritePin(U_PINA5,HIGH);
	}
	if (c==5)
	{
		DIO_WritePin(U_PINA5,LOW);
		c=0;
	}
}

