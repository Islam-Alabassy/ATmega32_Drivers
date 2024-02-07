/*
 * UART_Services.c
 *
 * Created: 7/23/2023 10:17:37 PM
 *  Author: Developer
 */ 
#include "UART_Services.h"
static volatile u8 *pdata=0, *prec=0;
void UART_SendInt(u32 num)
{
	UART_Send((u8)num);
	UART_Send((u8)(num>>8));
	UART_Send((u8)(num>>16));
	UART_Send((u8)(num>>24));
	//another solution using pointer
	/*
	u8*pnum = &num;
	u8 i ;
	for (i=0;i<4;i++)
	{
		UART_Send(pnum[i]);
	}
	*/
}
u32 UART_ReceiveInt(void)
{
	u8 byte_1=UART_Receive();
	u8 byte_2=UART_Receive();
	u8 byte_3=UART_Receive();
	u8 byte_4=UART_Receive();
	u32 num = byte_1|((u32)byte_2<<8)|((u32)byte_3<<16)|((u32)byte_4<<24);
	return num;
}
void UART_SendString(u8*str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		UART_Send(str[i]);
	}
	UART_Send('#');
}
void UART_ReceiveString(u8*str)
{
	u8 i=0;
	str[i]=UART_Receive();
	while (str[i]!='#') 
	{
		i++;
		str[i]=UART_Receive();
	}
	str[i]=0; 
}
//Software protocol based on uart
//it send first the length of the string
//then it sends the string itself
//third it sends the sum of the string letters to help you check if the data is delivered safely
void UART_SendString_CS(u8*str)//CS stands for Check Sum
{
	u8 i;
	u16 sum=0;
	//count the length of the string and calculate the sum of the string letters
	for (i=0;i<str[i];i++)
	{
		sum+=str[i];
	}
	//send the length of the string
	UART_Send(i);
	//send the string
	for (i=0;str[i];i++) 
	{
		UART_Send(str[i]);
	}
	//send the sum of the string letters (2 bytes)
	UART_Send(sum);
	UART_Send(sum>>8);
	
}
u8 UART_ReceiveString_CS(u8*str)//CS stands for Check Sum
{
	u8 len,i,byte_1,byte_2;
	u16 sum=0,sum_rec;
	len = UART_Receive();
	for (i=0;i<len;i++)
	{
		str[i]=UART_Receive();
		sum+=str[i];
	}
	byte_1=UART_Receive();
	byte_2=UART_Receive();
	sum_rec=byte_1|((u16)byte_2<<8);
	
	if (sum==sum_rec)
	{
		return 1;
	} 
	else
	{
		return 0;
	}
}

/************************** functions using interrupt *********************/
void UART_SendString_Asynchronous(u8*str)
{
	pdata=str;
	UART_TX_SetCallBack(UART_TX_Func);
	UART_TX_InterruptEnable();
	UART_Send_NoBlock(pdata[0]);
}
void UART_ReceiveString_Asynchronous(u8*str)
{
	prec=str;
	UART_RX_SetCallBack(UART_RX_Func);
	UART_RX_InterruptEnable();
}
/**************************** static funtions ************/
static void UART_TX_Func(void)
{
	static u8 i = 1;
	if (pdata[i]!=0)
	{
		UART_Send_NoBlock(pdata[i]);
		i++;
	}
	else
	{
		i=1;
	}
}
static void UART_RX_Func(void)
{
	static u8 i =0;
	prec[i]=UART_Receive_NoBlock();
	if(prec[i]!='#')
	{
		i++;
	}
	else
	{
		prec[i]=0;
		i=0;
	}
}