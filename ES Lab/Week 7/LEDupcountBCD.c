#include <LPC17xx.h>
#include <stdio.h>

#define FIRST_SEG 	0XF87FFFFF //0<<23
#define SECOND_SEG  0XF8FFFFFF //1<<23
#define THIRD_SEG   0XF97FFFFF //2<<23
#define FOURTH_SEG  0XF9FFFFFF //3<<23

unsigned int dig1=0x00,dig2=0x00,dig3=0x00,dig4=0x00;
unsigned int digcount=0x00,temp1=0x00,onesecflag=0x00;
unsigned int arraydec[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned long int temp2=0x00000000,i=0;

void delay(void);
void display(void);

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	
	LPC_PINCON->PINSEL0 &=0xFF0000FF;
	LPC_PINCON->PINSEL3 &=0xFFC03FFF;
	LPC_GPIO0->FIODIR |=0x00000FF0;
	LPC_GPIO1->FIODIR |=15<<23;
	while(1)
	{
		delay();
		digcount+=1;
		if(digcount==0x05)
		{
			digcount=0x00;
			onesecflag=0xFF;
		}
		if(onesecflag==0xFF)
		{
			onesecflag=0x00;
			dig1+=1;
			if(dig1==0x0A)
			{
				dig1=0;
				dig2+=1;
				if(dig2==0x0A)
				{
					dig2=0;
					dig3+=1;
					if(dig3==0x0A)
					{
						dig3=0;
						dig4+=1;
						if(dig4==0x0A)
						{
							dig4=0;
						}
					}
				}
			}
		}
		display();
	}
}
void display(void)
{
	if(digcount==0x01)
	{
		temp1=dig1;
		LPC_GPIO1->FIOPIN=FIRST_SEG;
	}
	else if(digcount==0x02)
	{
		temp1=dig2;
		LPC_GPIO1->FIOPIN=SECOND_SEG;
	}
	else if(digcount==0x03)
	{
		temp1=dig3;
		LPC_GPIO1->FIOPIN=THIRD_SEG;
	}
	else if(digcount==0x04)
	{
		temp1=dig4;
		LPC_GPIO1->FIOPIN=FOURTH_SEG;
	}
	temp1&=0x0F;
	temp2=arraydec[temp1];
	temp2=temp2<<4;
	LPC_GPIO0->FIOPIN=temp2;
	for(i=0;i<500;i++);
	LPC_GPIO0->FIOCLR = 0x00000FF0;
}
void delay(void)
{
	unsigned int i;
	for(i=0;i<10000;i++);
}

