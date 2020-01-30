#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, sum=0;
	printf("Enter no. of elements in array : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements of array :\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	sum=sum/2;
	int flag=0;
	return 0;
}