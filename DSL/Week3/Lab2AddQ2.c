#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x,y;
}COMPLEX;

void read(COMPLEX *num)
{
	printf("Enter real part : ");
	scanf("%d",&num->x);
	printf("Enter imaginary part : ");
	scanf("%d",&num->y);
}

COMPLEX* addition(COMPLEX *num1, COMPLEX *num2)
{
	COMPLEX *add;
	add = (COMPLEX*)malloc(sizeof(COMPLEX));
	add->x = num1->x + num2->x;
	add->y = num1->y + num2->y;
	return add;
}

COMPLEX* subtract(COMPLEX *num1, COMPLEX *num2)
{
	COMPLEX *sub;
	sub = (COMPLEX*)malloc(sizeof(COMPLEX));
	sub->x = (num1->x - num2->x);
	sub->y = (num1->y - num2->y);
	return sub;
}

COMPLEX* multiply(COMPLEX *num1, COMPLEX *num2)
{
	COMPLEX *mul;
	mul = (COMPLEX*)malloc(sizeof(COMPLEX));
	mul->x = (num1->x * num2->x) - (num1->y * num2->y);
	mul->y = (num1->x * num2->y) + (num1->y * num2->x);
	return mul;
}

void main()
{
	/*
	if(!(ptr = calloc(num,sizeof(int))))
	{
		exit(0);
	}
	*/
	COMPLEX *no1;
	no1 = (COMPLEX*)malloc(sizeof(COMPLEX));
	printf("Enter no. 1 :\n");
	read(no1);
	COMPLEX *no2;
	no2 = (COMPLEX*)malloc(sizeof(COMPLEX));
	printf("Enter no. 2 :\n");
	read(no2);
	printf("Complex no. 1 : %d + i%d\n",no1->x,no1->y);
	printf("Complex no. 2 : %d + i%d\n",no2->x,no2->y);

	COMPLEX *add;
	add = addition(no1,no2);
	printf("Sum : %d + i%d\n",add->x,add->y);

	//COMPLEX *sub;
	add = subtract(no1,no2);
	printf("Difference : %d + i%d\n",add->x,add->y);

	//COMPLEX *mul;
	add = multiply(no1,no2);
	printf("Product : %d + i%d\n",add->x,add->y);
}