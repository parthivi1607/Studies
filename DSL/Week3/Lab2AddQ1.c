#include <stdio.h>
#include <stdlib.h>

void main()
{
	int num;
	printf("Enter no. of elements : ");
	scanf("%d", &num);
	int *ptr;
	/*
	if(!(ptr = calloc(num,sizeof(int))))
	{
		exit(0);
	}
	*/
	ptr = (int*)calloc(num,sizeof(int));
	printf("Enter elements of array :\n");
	int *p;
	int *pLast;
	pLast = ptr + num -1;
	for(p=ptr;p<=pLast;p++)
	{
		scanf("%d", p);
	}
	
	printf("Printing in forward direction : ");
	for(p=ptr;p<=pLast;p++)
		printf("%d ",*p);
	printf("\nPrinting in backward direction : ");
	for(p=pLast;p>=ptr;p--)
		printf("%d ",*p);
	printf("\n");
}