#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("Enter length of array : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter values for array :\n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);

	printf("Sorted array :\n");
	int opcount=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			opcount++;
			if(arr[j]>arr[j+1])
			{
				int t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
				//opcount++;
			}
		}
	}
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\nOperation count = %d\n",opcount);
	return 0;
}