#include<LPC17xx.h>
unsigned int i,j,c;
int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0 &= 0xff0000ff;
	LPC_GPIO0->FIODIR |= 0x00000ff0;
	c = 0;
	while(1)
	{
		c++;
		LPC_GPIO0->FIOPIN = c<<4;
		for(i=0; i<30000; i++);
		if(c==0xff)
			c = 0;
	}
}
