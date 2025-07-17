#include "systic_drive.h"
#include "stm32f10x.h"

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
