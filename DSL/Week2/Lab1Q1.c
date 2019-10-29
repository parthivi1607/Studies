#include <stdio.h>
#include <stdlib.h>

double sumOfArray(double *p, int n)
{
	double sum;
	double *pLast;
	pLast = p + n - 1;
	for(; p<=pLast; p++)
	{
	  sum=sum+*p;
	}
	return sum;
}

void main()
{
	int num;
	printf("Enter no. of elements : ");
	scanf("%d", &num);
	double *ptr;
	/*
	if(!(ptr = calloc(num,sizeof(int))))
	{
		exit(0);
	}
	*/
	ptr = calloc(num,sizeof(double));
	printf("Enter elements of array :\n");
	double *p;
	double *pLast;
	pLast = ptr + num -1;
	for(p=ptr;p<=pLast;p++)
	{
		scanf("%lf", p);
	}
	double s = sumOfArray(ptr,num);
	printf("Sum = %lf \n", s);
}