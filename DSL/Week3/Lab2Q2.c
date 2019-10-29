#include <stdio.h>
#include <stdlib.h>

int* partAandB(int *p1, int s)
{
	int *p;
	p = p1+s-1;
	return p;
}

void main()
{
	//passing and returning a pointer
	int num,i,search;
	printf("Enter no. of elements : ");
	scanf("%d",&num);
	int arr[100];
	printf("Enter elements of array : \n");
	for(i=0;i<num;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter position of element that has to be sent back : ");
	scanf("%d",&search);
	int *p;
	p = partAandB(arr, search);
	printf("Element at position %d = %d\n",search,*p);

	//pointer to pointer
	int **pp;
	p=&num; pp=&p;
	printf("Enter a number : ");
	scanf("%d",*pp);
	int sum=0;
	for(;num!=0; num=num/10)
	{
		sum = sum + (num%10);
	}
	p=&sum; pp=&p;
	printf("Sum of digits of no. : %d\n",**pp);
}