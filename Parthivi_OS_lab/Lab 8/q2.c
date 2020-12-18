#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

void *thread_code(void *n)
{
	int sum = 0;
	for(int i=1;i<= (int)n;i++) sum += i;
	return (void *)sum;
}

int main()
{
	pthread_t thread;
	printf("Enter the number of elements: ");
	int n,ans;
	scanf("%d",&n);
	pthread_create(&thread, 0, &thread_code, (void *)n);
	printf("Thread created successfully\n");
	pthread_join(thread,(void **)&ans);
	printf("Summation of non-negetive integers from 1 to %d = %d\n", n, (int)ans);
}