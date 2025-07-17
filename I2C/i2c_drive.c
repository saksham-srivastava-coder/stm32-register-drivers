#include "i2c_drive.h"



// i2c_init()
void i2c_init(char i2c, unsigned short speed_mode)
{
	RCC->APB2ENR |= 1;     // AFIO enable
	
	if(i2c == 1)
	{
		RCC->APB1ENR |= 0x200000; 
		// Pin Enable
		init_GP(PB,6,OUT50,O_AF_OD);
		init_GP(PB,7,OUT50,O_AF_OD);
		// Reset state
		I2C1->CR1 |= 0x8000;
		I2C1->CR1 &= ~0x8000;
		// Peripheral Frequency selection as APB1 36MHz
		I2C1->CR2 |= 0x24;
		// FM or SM selection
		I2C1->CCR = speed_mode;
		I2C1->TRISE = 0x9;
		I2C1->CR1 |= 1;
	}
	else if(i2c == 2)
	{
		RCC->APB1ENR |= 0x400000; 
		// Pin Enable
		init_GP(PB,10,OUT50,O_AF_OD);
		init_GP(PB,11,OUT50,O_AF_OD);
		// Reset state
		I2C2->CR1 |= 0x8000;
		I2C2->CR1 &= ~0x8000;
		// Peripheral Frequency selection as APB1 36MHz
		I2C2->CR2 |= 0x24;
		// FM or SM selection
		I2C2->CCR = speed_mode;
		I2C2->TRISE = 0x9;
		I2C2->CR1 |= 1;
	}
}


// Start Step
void i2c_start(char i2c)
{
	if(i2c == 1)
	{
		I2C1->CR1 |= 0x100;
		while (!(I2C1->SR1 & 1))   // wait until start bit becomes 1
		{}
	}
	else if(i2c == 2)
	{
		I2C2->CR1 |= 0x100;
		while (!(I2C2->SR1 & 1))
		{}
	}
}

// Sending the address + Read or Write
void i2c_add(char i2c, char address, char RW)
{
	if(i2c == 1)
	{
		volatile int tmp; // for reading status registers
		I2C1->DR = (address | RW);
		while((I2C1->SR1 & 2) == 0) // waiting until ADDR = 1
		{}
		while(I2C1->SR1 & 2)        // Clearing ADDR after getting acknowledgement
		{
			tmp = I2C1->SR1;
			tmp = I2C1->SR2;
			if((I2C1->SR1 & 2) == 0)
			{
				break;
			}
		}
	}
	else 	if(i2c == 2)
	{
		volatile int tmp; // for reading status registers
		I2C2->DR = (address | RW);   // LSB of add will denote R/W
		while((I2C2->SR1 & 2) == 0) // waiting until ADDR = 1
		{}
		while(I2C2->SR1 & 2)        // Clearing ADDR after getting acknowledgement
		{
			tmp = I2C2->SR1;
			tmp = I2C2->SR2;
			if((I2C2->SR1 & 2) == 0)
			{
				break;
			}
		}
	}
}

// Sending data
void i2c_data(char i2c, char data)
{
	if(i2c == 1)
	{
		while((I2C1->SR1 & 0x80) == 0) {}
			I2C1->DR = data;
		while((I2C1->SR1 & 0x80) == 0) {}	
	}
	else 	if(i2c == 2)
	{
		while((I2C2->SR1 & 0x80) == 0) {}
			I2C2->DR = data;
		while((I2C2->SR1 & 0x80) == 0) {}	
	}
}

// Stop i2c
void i2c_stop(char i2c)
{
	volatile int tmp;
	if(i2c == 1)
	{
		tmp = I2C1->SR1;   // Reading status registers for stopping
		tmp = I2C1->SR2;
		I2C1->CR1 |= 0x200;  // Stop bit enabled
	}
	else if(i2c == 2)
	{
		tmp = I2C2->SR1;
		tmp = I2C2->SR2;
		I2C2->CR1 |= 0x200;
	}
}
//i2c_write function
void i2c_write(char i2c, char address, char data[])
{
	int i = 0;
	
	i2c_start(i2c);
	
	i2c_add(i2c, address,0);
	
	while(data[i])
	{
		i2c_data(i2c, data[i]);
		i++;
	}
	i2c_stop(i2c);
}
