#include "stm32f10x.h"                  // Device header
#include "gp_drive.h"
#include <stdint.h>


void Delays(int time);
static int signal = 0;
void EXTI0_IRQHandler(void);
void systick_init(void);
void DelayMillis(void);
void DelayMs(unsigned long t);

int main (void)
{
/*	RCC_APB2ENR |= 1<<2 | 1<<4 ; // Enabling port A clock and port c clock
	GPIOA->CRL &= 0xFFFFFFF0; 		//Clearing the first 4 bits for PA0
	GPIOA->CRL |= 0x00000008; 		// Setting the first 4 bits for PA0 input pull up pull down
	GPIOC->CRH &= 0xFF0FFFFF; 		//Clearing the bits for PC13
	GPIOC->CRH |= 0x00300000;			// Setting PC13 as output push pull 50MHz
*/
	systick_init();
	init_GP(PA,0,IN,IN_PP);
	init_GP(PC,13,OUT50,O_GP_PP);
	init_GP(PA,12,OUT50,O_GP_PP);
	
	__disable_irq();
	AFIO->EXTICR[0] = 0x00;
	EXTI->IMR |= 1;
	EXTI->RTSR |= 1;
	NVIC_EnableIRQ(EXTI0_IRQn);
	__enable_irq();
	
	
while(1)
{
	W_GP(PA,12,(uint16_t)signal);
	if(signal)
		{
			DelayMs(1000);
			toggle_GP(PC,13);
			DelayMs(1000);
		}
	else
	{
			W_GP(PC,13,1);
	}
}
}

void Delays(int time)
{
	int t;
	for(;time>0;time--)
	{
		for(t=0;t<100000;t++);
	}
}

void EXTI0_IRQHandler(void)
{
	EXTI->PR |= 1;
	if(signal)
		signal = 0;
	else
		signal = 1;
}

 void systick_init(void)
{
	SysTick->CTRL = 0;
	SysTick->LOAD = 0x00FFFFFF;
	SysTick->VAL = 0;
	SysTick->CTRL = 5; 			// 0101 will cause clock same of 8MHz and enable the systick timer
}

void DelayMillis(void)
{
	SysTick->LOAD = 72000-1;
	SysTick->VAL = 0;
	while((SysTick->CTRL & 0x00010000) == 0);
}

void DelayMs(unsigned long t)
{
	for(;t>0;t--)
	{
		DelayMillis();
	}
}
