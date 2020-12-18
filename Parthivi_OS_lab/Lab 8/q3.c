#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

void *prime(void **brr)
{
	int *arr = (int *)brr;
	printf("Prime numbers: ");
	for(int i=arr[0]; i<=arr[1]; i++)
	{
		int flag = 0;
		for(int j=2;j<=i/2;j++)
		{
			if((i%j)==0)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0) printf("%d ",i);
	}
}

int main()
{
	int arr[2];
	pthread_t thread;
	printf("Enter the limits: ");
	scanf("%d %d", &arr[0], &arr[1]);
	pthread_create(&thread, 0, &prime, (void **)arr);
	pthread_join(thread, NULL);
}