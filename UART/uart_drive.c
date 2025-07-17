#include "stm32f10x.h"                  // Device header
#include "uart_drive.h"
#include "gp_drive.h"
#include "systic_drive.h"

void UART_init(unsigned short uart, unsigned long BR)
{
	// If using UART1 clock speed 72MHz, else 36MHz
	// USART3 PB10, PB11 for TX,RX
	// USART2 PA2 , PA3 for TX,RX
	// USART1 PA9, PA10 for TX,RX
	
	//Enabling clock for Alternate function of GPIO pins
	unsigned long BRR_Cal;
	BRR_Cal = UART_BRR(uart,BR);
	
	RCC->APB2ENR |= 1;
	
	if(uart == 1)
	{
	__disable_irq();
	RCC->APB2ENR |= 0x4000;
	init_GP(PA,9,OUT50,O_AF_PP);
	init_GP(PA,10,IN,IN_PP);
	// Set up the baud rate 9600
	USART1->BRR |= BRR_Cal;
	USART1->CR1 |= 0x2000;
	USART1->CR1 |= 0x8;
	USART1->CR1 |= 0x4;
	USART1->CR1 |= 0x20;
	NVIC_EnableIRQ(USART1_IRQn);
	__enable_irq();	
	}
	else if(uart == 2)
	{
	__disable_irq();
	RCC->APB1ENR |= 0x20000;
	init_GP(PA,2,OUT50,O_AF_PP);
	init_GP(PA,3,IN,IN_PP);
	// Set up the baud rate 9600
	USART2->BRR |= BRR_Cal;
	USART2->CR1 |= 0x2000;
	USART2->CR1 |= 0x8;
	USART2->CR1 |= 0x4;
	USART2->CR1 |= 0x20;
	NVIC_EnableIRQ(USART2_IRQn);
	__enable_irq();	
	}
	else if(uart == 3)
	{
	__disable_irq();
	RCC->APB1ENR |= 0x40000;
	init_GP(PB,10,OUT50,O_AF_PP);
	init_GP(PB,11,IN,IN_PP);
	// Set up the baud rate 9600
	USART3->BRR |= BRR_Cal;
	USART3->CR1 |= 0x2000;
	USART3->CR1 |= 0x8;
	USART3->CR1 |= 0x4;
	USART3->CR1 |= 0x20;
	NVIC_EnableIRQ(USART3_IRQn);
	__enable_irq();	
	}
}

unsigned long UART_BRR(unsigned short uart, unsigned long BR)
{
	unsigned long div = 36000000;
	double frac = 36000000.00;
	unsigned long dec;
	double frac2 = 1.00;
	unsigned long final;
	
	if(uart == 1)     // for 72MHz uart1
	{
	 div = 72000000;
	 frac = 72000000.00;
	}
	div = div /(BR*16);                  // getting integer part
	frac =16 *((frac /(BR*16)) - div);     // getting fraction part
	dec = (unsigned long)frac;					 // getting integer part of frac
	frac2 = 100*(frac-dec);							 
	if(frac2>50)                         // for comparing ang getting the nearest real number
	{
		dec++;
		if(dec == 16)
		{
			dec = 0;
			div++;
		}
	}
	
	final =(div<<4);                     // mantissa position
	final += dec;
	
	return final;
}

char UART_RX(unsigned short uart)
{
	char c;
	if(uart == 1)
	{
		while((USART1->SR & 0x20) == 0x00)   //waiting until data is received
		{}
		c =(char)USART1->DR;
	}
	else if(uart == 2)
	{
		while((USART2->SR & 0x20) == 0x00)   //waiting until data is received
		{}
		c =(char)USART2->DR;
	}
	else if(uart == 3)
	{
		while((USART3->SR & 0x20) == 0x00)   //waiting until data is received
		{}
		c =(char)USART3->DR;
	}
	else c = 0;
	return c;
}

void UART_TX(unsigned short uart, char c)
{
	if(uart == 1)
	{
		while((USART1->SR & 0x80) == 0x00) //waiting until data is transferred to shift register for further transmission to data register
		{}
		USART1->DR = c;
	}
	else if(uart == 2)
	{
		while((USART2->SR & 0x80) == 0x00) //waiting until data is transferred to shift register for further transmission to data register
		{}
		USART2->DR = c;
	}
	else if(uart == 3)
	{
		while((USART3->SR & 0x80) == 0x00) //waiting until data is transferred to shift register for further transmission to data register
		{}
		USART3->DR = c;
	}
}

/* 
Define my uart
IS it bridge or process or both
if process : String to fulfill, cnt , signal
*/

void UART_ISR(unsigned short uart, unsigned short bridge, unsigned short * signal, unsigned short * counter, char str[])
{
	if(bridge == 0)
	{
		str[*counter] = UART_RX(uart);
		if(str[*counter] == '\n')
		{
			*counter = 0;
			*signal = 1;
		}
		else
		{
			*counter = *counter + 1;
		}
	}
	else
	{
		UART_TX(bridge,UART_RX(uart));
	}
}

void UART_SEND(unsigned short uart, char str[])
{
	int i =0;
	while(str[i] != '\0')
	{
		UART_TX(uart,str[i]);
		i++;
		DelayMs(1);
	}
}

void  str_empty(char str[])
{
	int i = 0;
	while(str[i] != '\0')
	{
		str[i] = '\0';
		i++;
	}
}
