#include "stm32f10x.h"                  // Device header
#include "gp_drive.h"
#include "systic_drive.h"
#include "uart_drive.h"

static char chat = 'A';

static char msg[250] = "Welcome to my PC";

static char USART_1_msg[250];
static unsigned short USART_1_cnt = 0;
static unsigned short USART_1_sig = 0;
static unsigned short USART_1_bdg = 0;

static char USART_2_msg[250];
static unsigned short USART_2_cnt = 0;
static unsigned short USART_2_sig = 0;
static unsigned short USART_2_bdg = 0;

static char USART_3_msg[250];
static unsigned short USART_3_cnt = 0;
static unsigned short USART_3_sig = 0;
static unsigned short USART_3_bdg = 0;

void USART2_IRQHandler(void);
void USART3_IRQHandler(void);

int main(void)
{
	// Delays Function
	systick_init();
	UART_init(2,9600);
	UART_init(3,9600);
	DelayMs(100);
	UART_SEND(2,msg);
	UART_SEND(3,msg);
	
	while(1)
	{
	/*	// Receive char
		chat = UART_RX(2);
		// Transmit Char
		UART_TX(2,chat); */
		if(USART_2_sig == 1)            // for sending for different baud rates
		{
			UART_SEND(3,USART_2_msg);
			USART_2_sig = 0;
			str_empty(USART_2_msg);
		}
		if(USART_3_sig == 1)
		{
			UART_SEND(2,USART_3_msg);
			USART_3_sig = 0;
			str_empty(USART_3_msg);
		}
	}
}
/*  For same baud rates we can directly use the bridge otherwise we have to process in case of different baud rates in order to send 
data between two uarts */

void USART2_IRQHandler(void)  // Send message from 2 to 3 when same baud rates happen
{
	UART_ISR(2,0,&USART_2_sig,&USART_2_cnt,USART_2_msg);
}

void USART3_IRQHandler(void)  // Send message from 3 to 2 when same baud rates happen
{
	UART_ISR(3,0,&USART_3_sig,&USART_3_cnt,USART_3_msg);
}
