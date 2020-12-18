#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

void *even(void **brr)
{

	int *arr = (int *)brr;
	int n = arr[0];
	int sum = 0;
	for(int i=1;i<= arr[0];i++)
	{
		if(arr[i]%2 == 0)
			sum+=arr[i];	
	}
	return (void *)sum;
}

void *odd(void **brr)
{
	int *arr = (int *)brr;
	int sum = 0;
	for(int i=1;i<= arr[0];i++)
	{
		if(arr[i]%2 != 0)
			sum+=arr[i];	
	}
	return (void *)sum;
}

int main()
{
	int n, e, o;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: \n");
	int arr[n+1];
	arr[0] = n;
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);

	pthread_t t1, t2;
	pthread_create(&t1, 0, &even, (void **)arr);
	pthread_create(&t2, 0, &odd, (void **)arr);

	pthread_join(t1, (void **)&e);
	pthread_join(t2, (void **)&o);
	printf("Sum of even numbers = %d\n", (int)e);
	printf("Sum of odd numbers = %d\n", (int)o);
}