#include<LPC17xx.h>
unsigned int i,c;
int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0 &= 0xff0000ff;
	LPC_GPIO0->FIODIR |= 0x00000ff0;
	LPC_GPIO2->FIODIR = 0;
	c = 1;
	while(1)
	{
		if(c==0x100) c=1;
		LPC_GPIO0->FIOPIN = c<<4;
		for(i=0; i<50000; i++);
		if(!(LPC_GPIO2->FIOPIN & 1<<12)) c*=2;
	}
}
