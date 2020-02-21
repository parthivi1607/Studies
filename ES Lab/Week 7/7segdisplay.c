#include<LPC17xx.h>
unsigned int seven_seg[] = {0x3f, 0x06, 0x5B, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
unsigned int dig_val[]={4,3,2,1};
unsigned int dig_count=0;
unsigned int dig_select[]={0<<23,1<<23,2<<23,3<<23};

void delay()
{
	int i=0;
	for(i=0;i<50000;i++);
}

void display()
{
	LPC_GPIO1->FIOPIN = dig_select[dig_count];
	LPC_GPIO0->FIOPIN = seven_seg[dig_val[dig_count]]<<4;
}

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_GPIO0->FIODIR |= 0x00000ff0;
	LPC_GPIO1->FIODIR = 0xf<<23;
	while(1)
	{
		delay();
		display();
		dig_count+=1;
		if(dig_count==4) dig_count=0;
	}
}
