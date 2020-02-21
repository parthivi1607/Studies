#include<LPC17xx.h>
unsigned int i,j;
int c=0;
unsigned long LED=0x00000010;
int main(void)
{
	LPC_PINCON->PINSEL0 &= 0xff0000ff;
	LPC_GPIO0->FIODIR |= 0x00000ff0;
	LPC_GPIO2->FIODIR = 0;
	
	while(1)
	{
		if(LPC_GPIO2->FIOPIN & 1<<12)
			c++;
		else c--;
		if(c==-1) c = 0xFF;
		if(c==0x100) c=0;
		LPC_GPIO0->FIOPIN = c<<4;
		for(j=0; j<50000; j++);
	}
}
