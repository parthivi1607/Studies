#include<LPC17xx.h>
unsigned int i,j,c;
int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0 &= 0xff0000ff;
	LPC_GPIO0->FIODIR |= 0x00000ff0;
	c = 1;
	while(1)
	{
		LPC_GPIO0->FIOPIN = c<<4;
		for(i=0; i<10000; i++);
		if(c==0x100)
			c = 1;
		else
			c<<=1;
	}
}
