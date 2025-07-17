#include "stm32f10x.h"                  // Device header
#include "gp_drive.h"
#include "systic_drive.h"
#include "i2c_drive.h"

static char data[2] = {0x01,0x02};

int main(void)
{
	systick_init();
	i2c_init(2,i2c_FM);
	i2c_init(1,i2c_SM);
	
	while(1)
	{
		i2c_write(2,0x78,data);
		DelayMs(10);
	}
}
