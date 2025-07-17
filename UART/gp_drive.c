#include "gp_drive.h"
#include <stdint.h>
void init_GP(unsigned short port, unsigned short pin, unsigned short dir, unsigned short opt)
{
	volatile unsigned long *CR = 0;
	unsigned short TPIN = pin;
	unsigned short offset = 0x00;
	
	if (pin > 7)
	{
		TPIN -= 8;
		offset = 0x04;
	}
	
	if(port == 1)
	{
		RCC_APB2ENR |= 0x4;
		CR = (volatile unsigned long *) ((uintptr_t)&GPIO_A + offset);
	}
	if(port == 2)
	{
		RCC_APB2ENR |= 0x8;
		CR = (volatile unsigned long *) ((uintptr_t)&GPIO_B + offset);
	}
	if(port == 3)
	{
		RCC_APB2ENR |= 0x10;
		CR = (volatile unsigned long *) ((uintptr_t)&GPIO_C + offset);
	}
	*CR &= ~(0xfUL <<(unsigned long)(TPIN)*4 ); // Reset the target pin
	*CR |= (((unsigned long)dir << (TPIN*4)) | ((unsigned long)opt << (TPIN*4 + 2))); // Set the target pin for port and pin number
}

int R_GP (unsigned short port, unsigned short pin)
{
	volatile unsigned long *IDR = 0;
	unsigned short offset = 0x08;
	unsigned short state;
	
	if(port == 1)
		IDR = (volatile unsigned long *) ((uintptr_t)&GPIO_A + offset);
	else if (port == 2)
		IDR = (volatile unsigned long *) ((uintptr_t)&GPIO_B + offset);
	else if (port == 3)
		IDR = (volatile unsigned long *) ((uintptr_t)&GPIO_C + offset);
	state = (unsigned short)((*IDR & ((unsigned long)1<<pin)) >> pin);
	return state;
}

void W_GP (unsigned short port, unsigned short pin, unsigned short state)
{
	volatile unsigned long *ODR = 0;
	unsigned short offset = 0x0C;
	
	if(port == 1)
		ODR = (volatile unsigned long *) ((uintptr_t)&GPIO_A + offset);
	else if (port == 2)
		ODR = (volatile unsigned long *) ((uintptr_t)&GPIO_B + offset);
	else if (port == 3)
		ODR = (volatile unsigned long *) ((uintptr_t)&GPIO_C + offset);
	state ? (*ODR |= ((unsigned long)state<<pin)) : (*ODR &= ~((unsigned long)1<<pin));
}

void toggle_GP(unsigned short port, unsigned short pin)
{
	if(R_GP(port,pin))
	{	
		W_GP(port,pin,0);
	}
	else
	{
		W_GP(port,pin,1);
	}
}
