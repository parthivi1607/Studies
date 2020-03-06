#include <LPC17xx.h>
#include <stdlib.h>
#include <time.h>
#define RS_CTRL 0x08000000
#define EN_CTRL 0x10000000
#define DT_CTRL 0x07800000
void lcd_init(void);
void wr_cn(void);
void delay_lcd(unsigned int);
void lcd_com(void);
void wr_dn(void);
void lcd_data(void);
void clear_ports(void);
void lcd_puts(unsigned char*);
unsigned char msg3[7] = {'0','1','2','3','4','5','6'};
unsigned int choice;
unsigned long int temp1=0,temp2=0;
unsigned int i;

int main(void){
	lcd_init();
	temp1=0x80;
	lcd_com();
	delay_lcd(800);
	lcd_puts(&msg3[0]);
	//temp1=0xC0;
	//lcd_com();
	//delay_lcd(800);
	//lcd_puts(&msg4[0]);
}
void lcd_init(){
	LPC_GPIO0->FIODIR |= DT_CTRL;
	LPC_GPIO0->FIODIR |= EN_CTRL;
	LPC_GPIO0->FIODIR |= RS_CTRL;
	clear_ports();
	delay_lcd(3200);
	temp1=0x33;
	lcd_com();
	delay_lcd(800);
	temp1=0x32;
	lcd_com();
	delay_lcd(800);
	temp1=0x28;
	lcd_com();
	delay_lcd(800);
	temp1=0x0C;
	lcd_com();
	delay_lcd(800);
	temp1=0x06;
	lcd_com();
	delay_lcd(800);
	temp1=0x01;
	lcd_com();
	delay_lcd(10000);
}
void clear_ports(void){
	LPC_GPIO0->FIOCLR |= DT_CTRL;
	LPC_GPIO0->FIOCLR |= EN_CTRL;
	LPC_GPIO0->FIOCLR |= RS_CTRL;	
}
void delay_lcd(unsigned int r){
	unsigned r1=0;
	for(r1=0;r1<=r;r1++);
}
void lcd_com(){
	temp2=temp1&0xF0;
	temp2=temp2<<19;
	wr_cn();
	delay_lcd(30000);
	temp2=temp1&0x0F;
	temp2=temp2<<23;
	wr_cn();
	delay_lcd(30000);
}
void wr_cn(){
	clear_ports();
	LPC_GPIO0->FIOPIN=temp2;
	LPC_GPIO0->FIOCLR=RS_CTRL;
	LPC_GPIO0->FIOSET=EN_CTRL;
	delay_lcd(25);
	LPC_GPIO0->FIOCLR=EN_CTRL;
}
void lcd_puts(unsigned char* buf1){
	srand(time(0));
	choice = rand()%7;
	i = 0;
	while(buf1[i]!='\0'){
			temp1=buf1[choice];
			lcd_data();
			delay_lcd(800);
			i++;
			if(i==16){
				temp1=0xC0;
				lcd_com();
				delay_lcd(800);
			}
	}
	return;
}
void lcd_data(){
	temp2=temp1 & 0xF0;
	temp2=temp2<<19;
	wr_dn();
	delay_lcd(30000);
	temp2=temp1&0x0F;
	temp2=temp2<<23;
	wr_dn();
	delay_lcd(30000);
}
void wr_dn(){
	clear_ports();
	LPC_GPIO0->FIOPIN=temp2;
	LPC_GPIO0->FIOSET=RS_CTRL;
	LPC_GPIO0->FIOSET=EN_CTRL;
	delay_lcd(25);
	LPC_GPIO0->FIOCLR=EN_CTRL;
}
